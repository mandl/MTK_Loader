/*
 *
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "memory.h"
#include "string.h"
#include "mt6223.h"
#include "stdio.h"
#include "stdint.h"
#include "led.h"



void LedGreen(uint16_t on) {

	uint16_t reg;
	reg = readw(MTK6223_PMIC_CON5);

	if (on == 1) {
		/* LED on */
		reg |= MTK6223_BLED_EN;
	} else {
		reg &= ~(MTK6223_BLED_EN);
	}

	writew(reg, MTK6223_PMIC_CON5);
}

void LedBlue(uint16_t on) {

	uint16_t reg;
	reg = readw(MTK6223_PMIC_CON5);

	if (on == 1) {
		/* LED on */
		reg |= MTK6223_RLED_EN;
	} else {
		reg &= ~(MTK6223_RLED_EN);
	}

	writew(reg, MTK6223_PMIC_CON5);
}

void LedRed(uint16_t on) {

	uint16_t reg;
	reg = readw(MTK6223_PMIC_CON5);

	if (on == 1) {
		/* LED on */
		reg |= MTK6223_GLED_EN;
	} else {
		reg &= ~(MTK6223_GLED_EN);
	}

	writew(reg, MTK6223_PMIC_CON5);
}

