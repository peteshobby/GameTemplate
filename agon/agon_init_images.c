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
 * @file  agon_init_images.h
 * @brief Agon Light one time image initialization functions.
 */

#include "agon_init_images.h"
#include "constants.h"
#include "images.h"
#include "vdp_functions.h"
#include "palette.h"

void ExpandImage(uint8_t *source, uint8_t *dest, uint8_t size) {
	int srcIndex;

	for(srcIndex = 0; srcIndex < size; ++srcIndex) {
		int dstIndex = srcIndex * 2;
		uint8_t left = source[srcIndex] >> 4;
		uint8_t right = source[srcIndex] & 0x0F;

		dest[dstIndex] = palettes[GRAPHICS_PALETTE_2][left][0];
		dest[dstIndex + 1] = palettes[GRAPHICS_PALETTE_2][right][0];
    }
}

 void InitializeSmallImages(void) {
    uint8_t buffer[64];
    for (int i = 0; i < MAX_SMALL_IMAGES; ++i) {
        uint16_t bufferId = IMAGE_BM_BASE + MAX_LARGE_IMAGES + i;

        ExpandImage((uint8_t *)&smallImages[i], (uint8_t *)&buffer, 32);
        ClearBuffer(bufferId);
        WriteBuffer(bufferId, 8, 8, (uint8_t *)&buffer);
        SelectBitmap(bufferId);
        CreateBitmap(8, 8, RGBA2222);
    }

}

void InitializeLargeImages(void) {
    uint8_t buffer[256];
    for (int i = 0; i < MAX_LARGE_IMAGES; ++i) {
        uint16_t bufferId = IMAGE_BM_BASE + i;

        ExpandImage((uint8_t *)&largeImages[i], (uint8_t *)&buffer, 128);            
        ClearBuffer(bufferId);
        WriteBuffer(bufferId, 16, 16, (uint8_t *)&buffer);
        SelectBitmap(bufferId);
        CreateBitmap(16, 16, RGBA2222);
    }
}

void InitializeImages(void) {
	InitializeLargeImages();
    InitializeSmallImages();
}