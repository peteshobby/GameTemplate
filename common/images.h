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
 * @file  images.c
 * @brief Common image data for tiles and sprites.
 */

#ifndef IMAGES_H_
#define IMAGES_H_

#include <stdint.h>

#define MAX_LARGE_IMAGES		4
#define LARGE_IMAGE_HEIGHT		16
#define LARGE_IMAGE_WIDTH 		8

extern const uint8_t largeImages[MAX_LARGE_IMAGES][LARGE_IMAGE_HEIGHT][LARGE_IMAGE_WIDTH];

#define MAX_SMALL_IMAGES		7
#define SMALL_IMAGE_HEIGHT		8
#define SMALL_IMAGE_WIDTH 		4

extern const uint8_t smallImages[MAX_SMALL_IMAGES][SMALL_IMAGE_HEIGHT][SMALL_IMAGE_WIDTH];

// Large Image IDs
#define TILE_EXAMPLE_IMAGE_0		0
#define TILE_EXAMPLE_IMAGE_1		1
#define TILE_EXAMPLE_IMAGE_2		2
#define TILE_EXAMPLE_IMAGE_3		3

// Small Image IDs
#define SHOTS_IMAGE_0   		0
#define SHOTS_IMAGE_1   		1
#define SHOTS_IMAGE_2   		2
#define SHOTS_IMAGE_3   		3
#define SHOTS_IMAGE_4   		4
#define SHOTS_IMAGE_5   		5
#define SHOTS_IMAGE_6   		6

#endif // IMAGES_H_
