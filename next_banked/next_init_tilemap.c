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
 * @file  next_init_tilemap.c
 * @brief ZX Spectrum Next one time tilemap initialization functions.
 */

#include "next_init_tilemap.h"
#include "constants.h"
#include "images.h"
#include "palette.h"

#include <arch/zxn.h> 

#define TILEMAP_TRANSPARENCY        0x4C
#define ULA_CONTROL                 0x68
#define TILEMAP_CONTROL             0x6B
#define TILEMAP_DEFAULT_ATTRIBUTE   0x6C
#define TILEMAP_BASE_ADDRESS        0x6E
#define TILE_DEFS_BASE_ADDRESS      0x6F

void InitializeTileLayer(void) {
    // ULA Control
    ZXN_NEXTREGA(ULA_CONTROL, 0b10000000);

    // // Tile layer transparent
     ZXN_NEXTREGA(TILEMAP_TRANSPARENCY, GLOBAL_TRANSPARENT);

    // Enable tilemap mode
	ZXN_NEXTREGA(TILEMAP_CONTROL, 0b10000011);		//; 40x32, 8-bit entries
	ZXN_NEXTREGA(TILEMAP_DEFAULT_ATTRIBUTE, 0b00100000);		//; palette offset, visuals

    // Tell harware where to find tiles
	ZXN_NEXTREGA(TILEMAP_BASE_ADDRESS, OFFSET_OF_MAP); //	; MSB of tilemap in bank 5
	ZXN_NEXTREGA(TILE_DEFS_BASE_ADDRESS, OFFSET_OF_TILES); //	; MSB of tilemap definitions
}

void InitializeTileSet(void) {
    uint8_t row;
    uint8_t column;
    uint16_t *tilemapRam = (uint16_t *) TILEMAP_RAM;
    uint16_t tilePalette = 0x2000;

    for (row = 0; row < TILEMAP_HEIGHT; ++row) {
        for (column = 0; column < TILEMAP_WIDTH; ++column) {
            tilemapRam[row * TILEMAP_WIDTH + column] =  tilePalette | ((row % 2) * 2 + (column % 2));
        }
    } 
}

void InitializeMap(void) {
      uint8_t *tileRam = (uint8_t *) TILE_RAM;
    uint8_t row;
    uint8_t column;

    uint8_t *gridSquare = (uint8_t *) largeImages[TILE_EXAMPLE_IMAGE_0];

    for (row = 0; row < 8; ++row) {
        for(column = 0; column < 4; ++column) {
            tileRam[row * 4 + column] = gridSquare[row * 8 + column];
            tileRam[32 + (row * 4) + column] = gridSquare[row * 8 + 4 + column];
            tileRam[64 + row * 4 + column] = gridSquare[64 + row * 8 + column];
            tileRam[96 + (row * 4) + column] = gridSquare[64 +row * 8 + 4 + column];
        }
    }
}

void InitializeTilemap(void) {
	InitializeTileLayer();
	InitializeTileSet();
	InitializeMap();
}