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
 * @file  agon_init_tilemap.c
 * @brief Agon Light one time tilemap initialization functions.
 */

#include "agon_init_tilemap.h"
#include "agon_init_images.h"
#include "constants.h"
#include "graphics.h"
#include "images.h"
#include "palette.h"
#include "vdp_functions.h"

#include <agon/vdp_vdu.h>

void InitializeTileBank(void) {
  putch(23);
  putch(0);
  putch(0xC2);
  putch(0);
  putch(0);
  putch(0);
  putch(0);
  putch(0);
}

void InitializeTileSet(void) {
    uint8_t row;
    uint8_t column;
    uint8_t tileId;
    uint8_t buffer[256];

    ExpandImage((uint8_t *)&largeImages[TILE_EXAMPLE_IMAGE_0], (uint8_t *)&buffer, 128);    
    InitializeTileBank();

    for (tileId = 0; tileId < 4; ++tileId) {
      uint8_t offset = (tileId > 1) ? 112 : 0;
      putch(23);
      putch(0);
      putch(0xC2);
      putch(1);
      putch(0);
      putch(tileId + 1);

      for (row = 0; row < 8; ++row) {
        for (column = 0; column < 8; ++column) {
          putch(buffer[ offset + (row * 16) + column + tileId * 8]);
        }
      }
    }
}

void InitializeTilemapMap(uint8_t mode) {
    putch(23);
    putch(0);
    putch(0xC2);
    putch(16);
    putch(0);
    putch(mode);
    putch(0);
    putch(0);
}


void SetTile(uint8_t row, uint8_t column, uint8_t tileId, uint8_t attribute) {
    putch(23);
    putch(0);
    putch(0xC2);
    putch(17);
    putch(0);
    putch(column);
    putch(row);
    putch(tileId);
    putch(attribute);
}

void InitializeMap(void) {
    uint8_t row;
    uint8_t column;

    for (row = 0; row < TILEMAP_HEIGHT; ++row) {
        for (column = 0; column < TILEMAP_WIDTH; ++column) {
            uint8_t tileId = 1 + (row % 2) * 2 + (column % 2);
            SetTile(row, column, tileId, 0);
        }
    }
}

void InitializeTilemapLayer(uint8_t layer) {
    putch(23);
    putch(0);
    putch(0xC2);
    putch(24);
    putch(0);
    putch(layer);
    putch(0);
    putch(0);
}



void InitializeTilemap(void) {
    EnableTilemap();
    InitializeTileSet();
    InitializeTilemapMap(TILE_MAP_MODE_64x32);
    InitializeTilemapLayer(TILE_LAYER_MODE_40x25);
    InitializeMap();
    ScrollTilemap(0, 0);
}