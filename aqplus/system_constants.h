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
 * @brief Aquarius+ global constants.
 */

#ifndef SYSTEM_CONSTANTS_H_
#define SYSTEM_CONSTANTS_H_

// Graphics
#define TILEMAP_RAM             0xC000
#define IMAGERAM				0xD000
#define SPRITE_BASE     		0x0080

#define COLOR(fore, back)       ((fore << 4) | back)

#define SwitchToVideoRam()      IO_BANK3 = 20

// Screen
#define SCREEN_WIDTH			40
#define SCREEN_HEIGHT			25

#define MIN_SPRITE_X		0
#define MAX_SPRITE_X		(SCREEN_WIDTH * 8)
#define MIN_SPRITE_Y		0
#define MAX_SPRITE_Y		(SCREEN_HEIGHT * 8)

// Tilemap
#define TILEMAP_HEIGHT          32
#define TILEMAP_WIDTH           64
#define TILE_PALETTE            (0x2000)
// Text RAM 
#define CHARRAM             	0x3000
#define COLRRAM             	0x3400
#define BORDER_COLOR        	0x37FF
#define CHARRAM_SIZE        	0x0400


// Palettes
#define PALETTE_SIZE        32
#define MAX_PALETTE         4
#define PALETTE_GB  		0
#define PALETTE_R   		1

// Sprites
// Sprite attributes
enum {
    SPRITE_ENABLE       = 0x8000,
    SPRITE_16           = 0x0800,
    SPRITE_FLIP_V       = 0x0400,
    SPRITE_FLIP_H       = 0x0200,
    SPRITE_PALETTE_0    = 0x0000,
    SPRITE_PALETTE_1    = 0x1000,
    SPRITE_PALETTE_2    = 0x2000,
    SPRITE_PALETTE_3    = 0x3000
};

// Start message
#define START_MESSAGE		"Press FIRE to play"

#endif // SYSTEM_CONSTANTS_H_
