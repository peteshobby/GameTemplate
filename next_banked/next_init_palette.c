
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
 * @file  next_init_palette.h
 * @brief ZX Spectrum Next one time palette initialization functions.
 */

#include "next_init_palette.h"
#include "palette.h"
#include "constants.h"

#include <arch/zxn.h>

void InitializePaletteByType(uint8_t paletteType) {
    int i;
    uint8_t paletteIndex = 0;
    
    IO_NEXTREG_REG = REG_PALETTE_CONTROL;
    IO_NEXTREG_DAT = paletteType;
    IO_NEXTREG_REG = REG_PALETTE_INDEX;
    IO_NEXTREG_DAT = paletteIndex;
    IO_NEXTREG_REG = REG_PALETTE_VALUE_16;

    for (uint8_t index = 0; index < MAX_PALETTE; ++index) {
        for (i = 0; i < 16; i++)
        {
            IO_NEXTREG_DAT = palettes[index][i][0];
            IO_NEXTREG_DAT = palettes[index][i][1];
        }
    }



}

#define PALETTE_TYPE_TILEMAP    0b00110000
#define PALETTE_TYPE_SPRITE     0b00100000
#define PALETTE_TYPE_L2         0b00010000

void InitializePalette(void) {
    InitializePaletteByType(PALETTE_TYPE_TILEMAP);
    InitializePaletteByType(PALETTE_TYPE_SPRITE);
    InitializePaletteByType(PALETTE_TYPE_L2);

    IO_NEXTREG_REG = REG_SPRITE_TRANSPARENCY_INDEX;
    IO_NEXTREG_DAT = 0x00;
   
}