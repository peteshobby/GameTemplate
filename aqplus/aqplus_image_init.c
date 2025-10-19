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
 * @file  aqplus_image_init.c
 * @brief Aquarius+ one time image initialization functions.
 */

#include "aqplus_image_init.h"
#include "images.h"
#include "constants.h"

#include <aqplus.h>

void InitializeSmallImages(void) {
    int i;
    int row;
    int byte;
    uint8_t *imageRam = (uint8_t *) IMAGERAM; 
    uint16_t imageBase = ((MAX_LARGE_IMAGES) * 128);
    IO_BANK3 = 20;
    
     for (i = 0; i < MAX_SMALL_IMAGES; i++) { 
        int imageBase = i * 32;

        for (row = 0; row < 8; ++row) {
            uint16_t imageBase1 = (imageBase + imageBase) + (row * 4);

            for (byte = 0; byte < 4; ++byte) {
                imageRam[imageBase1 + byte] = smallImages[i][row][byte];
            }
        }
    }
}

void InitializeLargeImages(void) {
    int imageIndex;
    int row;
    int byte;
    uint8_t *imageRam = (uint8_t *) IMAGERAM; 
    IO_BANK3 = 20;

    for (imageIndex = 0; imageIndex < MAX_LARGE_IMAGES; imageIndex++) { 
        int imageBase =  imageIndex * 128;

        for (row = 0; row < 16; ++row) {
            int imageBase1 = (imageIndex * 128) + (row * 4);
            int imageBase2 = imageBase1 + 64;

            for (byte = 0; byte < 4; ++byte) {
                imageRam[imageBase1 + byte] = largeImages[imageIndex][row][byte];
                imageRam[imageBase2 + byte] = largeImages[imageIndex][row][4 + byte];
            }
        }
    }
}

// This function:
// Initializes the image data for tiles and images.
// On the Aquarius+ tiles are always 8x8 and images can be 8x8 or 8x16.
// When a tilemap is in use there is 12K available for image data and each
// 8x8 tile takes 32 bytes so there is only room for 384 images.
// To use the space effectively I spilt images into large and small.
// Large are 16x16 which is the standard size for images on some other systems.
// Small are 8x8.
void InitializeImageData(void) {
	InitializeLargeImages();
    InitializeSmallImages();
}