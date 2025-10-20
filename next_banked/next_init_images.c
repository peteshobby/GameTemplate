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
 * @file  next_init_images.c
 * @brief ZX Spectrum Next one time image initialization functions.
 */

#include "next_init_images.h"
#include "constants.h"
#include "images.h"

#include <stdint.h>
#include <arch/zxn.h>


void LoadSmallImages(void) {
    uint16_t row;
    uint16_t column;
    uint16_t image;


    for (image = 0; image < MAX_SMALL_IMAGES; ++image) {
        IO_SPRITE_SLOT = MAX_LARGE_IMAGES + image;
        for (row = 0; row < 8; ++row) {
            for (column = 0; column < 4;++column) {
                IO_SPRITE_PATTERN = smallImages[image][row][column];
            }
            for (column = 0; column < 4;++column) {
                IO_SPRITE_PATTERN = 0;
            }
        }
        for (row = 0; row < 8; ++row) {
            for (column = 0; column < 8;++column) {
                IO_SPRITE_PATTERN = 0;
            }
        }
    } 
}

void LoadLargeImages(void) {
    uint8_t image;
    uint8_t row;
    uint8_t column;

    for (image = 0; image < MAX_LARGE_IMAGES; ++image) {
        IO_SPRITE_SLOT = image;
        for (row = 0; row < LARGE_IMAGE_HEIGHT; ++row) {
            for (column = 0; column < LARGE_IMAGE_WIDTH; ++column) {
                IO_SPRITE_PATTERN = largeImages[image][row][column];
            }
        }
    }
}

void InitializeImages(void) {
    LoadLargeImages();
    LoadSmallImages();
}