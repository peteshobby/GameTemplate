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
 * @file  system_constants.h
 * @brief Commander X16 global constants.
 */

#ifndef SYSTEM_CONSTANTS_H_
#define SYSTEM_CONSTANTS_H_

// Need to include ascii_charmap.h in every file that defines strings to map
// character codes to standard ascii.
#include <ascii_charmap.h>

// VERA
// Layers
#define LAYER_0             0b00000001
#define LAYER_1             0b00000010
#define TEXT_LAYER          layer1
#define TILE_LAYER          layer0

// Sprites
#define ENABLE_SPRITES		64
#define SPRITE16X16     	0b01010000
#define SPRITE_FLIP_H   	0b0000001
#define SPRITE_FLIP_V   	0b0000010
#define HFLIP               1
#define VFLIP               2  
#define MAX_SPRITE_X        0x3FF

// Tilemap
#define TILESET_BASE        0x00000
#define TILESET_SIZE        128
#define TILEMAP_BASE        0x04000 
#define TILEMAP_WIDTH       64
#define TILEMAP_HEIGHT      64
#define TILE_16x16          0b00000011

// Colors
#define COLOR(fore, back)	((back << 4) | fore) 

// Screen
#define SCREEN_WIDTH		40
#define SCREEN_HEIGHT		30

// Tile map size
#define MAX_TILE_ROW    64
#define MAX_TILE_COLUMN 128 // Seems to be broken for text

// Start message
#define START_MESSAGE		"Press START to play"

#endif // SYSTEM_CONSTANTS_H_