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
 * @file  aqplus_init_tilemap.c
 * @brief Aquarius+ one time tilemap initialization functions.
 */

#include "aqplus_init_tilemap.h"
#include "constants.h"
#include "images.h"
#include "palette.h"

#include <aqplus.h>

#define TILE    ((TILE_EXAMPLE_IMAGE_0 * 4) + 128)

void InitializeTilemap(void) {
	uint16_t *tilemapRam  = (uint16_t *) TILEMAP_RAM;
    SwitchToVideoRam();
    
    for (uint8_t row = 0; row < TILEMAP_HEIGHT; ++row) {
        for (uint8_t column = 0; column < TILEMAP_WIDTH; ++column) {
            tilemapRam[row * TILEMAP_WIDTH + column] = TILE_PALETTE | (TILE + (row % 2) + ((column % 2) * 2));
        }
    }
}