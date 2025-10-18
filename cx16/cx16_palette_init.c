
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
 * @file  cx16_palette_init.h
 * @brief Commander X16 one time palette initialization functions.
 */

#include "cx16_palette_init.h"
#include "palette.h"
#include "constants.h"

#include <cx16.h>

void InitializePalette(void) {
    uint8_t index;
    int i;
    
    for (index = 0; index < MAX_PALETTE; ++index) {
        unsigned long PaletteBaseAddr = 0x1FA00 + (index * 32);
        VERA.address = PaletteBaseAddr;
        VERA.address_hi = PaletteBaseAddr >> 16;
        VERA.address_hi |= VERA_INC_1;
        
        for (i = 0; i < PALETTE_ENTRIES; i++) {
           VERA.data0 = palettes[index][i][0];
           VERA.data0 = palettes[index][i][1];

        }
    }
}
