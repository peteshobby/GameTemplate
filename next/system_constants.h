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
 * @brief ZX Spectrum Next global constants.
 */

 #ifndef SYSTEM_CONSTANTS_H_
#define SYSTEM_CONSTANTS_H_

// Layer 2
#define LAYER_2_START_BANK		9
#define REG_LAYER_2_CONTROL		0x70
#define LAYER_2_320x256x8		0x10
#define CLIP_HEIGHT				255
#define CLIP_WIDTH				159

#define GLOBAL_TRANSPARENT		0xC3

// Tile Map
#define START_OF_BANK_5		                0x4000
#define TILEMAP_RAM	                        0x6000
#define TILE_RAM		                    0x6A00	
#define TILEDEF_SIZE                        32
#define OFFSET_OF_MAP		                0x20 // ((START_OF_TILEMAP - START_OF_BANK_5) >> 8)
#define OFFSET_OF_TILES		                0x2A // ((START_OF_TILES - START_OF_BANK_5) >> 8)

#define TILEMAP_WIDTH                       40
#define TILEMAP_HEIGHT                      32

// Color
#define COLOR(fore, back)       (((back << 4) | fore) & 0xFF) 

// Banking
#define BANK_3_START_ADDRESS	0xC000
#define BANK_LENGTH				0x4000

#define INIT_BANK				40

// Screen
#define SCREEN_WIDTH        	40
#define SCREEN_HEIGHT       	32

// Start message
#define START_MESSAGE		"Press FIRE to play"

#endif // SYSTEM_CONSTANTS_H_