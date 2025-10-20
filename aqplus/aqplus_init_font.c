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
 * @file  aqplus_init_font.c
 * @brief Aquarius+ one time font initialization function.
 */

#include "aqplus_init_font.h"
#include "font.h"

#include <aqplus.h>
#include <stdint.h>

void InitializeFont(void) {
    uint8_t *characterRam = (uint8_t *) 0xC000;
    // Map UDC Ram (page 21) to $C000 (bank 3)
    IO_BANK3 = 21;
   
    memcpy(characterRam, font, FONT_SIZE);

	// Map bank 3 to VIDEO Ram
    IO_BANK3 = 20;	
}