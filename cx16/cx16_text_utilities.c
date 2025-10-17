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
 * @file  cx16_text_utilities.c
 * @brief Commander X16 text display and utilitiy frunctions.
 */

#include "constants.h"
#include "text_utilities.h"
#include <stdlib.h>
#include <string.h>

#include <cx16.h>

// Need ascii_charmap.h to map character codes to standard ascii.
#include <ascii_charmap.h>

void DisplayText(uint8_t row, uint8_t column, const char* text, uint8_t color) {
	uint32_t offset = ((row * MAX_TILE_COLUMN) + column) * 2;
	uint32_t mapBaseAddr = 0x1B000 + offset;

    VERA.address = mapBaseAddr;
    VERA.address_hi = mapBaseAddr >> 16;
	VERA.address_hi |= VERA_INC_1;

	while(*(text)) {
		uint8_t ch = *(text++);

		VERA.data0 = ch;
		VERA.data0 = color; 
    }
}    

void DisplayChar(uint8_t row, uint8_t column, char ch, uint8_t color) {
	uint32_t offset = ((row * MAX_TILE_COLUMN) + column) * 2;
	uint32_t mapBaseAddr = 0x1B000 + offset;

    VERA.address = mapBaseAddr;
    VERA.address_hi = mapBaseAddr>>16;
	VERA.address_hi |= VERA_INC_1;

	VERA.data0 = ch;
	VERA.data0 = color;
}