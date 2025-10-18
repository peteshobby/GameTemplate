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
 * @file  palettes.h
 * @brief Common palette definitions.
 */

#ifndef PALETTES_H_
#define PALETTES_H_

#include <stdint.h>

#define MAX_PALETTE			4
#define PALETTE_ENTRIES		16
#define PALETTE_BYTES		2

extern const uint8_t palettes[MAX_PALETTE][PALETTE_ENTRIES][PALETTE_BYTES];

// Palette name constants.
#define OVERLAY	0
#define PLAYER_AND_SHOTS	1
#define GRID_AND_ENEMIES	2
#define MORE_ENEMIES	3

#endif // PALETTES_H_
