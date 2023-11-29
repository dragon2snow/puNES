/*
 *  Copyright (C) 2010-2023 Fabio Cavallo (aka FHorse)
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

#include <string.h>
#include "mappers.h"
#include "save_slot.h"

INLINE static void prg_fix_148(void);
INLINE static void chr_fix_148(void);

struct m148 {
	BYTE reg;
} m148;

void map_init_148() {
	EXTCL_AFTER_MAPPER_INIT(148);
	EXTCL_CPU_WR_MEM(148);
	EXTCL_SAVE_MAPPER(148);
	map_internal_struct_init((BYTE *)&m148, sizeof(m148));

	if (info.reset >= HARD) {
		memset(&m148, 0x00, sizeof(m148));
	}
}
void extcl_after_mapper_init_148(void) {
	prg_fix_148();
	chr_fix_148();
}
void extcl_cpu_wr_mem_148(BYTE nidx, WORD address, BYTE value) {
	// bus conflict
	m148.reg = value & prgrom_rd(nidx, address);
	chr_fix_148();
}
BYTE extcl_save_mapper_148(BYTE mode, BYTE slot, FILE *fp) {
	save_slot_ele(mode, slot, m148.reg);
	return (EXIT_OK);
}

INLINE static void prg_fix_148(void) {
	memmap_auto_32k(0, MMCPU(0x8000), (m148.reg >> 3));
}
INLINE static void chr_fix_148(void) {
	memmap_auto_8k(0, MMPPU(0x0000), (m148.reg & 0x07));
}


