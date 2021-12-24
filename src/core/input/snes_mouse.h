/*
 *  Copyright (C) 2010-2022 Fabio Cavallo (aka FHorse)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef INPUT_SNES_MOUSE_H_
#define INPUT_SNES_MOUSE_H_

#include "input.h"

void input_init_snes_mouse(void);
void input_wr_snes_mouse(BYTE *value, BYTE nport);
void input_rd_snes_mouse(BYTE *value, BYTE nport, BYTE shift);

#endif /* INPUT_SNES_MOUSE_H_ */
