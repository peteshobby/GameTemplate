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
 * @file  cx16_image_init.c
 * @brief Commander X16 one time image initialization functions.
 */

 #include "cx16_image_init.h"
 #include "images.h"

 #include <cx16.h>

void LoadLargeImages(void) {
    unsigned long imageGraphicAddress = 0x2000;
    uint8_t image;
    uint8_t row;
    uint8_t column;

    VERA.address = imageGraphicAddress;
    VERA.address_hi = imageGraphicAddress>>16;
    VERA.address_hi |= VERA_INC_1;

    for (image = 0; image < MAX_LARGE_IMAGES; ++image) {
        for (row = 0; row < LARGE_IMAGE_HEIGHT; ++row) {
            for (column = 0; column < LARGE_IMAGE_WIDTH; ++column) {
                VERA.data0 = largeImages[image][row][column];
            }
        }
    }
}

void LoadSmallImages(void) {
    unsigned long imageGraphicAddress = 0x2000 + MAX_LARGE_IMAGES * 128;
     uint16_t row;
     uint16_t column;
     uint16_t image;

    VERA.address = imageGraphicAddress;
    VERA.address_hi = imageGraphicAddress>>16;
    VERA.address_hi |= VERA_INC_1;

    for (image = 0; image < MAX_SMALL_IMAGES; ++image) {
        for (row = 0; row < 8; ++row) {
            for (column = 0; column < 4;++column) {
                VERA.data0 = smallImages[image][row][column];
            }
            for (column = 0; column < 4;++column) {
                VERA.data0 = 0;
            }
        }
        for (row = 0; row < 8; ++row) {
            for (column = 0; column < 8;++column) {
                VERA.data0 = 0;
            }
        }
    }
}

void InitializeImageData(void) {
    LoadLargeImages();
    LoadSmallImages();
}
