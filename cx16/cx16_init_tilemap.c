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
 * @file  cx16_init_tilemap.c
 * @brief Commander X16 one time tilemap initialization functions.
 */

#include "cx16_init_tilemap.h"
#include "constants.h"
#include "images.h"
#include "palette.h"

#include <cx16.h> 

void InitializeTileLayer(void) { 
    VERA.TILE_LAYER.config = 0b01010010; // 64x64 16 colors
    VERA.TILE_LAYER.mapbase = TILEMAP_BASE >> 9;
    VERA.TILE_LAYER.tilebase = (TILESET_BASE >> 9) | TILE_16x16;
}

void InitializeTileSet(void) {
    unsigned long tileBaseAddr = TILESET_BASE;
    uint8_t row;
    uint8_t column;

    VERA.control = 0x00;
    VERA.address = tileBaseAddr;
    VERA.address_hi = tileBaseAddr>>16;
    VERA.address_hi |= VERA_INC_1;

    for (row = 0; row < 16; ++row) {
        for (column = 0; column < 8; ++column) {
            VERA.data0 = largeImages[TILE_EXAMPLE_IMAGE_0][row][column];
        }
    }
}

void InitializeMap(void) {
    unsigned long mapBaseAddr = TILEMAP_BASE;
    unsigned char row;
    unsigned char column;
    uint8_t palette = GRID_AND_ENEMIES << 4;
    VERA.control = 0x00;
    VERA.address = mapBaseAddr;
    VERA.address_hi = mapBaseAddr>>16;

    // Set the Increment Mode, turn on bit 4
    VERA.address_hi |= 0b10000;


     for(row = 0; row < TILEMAP_HEIGHT; ++row) {
        for (column=0; column< TILEMAP_WIDTH; ++column) {
            VERA.data0 = 0;
            VERA.data0 = palette;
        }
    }
}

void InitializeTilemap(void) {
	InitializeTileLayer();
	InitializeTileSet();
	InitializeMap();
}