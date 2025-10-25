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
 * @file  agon_graphics.c
 * @brief Agon Light graphics functions.
 */

#include "graphics.h"
#include "frame_sync.h"
#include "agon_text_palette.h"
#include <agon/vdp_vdu.h>
#include <stdbool.h>



void ClearTextScreen(uint8_t backgroundColor) {
	vdp_set_text_colour(agonTextPalette[backgroundColor] + 128);
	vdp_clear_screen();
}

void UpdateAndDrawLayer(void) {
    putch(23);
    putch(0);
    putch(0xC2);
    putch(30);
    putch(0);
}

void ScrollTilemap(int16_t x, int16_t y) {
	uint8_t xpos = x >> 3;
	uint8_t xoffset = x & 7;
	uint8_t ypos = y >> 3;
	uint8_t yoffset = y & 7;
  
	putch(23);
	putch(0);
	putch(0xC2);
	putch(26);
	putch(0);
	putch(xpos);
	putch(ypos);
	putch(xoffset);
	putch(yoffset);

	UpdateAndDrawLayer();
}
