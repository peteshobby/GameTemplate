
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
 * @file  aqplus_init_palette.c
 * @brief Aquarius+ one time palette initialization functions.
 */

#include "aqplus_init_palette.h"
#include "constants.h"
#include "palette.h"

#include <aqplus.h>

void InitializePalette(void) {
    for (uint8_t index = 0; index < MAX_PALETTE; ++index) {
        uint8_t palette = index << 5;
        for (uint8_t i = 0; i < 16; i++) {
            uint8_t entry = (i << 1);
            IO_VPALSEL  = palette + entry + PALETTE_GB;
            IO_VPALDATA = palettes[index][i][0];
            IO_VPALSEL  = palette + entry + PALETTE_R;
            IO_VPALDATA = palettes[index][i][1];
        }
    }
}