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
 * @file  agon_text_utilities.c
 * @brief Agon Light text display and utilitiy frunctions.
 */

#include "constants.h"
#include "text_utilities.h"
#include "agon_text_palette.h"

#include <agon/vdp_vdu.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>


void DisplayChar(uint8_t row, uint8_t column, char ch, uint8_t color) {
	vdp_set_text_colour(agonTextPalette[color & 0x0F]);
	vdp_set_text_colour(128 + agonTextPalette[color >> 4]);
	
	//vdp_cursor_tab row and column are reversed from the function definition.
	vdp_cursor_tab(column, row);
	putch(ch);

    
}


void DisplayText(uint8_t row, uint8_t column, const char* text, uint8_t color) {
	vdp_set_text_colour(agonTextPalette[color & 0x0F]);
	vdp_set_text_colour(128 + agonTextPalette[color >> 4]);
	
	//vdp_cursor_tab row and column are reversed from the function definition.
	vdp_cursor_tab(column, row);

	while(*text != 0)
		putch(*text++);
}


