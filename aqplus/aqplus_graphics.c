/*
 * Copyright 2025 Peter Brown
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file  aqplus_graphics.c
 * @brief Aquarius+ graphics functions.
 */

#include "graphics.h"
#include "constants.h"

static uint8_t  *textRam     = (uint8_t *)  CHARRAM;
static uint8_t  *colorRam    = (uint8_t *)  COLRRAM;

#define CLRSCRN 	0x1E45
#define FILLSCRN	0x1e59
#define SCRSIZE		1000

// The rom FILLSCRN routine is hard coded to fill 1024 bytes. That does not 
// matter on an original Aquarius but on the Aquarius+ the border control
// attribute can be remapped to 1023 to allow every screen positon to have its 
// own character and color without affecting the boarder.
// As the screen is only 40x25 = 1000 positions we can clear it without 
// affecting the border by only writing 1000 bytes.
void ClearScreen(uint8_t color) {
	(void) color; // asm takes the parameter directly from the A register.
__asm
	ld		hl, #COLRRAM 
	ld 		b, a
	call 	Fill
	ld 		b, #SPACE_CHAR
	ld 		hl, #CHARRAM
	call 	Fill 
	jp		FillEnd

Fill:
	ld		de, #SCRSIZE
FillLoop:
	ld		(hl), b
	inc		hl
	dec		de
	ld		a, d
	or		e
	jr		nz, FillLoop
	ret
FillEnd:
__endasm;
}

void SetBorder(uint8_t color) {
    uint8_t *borderColor = (uint8_t *)BORDER_COLOR;
    *borderColor = color;
}

// This function:
// Sets very character sell on the screen to the space character
// and sets its background to the color given in the parameter.
// It also sets the border to the same color.
void ClearTextScreen(uint8_t backgroundColor) {
	ClearScreen(COLOR(0, backgroundColor));
}