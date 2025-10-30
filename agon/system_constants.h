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
 * @brief Agon Light global constants.
 */

#ifndef SYSTEM_CONSTANTS_H_
#define SYSTEM_CONSTANTS_H_

// Colors
#define COLOR(fore, back)   ((back << 4) | fore)

// Images
#define RGBA2222            1
#define IMAGE_BM_BASE       2000

#define ALPHA 				0b11000000
#define ALPHA_MASK			0b00111111

// Sprites
#define MAX_SPRITE			50

// Tilemap
#define TILEMAP_WIDTH       64
#define TILEMAP_HEIGHT      32

// Screen info
#define SCREEN_WIDTH        40
#define SCREEN_HEIGHT       25

#define MIN_SPRITE_X		0
#define MAX_SPRITE_X		(SCREEN_WIDTH * 8)
#define MIN_SPRITE_Y		16
#define MAX_SPRITE_Y		((SCREEN_HEIGHT - 2) * 8)

// Screen modes
#define MODE_320_240_64		8
#define MODE_320_200_64		12
#define DOUBLE_BUFFER		128

// Start message
#define START_MESSAGE		"Press FIRE to play"

#endif // SYSTEM_CONSTANTS_H_