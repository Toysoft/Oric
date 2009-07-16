/*
**  Oriculator
**  Copyright (C) 2009 Peter Gordon
**
**  This program is free software; you can redistribute it and/or
**  modify it under the terms of the GNU General Public License
**  as published by the Free Software Foundation, version 2
**  of the License.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
**  WD17xx, Microdisc and Jasmin emulation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <SDL/SDL.h>

#include "6502.h"
#include "via.h"
#include "8912.h"
#include "gui.h"
#include "disk.h"
#include "machine.h"
#include "monitor.h"

extern char diskfile[], diskpath[];

// Track size, ID mark, Data mark, Deleted data mark
static struct densityinfo dinf[] = { { 0, },          // ?
                                     { 0, },          // High density
                                     { 0x1900, 0xfe, 0xfb, 0xf8 } };

// Pop up disk image information for a couple of seconds
void disk_popup( struct machine *oric, int drive )
{
  char tmp[40];
  if( !oric->diskname[drive][0] )
  {
    do_popup( "\x14\x15\x13" );
    return;
  }

  sprintf( tmp, "\x14\x15""%d %-16s", drive, oric->diskname[drive] );
  do_popup( tmp );
}

// Free a disk image and clear the pointer to it
void diskimage_free( struct diskimage **dimg )
{
  if( !(*dimg) ) return;
  if( (*dimg)->rawimage ) free( (*dimg)->rawimage );
  free( *dimg );
  (*dimg) = NULL;
}

// Read a raw integer from a disk image file
Uint32 diskimage_rawint( struct diskimage *dimg, Uint32 offset )
{
  if( !dimg ) return 0;
  if( ( !dimg->rawimage ) || ( dimg->rawimagelen < 4 ) ) return 0;
  if( offset > (dimg->rawimagelen-4) ) return 0;

  return (dimg->rawimage[offset+3]<<24)|(dimg->rawimage[offset+2]<<16)|(dimg->rawimage[offset+1]<<8)|dimg->rawimage[offset];
}

// Allocate and initialise a disk image structure
// If "rawimglen" isn't zero, it will also allocate
// ram for a raw disk image
struct diskimage *diskimage_alloc( Uint32 rawimglen )
{
  struct diskimage *dimg;
  Uint8 *buf=NULL;

  if( rawimglen )
  {
    buf = malloc( rawimglen );
    if( !buf ) return NULL;
  }

  dimg = malloc( sizeof( struct diskimage ) );
  if( !dimg ) return NULL;

  dimg->numtracks   = 0;
  dimg->numsides    = 0;
  dimg->density     = 0;
  dimg->cachedtrack = -1;
  dimg->cachedside  = -1;
  dimg->numsectors  = 0;
  dimg->rawimage    = buf;
  dimg->rawimagelen = rawimglen;
  dimg->dinf        = NULL;
  return dimg;
}

// Eject a disk from a drive
void disk_eject( struct machine *oric, int drive )
{
  diskimage_free( &oric->wddisk.disk[drive] );
  oric->diskname[drive][0] = 0;
  disk_popup( oric, drive );
}

// Cache a track
void diskimage_cachetrack( struct diskimage *dimg, int track, int side )
{
  Uint8 *ptr, *eot;
  Uint32 sectorcount, n;

  if( ( dimg->cachedtrack == track ) &&
      ( dimg->cachedside == side ) )
    return;

  ptr = &dimg->rawimage[HEADERSIZE+(dimg->dinf->tracksize*((track*dimg->numsides)+side))];
  eot = &ptr[dimg->dinf->tracksize];

  sectorcount = 0;
  while( ptr < eot )
  {
    // Search for ID mark
    while( (ptr<eot) && (ptr[0]!=dimg->dinf->idmark) ) ptr++;
    if( ptr >= eot ) break;
    
    // Store pointer
    dimg->sector[sectorcount].id_ptr = ptr;
    dimg->sector[sectorcount].data_ptr = NULL;
    sectorcount++;

    // Get N value
    n = ptr[4];

    // Skip ID field and CRC
    ptr+=7;

    // Search for data ID
    while( (ptr<eot) && (ptr[0]!=dimg->dinf->datamark) && (ptr[0]!=dimg->dinf->deldatamark) ) ptr++;
    if( ptr >= eot ) break;

    // Store pointer
    dimg->sector[sectorcount-1].data_ptr = ptr;

    // Skip data field and ID
    ptr += (1<<(n+7))+3;
  }

  dimg->numsectors = sectorcount;

  {
    char tmp[128];
    sprintf( tmp, "Track %d, Side %d, Sectors %d", track, side, dimg->numsectors );
    do_popup( tmp );
  }
}

SDL_bool diskimage_load( struct machine *oric, char *fname, int drive )
{
  FILE *f;
  Uint32 len;

  f = fopen( fname, "rb" );
  if( !f ) return SDL_FALSE;

  disk_eject( oric, drive );

  fseek( f, 0, SEEK_END );
  len = ftell( f );
  fseek( f, 0, SEEK_SET );

  if( len <= 0 )
  {
    fclose( f );
    return SDL_FALSE;
  }

  oric->wddisk.disk[drive] = diskimage_alloc( len );
  if( !oric->wddisk.disk[drive] )
  {
    SDL_WM_SetCaption( "Fail 1", "Fail 1" );
    fclose( f );
    return SDL_FALSE;
  }

  if( fread( oric->wddisk.disk[drive]->rawimage, len, 1, f ) != 1 )
  {
    SDL_WM_SetCaption( "Fail 2", "Fail 2" );
    fclose( f );
    disk_eject( oric, drive );
    return SDL_FALSE;
  }

  fclose( f );

  if( strncmp( oric->wddisk.disk[drive]->rawimage, "MFM_DISK", 8 ) != 0 )
  {
    SDL_WM_SetCaption( "Fail 3", "Fail 3" );
    disk_eject( oric, drive );
    return SDL_FALSE;
  }

  oric->wddisk.disk[drive]->numtracks = diskimage_rawint( oric->wddisk.disk[drive], 12 );
  oric->wddisk.disk[drive]->numsides  = diskimage_rawint( oric->wddisk.disk[drive], 16 );
  oric->wddisk.disk[drive]->density   = diskimage_rawint( oric->wddisk.disk[drive], 8 );

  if( oric->wddisk.disk[drive]->density != DOUBLE_DENSITY )
  {
    SDL_WM_SetCaption( "Fail 4", "Fail 4" );
    disk_eject( oric, drive );
    return SDL_FALSE;
  }

  oric->wddisk.disk[drive]->dinf      = &dinf[oric->wddisk.disk[drive]->density];

  {
    char deleteme[128];
    sprintf( deleteme, "Tracks: %u, Sides: %u, Density: %u",
      oric->wddisk.disk[drive]->numtracks,
      oric->wddisk.disk[drive]->numsides,
      oric->wddisk.disk[drive]->density );
    SDL_WM_SetCaption( deleteme, deleteme );
  }

  strncpy( oric->diskname[drive], fname, 16 );
  oric->diskname[drive][15] = 0;
  disk_popup( oric, drive );
  return SDL_TRUE;
};

void wd17xx_dummy( void *nothing )
{
}

void wd17xx_init( struct wd17xx *wd )
{
  wd->cmd      = 0;
  wd->r_status = 0;
  wd->r_track  = 0;
  wd->r_sector = 0;
  wd->r_data   = 0;
  wd->c_drive  = 0;
  wd->c_side   = 0;
  wd->c_track  = 0;
  wd->c_sector = 0;
  wd->last_step_in = SDL_FALSE;
  wd->setintrq = wd17xx_dummy;
  wd->clrintrq = wd17xx_dummy;
  wd->intrqarg = NULL;
  wd->setdrq   = wd17xx_dummy;
  wd->clrdrq   = wd17xx_dummy;
  wd->drqarg   = NULL;
  wd->currentop = COP_NUFFINK;
  wd->delayedint = 0;
  wd->delayeddrq = 0;
}

void wd17xx_ticktock( struct wd17xx *wd, int cycles )
{
  if( wd->delayedint > 0 )
  {
    wd->delayedint -= cycles;
    if( wd->delayedint <= 0 )
    {
      wd->delayedint = 0;
      wd->setintrq( wd->intrqarg );
      dbg_printf( "DISK: Delayed INTRQ" );
    }
  }

  if( wd->delayeddrq > 0 )
  {
    wd->delayeddrq -= cycles;
    if( wd->delayeddrq <= 0 )
    {
      wd->delayeddrq = 0;
      wd->setdrq( wd->drqarg );
      dbg_printf( "DISK: Delayed DRQ" );
    }
  }
}

void wd17xx_seek_track( struct wd17xx *wd, Uint8 track )
{
  if( wd->disk[wd->c_drive] )
  {
    diskimage_cachetrack( wd->disk[wd->c_drive], track, wd->c_side );
    wd->r_status = 0;
    wd->c_track = track;
    wd->c_sector = 0;
    wd->r_track = track;
    if( track == 0 ) wd->r_status |= WSFI_TRK0;
    wd->delayedint = 100;
    dbg_printf( "DISK: At track %u", track );
    return;
  }

  // No disk in drive
  wd->setintrq( wd->intrqarg );
  wd->r_status = WSF_NOTREADY|WSFI_SEEKERR;
  wd->r_track = 0;
  dbg_printf( "DISK: Seek fail" );
}

struct mfmsector *wd17xx_find_sector( struct wd17xx *wd, Uint8 secid )
{
  int revs=0;
  struct diskimage *dimg;

  dimg = wd->disk[wd->c_drive];

  if( !dimg ) return NULL;
  diskimage_cachetrack( dimg, wd->c_track, wd->c_side );

  if( dimg->numsectors < 1 )
    return NULL;

  while( revs < 2 )
  {
    wd->c_sector = (wd->c_sector+1)%dimg->numsectors;
    if( !wd->c_sector ) revs++;

    if( dimg->sector[wd->c_sector].id_ptr[3] == secid )
      return &dimg->sector[wd->c_sector];
  }

  dbg_printf( "Couldn't find sector %02X", secid );
  return NULL;
}

unsigned char wd17xx_read( struct wd17xx *wd, unsigned short addr )
{
  switch( addr )
  {
    case 0: // Status register
      wd->clrintrq( wd->intrqarg );
      return wd->r_status;
    
    case 1: // Track register
      return wd->r_track;
    
    case 2: // Sector register
      return wd->r_sector;
    
    case 3: // Data register
      switch( wd->currentop )
      {
        case COP_READ_SECTOR:
          if( !wd->currsector )
          {
            wd->clrdrq( wd->drqarg );
            wd->currentop = COP_NUFFINK;
            break;
          }
          wd->r_data = wd->currsector->data_ptr[wd->curroffs++];
          wd->clrdrq( wd->drqarg );
//          printf( "%02X", wd->r_data );
          printf( "%c", ((wd->r_data>=32)&&(wd->r_data<128))?wd->r_data:'.' );
          if( wd->curroffs >= wd->currseclen )
          {
            wd->clrdrq( wd->drqarg );
            wd->delayedint = 100;
            wd->currentop = COP_NUFFINK;
            wd->r_status = 0;
            printf( "\n\n" );
          } else {
            wd->delayeddrq = 10;
          }
          break;
      }

      return wd->r_data;
  }

  return 0; // ??
}

static SDL_bool last_step_in = SDL_FALSE;
void wd17xx_write( struct machine *oric, struct wd17xx *wd, unsigned short addr, unsigned char data )
{
  switch( addr )
  {
    case 0: // Command register
      wd->cmd = data;
      switch( data & 0xe0 )
      {
        case 0x00:  // Restore or seek
          switch( data & 0x10 )
          {
            case 0x00:  // Restore (Type I)
              dbg_printf( "DISK: (%04X) Restore", oric->cpu.pc-1 );
              wd17xx_seek_track( wd, 0 );
              wd->currentop = COP_NUFFINK;
              break;
            
            case 0x10:  // Seek (Type I)
              dbg_printf( "DISK: (%04X) Seek", oric->cpu.pc-1 );
              wd17xx_seek_track( wd, wd->r_data );
              wd->currentop = COP_NUFFINK;
              break;
          }
          break;
        
        case 0x20:  // Step (Type I)
          dbg_printf( "DISK: (%04X) Step", oric->cpu.pc-1 );
          if( last_step_in )
            wd17xx_seek_track( wd, wd->c_track+1 );
          else
            wd17xx_seek_track( wd, wd->c_track > 0 ? wd->c_track-1 : 0 );
          wd->currentop = COP_NUFFINK;
          break;
        
        case 0x40:  // Step-in (Type I)
          dbg_printf( "DISK: Step-In" );
          wd17xx_seek_track( wd, wd->c_track+1 );
          last_step_in = SDL_TRUE;
          wd->currentop = COP_NUFFINK;
          break;
        
        case 0x60:  // Step-out (Type I)
          dbg_printf( "DISK: Step-Out" );
          if( wd->c_track > 0 )
            wd17xx_seek_track( wd, wd->c_track-1 );
          last_step_in = SDL_FALSE;
          wd->currentop = COP_NUFFINK;
          break;
        
        case 0x80:  // Read sector (Type II)
          printf( "TRACK: %d, SECTOR: %d\n", wd->r_track, wd->r_sector );
          dbg_printf( "DISK: (%04X) Read sector", oric->cpu.pc-1 );
          wd->curroffs   = 0;
          wd->currsector = wd17xx_find_sector( wd, wd->r_sector );
          if( !wd->currsector )
          {
            wd->r_status = WSF_RNF;
            wd->clrdrq( wd->drqarg );
            wd->currentop = COP_NUFFINK;
            break;
          }

          wd->currseclen = 1<<(wd->currsector->id_ptr[4]+7);
          wd->r_status = WSF_BUSY|WSF_DRQ;
          wd->setdrq( wd->drqarg );
          wd->setintrq( wd->intrqarg );
          wd->currentop = COP_READ_SECTOR;
          break;
        
        case 0xa0:  // Write sector (Type II)
          dbg_printf( "DISK: Write sector" );
          wd->currentop = COP_WRITE_SECTOR;
          break;
        
        case 0xc0:  // Read address / Force IRQ
          switch( data & 0x10 )
          {
            case 0x00: // Read address (Type III)
              dbg_printf( "DISK: (%04X) Read address", oric->cpu.pc-1 );
              break;
            
            case 0x10: // Force IRQ (Type IV)
              dbg_printf( "DISK: (%04X) Force int", oric->cpu.pc-1 );
              wd->setintrq( wd->intrqarg );
              wd->r_status = 0;
              wd->currentop = COP_NUFFINK;
              break;
          }
          break;
        
        case 0xe0:  // Read track / Write track
          switch( data & 0x10 )
          {
            case 0x00: // Read track (Type III)
              dbg_printf( "DISK: (%04X) Read track", oric->cpu.pc-1 );
              wd->currentop = COP_READ_TRACK;
              break;
            
            case 0x10: // Write track (Type III)
              dbg_printf( "DISK: (%04X) Write track", oric->cpu.pc-1 );
              wd->currentop = COP_WRITE_TRACK;
              break;
          }
          break;
      }
      break;
    
    case 1: // Track register
      wd->r_track = data;
      break;
    
    case 2: // Sector register
      wd->r_sector = data;
      break;
    
    case 3: // Data register
      wd->r_data = data;
      break;
  }
}

void microdisc_setdrq( void *md )
{
  struct microdisc *mdp = (struct microdisc *)md;
  mdp->drq = 0;
}

void microdisc_clrdrq( void *md )
{
  struct microdisc *mdp = (struct microdisc *)md;
  mdp->drq = MF_DRQ;
}

void microdisc_setintrq( void *md )
{
  struct microdisc *mdp = (struct microdisc *)md;
  
  mdp->intrq = 0; //MDSF_INTRQ;
  if( mdp->status & MDSF_INTENA )
  {
    mdp->oric->cpu.irq |= IRQF_DISK;
    mdp->oric->cpu.irql = SDL_TRUE;
  }

}

void microdisc_clrintrq( void *md )
{
  struct microdisc *mdp = (struct microdisc *)md;

  mdp->intrq = MDSF_INTRQ;
  mdp->oric->cpu.irq &= ~IRQF_DISK;
}

void microdisc_init( struct microdisc *md, struct wd17xx *wd, struct machine *oric )
{
  wd17xx_init( wd );
  wd->setintrq = microdisc_setintrq;
  wd->clrintrq = microdisc_clrintrq;
  wd->intrqarg = (void*)md;
  wd->setdrq   = microdisc_setdrq;
  wd->clrdrq   = microdisc_clrdrq;
  wd->drqarg   = (void*)md;

  md->status  = 0;
  md->intrq   = 0;
  md->drq     = 0;
  md->wd      = wd;
  md->oric    = oric;
  md->diskrom = SDL_TRUE;
}

void microdisc_free( struct microdisc *md )
{
  int i;
  for( i=0; i<MAX_DRIVES; i++ )
    disk_eject( md->oric, i );
}

unsigned char microdisc_read( struct microdisc *md, unsigned short addr )
{
//  dbg_printf( "DISK: (%04X) Read from %04X", md->oric->cpu.pc-1, addr );
  if( ( addr >= 0x310 ) && ( addr < 0x314 ) )
    return wd17xx_read( md->wd, addr&3 );

  switch( addr )
  {
    case 0x314:
      return md->intrq;

    case 0x318:
      return md->drq;
  }

  return 0;
}

void microdisc_write( struct microdisc *md, unsigned short addr, unsigned char data )
{
//  dbg_printf( "DISK: (%04X) Write %02X to %04X", md->oric->cpu.pc-1, data, addr );
  if( ( addr >= 0x310 ) && ( addr < 0x314 ) )
  {
    wd17xx_write( md->oric, md->wd, addr&3, data );
    return;
  }

  switch( addr )
  {
    case 0x314:
      md->status = data;
      md->wd->c_drive = (data&MDSF_DRIVE)>>5;

      md->oric->romdis = (md->status&MDSF_ROMDIS) ? SDL_FALSE : SDL_TRUE;
      md->diskrom = (md->status&MDSF_EPROM) ? SDL_FALSE : SDL_TRUE;
      break;

    case 0x318:
      md->drq = (data&MF_DRQ);
      break;
  }
}