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
#include "large_image_data.h"
#include "small_image_data.h"
#include "vdp_functions.h"

 void InitializeSmallImages(void) {
    for (int i = 0; i < MAX_SMALL_IMAGES; ++i) {
        uint16_t bufferId = IMAGE_BM_BASE + MAX_LARGE_IMAGES + i;

        ClearBuffer(bufferId);
        WriteBuffer(bufferId, 8, 8, &smallImage[i * 64]);
        SelectBitmap(bufferId);
        CreateBitmap(8, 8, RGBA2222);
    }

}

void InitializeLargeImages(void) {
    for (int i = 0; i < MAX_LARGE_IMAGES; ++i) {
        uint16_t bufferId = IMAGE_BM_BASE + i;

        ClearBuffer(bufferId);
        WriteBuffer(bufferId, 16, 16, &largeImage[i * 256]);
        SelectBitmap(bufferId);
        CreateBitmap(16, 16, RGBA2222);
    }
}

void InitializeImages(void) {
	InitializeLargeImages();
    InitializeSmallImages();
}