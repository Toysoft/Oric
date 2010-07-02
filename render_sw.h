/*
**  Oricutron
**  Copyright (C) 2009-2010 Peter Gordon
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
**  Software rendering
*/

void render_begin_sw( struct machine *oric );
void render_end_sw( struct machine *oric );
void render_textzone_alloc_sw( struct machine *oric, int i );
void render_textzone_free_sw( struct machine *oric, int i );
void render_textzone_sw( struct machine *oric, struct textzone *ptz );
void render_video_sw( struct machine *oric, SDL_bool doublesize );
void preinit_render_sw( struct machine *oric );
SDL_bool init_render_sw( struct machine *oric );
void shut_render_sw( struct machine *oric );