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
**  A crappy font, wot I made by hand-typing all the hex statements below.
*/

unsigned char thefont[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //   0 nothing!
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x18, //   1 top left 
                            0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, //   2 horizontal
                            0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, //   3 branch down
                            0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x18, 0x18, 0x18, 0x18, 0x18, //   4 top right
                            0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, //   5 vertical
                            0x18, 0x18, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x18, //   6 branch right
                            0x18, 0x18, 0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, //   7 cross
                            0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x18, 0x18, 0x18, 0x18, 0x18, //   8 branch left
                            0x18, 0x18, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, //   9 bottom left 
                            0x18, 0x18, 0x18, 0x18, 0x18, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, //  10 branch up
                            0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, //  11 bottom right
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, //  12 menu seperator
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  13
                            0x00, 0x00, 0x06, 0x06, 0x0c, 0x0c, 0x18, 0xd8, 0xf0, 0x70, 0x60, 0x00, //  14 Tick
                            0x00, 0xff, 0x80, 0x98, 0xa4, 0xa4, 0x98, 0x80, 0x8f, 0x90, 0xff, 0x00, //  15 Tape left
                            0x00, 0xfe, 0x02, 0x32, 0x4a, 0x4a, 0x32, 0x02, 0xe2, 0x12, 0xfe, 0x00, //  16 Tape right
                            0x00, 0x00, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x00, 0x00, //  17 Stop
                            0x00, 0x00, 0x60, 0x70, 0x78, 0x7c, 0x7c, 0x78, 0x70, 0x60, 0x00, 0x00, //  18 Play
                            0x00, 0x00, 0x10, 0x10, 0x38, 0x38, 0x7c, 0x7c, 0x00, 0x7c, 0x00, 0x00, //  19 Eject
                            0x7f, 0x40, 0x40, 0x40, 0x43, 0x44, 0x44, 0x43, 0x40, 0x41, 0x41, 0x7f, //  20 Disk left
                            0xfc, 0x04, 0x04, 0x04, 0x84, 0x44, 0x44, 0x84, 0x04, 0x04, 0x04, 0xfc, //  21 Disk right
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  22
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  23
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  24
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  25
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  26
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  27
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  28
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  29
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  30
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  31
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  32 ' '
                            0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x00, //  33 '!'
                            0xcc, 0xcc, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  34 '"'
                            0x00, 0x6c, 0x6c, 0x6c, 0xfe, 0x6c, 0x6c, 0xfe, 0x6c, 0x6c, 0x6c, 0x00, //  35 '#'
                            0x10, 0x7c, 0xd6, 0xd0, 0xd0, 0x7c, 0x16, 0x16, 0x16, 0xd6, 0x7c, 0x10, //  36 '$'
                            0x00, 0x62, 0x94, 0x94, 0x68, 0x08, 0x10, 0x16, 0x29, 0x29, 0x46, 0x00, //  37 '%'
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  38 TODO: '&'
                            0x18, 0x18, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  39 '''
                            0x06, 0x0c, 0x18, 0x18, 0x30, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x06, 0x00, //  40 '('
                            0xc0, 0x60, 0x30, 0x30, 0x18, 0x18, 0x18, 0x30, 0x30, 0x60, 0xc0, 0x00, //  41 ')'
                            0x10, 0xd6, 0xd6, 0x7c, 0x7c, 0x38, 0x7c, 0x7c, 0xd6, 0xd6, 0x10, 0x00, //  42 '*'
                            0x00, 0x18, 0x18, 0x18, 0x18, 0xfe, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, //  43 '+'
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30, //  44 ','
                            0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  45 '-'
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, //  46 '.'
                            0x06, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0, //  47 '/'
                            0x00, 0x7c, 0xc6, 0xc6, 0xd6, 0xd6, 0xd6, 0xd6, 0xc6, 0xc6, 0x7c, 0x00, //  48 '0'
                            0x00, 0x08, 0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e, 0x00, //  49 '1'
                            0x00, 0x7c, 0xc6, 0x06, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0xfe, 0x00, //  50 '2'
                            0x00, 0x7c, 0xc6, 0x06, 0x06, 0x3c, 0x06, 0x06, 0x06, 0xc6, 0x7c, 0x00, //  51 '3'
                            0x00, 0x0c, 0x1c, 0x3c, 0x6c, 0xcc, 0xcc, 0xfe, 0x0c, 0x0c, 0x0c, 0x00, //  52 '4'
                            0x00, 0xfc, 0xc0, 0xc0, 0xfc, 0x06, 0x06, 0x06, 0x06, 0xc6, 0x7c, 0x00, //  53 '5'
                            0x00, 0x7c, 0xc6, 0xc0, 0xc0, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, //  54 '6'
                            0x00, 0xfe, 0x06, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, //  55 '7'
                            0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, //  56 '8'
                            0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0x7e, 0x06, 0x06, 0x06, 0xc6, 0x7c, 0x00, //  57 '9'
                            0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, //  58 ':'
                            0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x30, 0x00, 0x00, //  59 ';'
                            0x00, 0x00, 0x00, 0x06, 0x0c, 0x18, 0x30, 0x18, 0x0c, 0x06, 0x00, 0x00, //  60 '<'
                            0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, //  61 '='
                            0x00, 0x00, 0x00, 0xc0, 0x60, 0x30, 0x18, 0x30, 0x60, 0xc0, 0x00, 0x00, //  62 '>'
                            0x00, 0x7c, 0xc6, 0x06, 0x06, 0x06, 0x1c, 0x30, 0x00, 0x30, 0x30, 0x00, //  63 '?'
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  64 TODO: '@'
                            0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xfe, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, //  65 'A'
                            0x00, 0xfc, 0xc6, 0xc6, 0xc6, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xfc, 0x00, //  66 'B'
                            0x00, 0x7c, 0xc6, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc6, 0x7c, 0x00, //  67 'C'
                            0x00, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xfc, 0x00, //  68 'D'
                            0x00, 0xfe, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0x00, //  69 'E'
                            0x00, 0xfe, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, //  70 'F'
                            0x00, 0x7c, 0xc6, 0xc0, 0xc0, 0xde, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, //  71 'G'
                            0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xfe, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, //  72 'H'
                            0x00, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, //  73 'I'
                            0x00, 0x0e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0xc6, 0x7c, 0x00, //  74 'J'
                            0x00, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0x00, //  75 'K'
                            0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0x00, //  76 'L'
                            0x00, 0x82, 0xc6, 0xee, 0xd6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, //  77 'M'
                            0x00, 0xc6, 0xe6, 0xe6, 0xf6, 0xf6, 0xde, 0xde, 0xce, 0xc6, 0xc6, 0x00, //  78 'N'
                            0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, //  79 'O'
                            0x00, 0xfc, 0xc6, 0xc6, 0xc6, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, //  80 'P'
                            0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xce, 0x7e, 0x03, //  81 'Q'
                            0x00, 0xfc, 0xc6, 0xc6, 0xc6, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, //  82 'R'
                            0x00, 0x7c, 0xc6, 0xc0, 0xc0, 0x7c, 0x06, 0x06, 0x06, 0xc6, 0x7c, 0x00, //  83 'S'
                            0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, //  84 'T'
                            0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, //  85 'U'
                            0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x6c, 0x38, 0x10, 0x00, //  86 'V'
                            0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xd6, 0xee, 0xc6, 0x82, 0x00, //  87 'W'
                            0x00, 0xc6, 0xc6, 0xc6, 0x6c, 0x38, 0x38, 0x6c, 0xc6, 0xc6, 0xc6, 0x00, //  88 'X'
                            0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0x7e, 0x06, 0x06, 0x06, 0xc6, 0x7c, 0x00, //  89 'Y'
                            0x00, 0xfe, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x30, 0x60, 0x60, 0xfe, 0x00, //  90 'Z'
                            0x00, 0x7c, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7c, 0x00, //  91 '['
                            0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x06, //  92 '\'
                            0x00, 0x7c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x7c, 0x00, //  93 ']'
                            0x00, 0x10, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  94 '^'
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, //  95 '_'
                            0x00, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  96 '`'
                            0x00, 0x00, 0x00, 0x00, 0x7c, 0x06, 0x7e, 0xc6, 0xc6, 0xc6, 0x7b, 0x00, //  97 'a'
                            0x00, 0xc0, 0xc0, 0xc0, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xfc, 0x00, //  98 'b'
                            0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc0, 0xc0, 0xc0, 0xc6, 0x7c, 0x00, //  99 'c'
                            0x00, 0x06, 0x06, 0x06, 0x7e, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7e, 0x00, // 100 'd'
                            0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xfe, 0xc0, 0xc6, 0x7c, 0x00, // 101 'e'
                            0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, // 102 'f'
                            0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0x7e, 0x06, 0x7c, // 103 'g'
                            0x00, 0xc0, 0xc0, 0xc0, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, // 104 'h'
                            0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, // 105 'i'
                            0x00, 0x0c, 0x0c, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x6c, 0x38, // 106 'j'
                            0x00, 0xc0, 0xc0, 0xc0, 0xc6, 0xcc, 0xd8, 0xf0, 0xd8, 0xcc, 0xc6, 0x00, // 107 'k'
                            0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, // 108 'l'
                            0x00, 0x00, 0x00, 0x00, 0xec, 0xd6, 0xd6, 0xd6, 0xd6, 0xd6, 0xd6, 0x00, // 109 'm'
                            0x00, 0x00, 0x00, 0x00, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, // 110 'n'
                            0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, // 111 'o'
                            0x00, 0x00, 0x00, 0x00, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xfc, 0xc0, 0xc0, // 112 'p'
                            0x00, 0x00, 0x00, 0x00, 0x7e, 0xc6, 0xc6, 0xc6, 0xc6, 0x7e, 0x06, 0x06, // 113 'q'
                            0x00, 0x00, 0x00, 0x00, 0xfc, 0xc6, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, // 114 'r'
                            0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc0, 0x7c, 0x06, 0xc6, 0x7c, 0x00, // 115 's'
                            0x00, 0x60, 0x60, 0x60, 0xfc, 0x60, 0x60, 0x60, 0x60, 0x66, 0x3c, 0x00, // 116 't'
                            0x00, 0x00, 0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7e, 0x00, // 117 'u'
                            0x00, 0x00, 0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0x6c, 0x38, 0x10, 0x00, // 118 'v'
                            0x00, 0x00, 0x00, 0x00, 0xd6, 0xd6, 0xd6, 0xd6, 0xd6, 0xd6, 0xec, 0x00, // 119 'w'
                            0x00, 0x00, 0x00, 0x00, 0xc6, 0xc6, 0x6c, 0x38, 0x38, 0x6c, 0xc6, 0x00, // 120 'x'
                            0x00, 0x00, 0x00, 0x00, 0xc6, 0xc6, 0xc6, 0x7e, 0x06, 0x06, 0x06, 0x7c, // 121 'y'
                            0x00, 0x00, 0x00, 0x00, 0xfe, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xfe, 0x00, // 122 'z'
                            0x00, 0x0c, 0x18, 0x18, 0x18, 0x30, 0x30, 0x18, 0x18, 0x18, 0x0c, 0x00, // 123 '{'
                            0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, // 124 '|'
                            0x00, 0x60, 0x30, 0x30, 0x30, 0x18, 0x18, 0x30, 0x30, 0x30, 0x60, 0x00, // 125 '}'
                            0x00, 0x36, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126 '~'
                            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 127 ''
                            
};