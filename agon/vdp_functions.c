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
 * @file  vdp_functions.c
 * @brief Agon Light VDP wrapper functions.
 */

#include "vdp_functions.h"
#include "constants.h"

#include <agon/vdp_vdu.h>
#include <agon/vdp_key.h>

void putwd(uint16_t value) {
    putch(value & 0xFF);
    putch(value >> 8);
}

void putdwd(uint32_t value) {
    putch(value & 0xFF);
    value >>= 8;
    putch(value & 0xFF);
    value >>= 8;
    putch(value & 0xFF);
    value >>= 8;
    putch(value & 0xFF);
}

void EnableScrollProtection(void) {
    putch(23);
    putch(16);
    putch(1);
    putch(255);
}

// Buffer functions
void ClearBuffer(uint16_t bufferId) {
    putch(23);
    putch(0);
    putch(0xA0);
    putwd(bufferId);
    putch(2);
}

void WriteBuffer(uint16_t bufferId, uint16_t width, uint16_t height, const uint8_t *source) {
    uint16_t length = height * width;

    putch(23);
    putch(0);
    putch(0xA0);
    putwd(bufferId);
    putch(0);
    putwd(length);

    uint32_t *data = (uint32_t *) source;
    for(int i = 0; i < length/4; ++i)
        putdwd(data[i]);
}

void WriteMultipleBuffer(uint16_t bufferId, uint16_t width, uint16_t height, uint8_t rows, uint8_t columns, const uint8_t *source) {
    uint16_t length = height * rows * width * columns;

    putch(23);
    putch(0);
    putch(0xA0); 
    putwd(bufferId);
    putch(0);
    putwd(length); 
 
    for (int row = 0; row < rows; ++row) {
        for(int y = 0; y < height; ++y) {
            uint16_t base = y * width;
            for(int column = 0; column < columns; ++column) {
                for (int x = 0; x < width; ++x) {
                    putch(source[base + x]);
                }
            }
        }
    }
}

void ConsolidateBuffer(uint16_t bufferId) {
        putch(23);
    putch(0);
    putch(0xA0); 
    putwd(bufferId);
    putch(14);
}

// Bitmap functions
void SelectBitmap(uint16_t bitmapId) {
    putch(23);
    putch(27);
    putch(32);
    putwd(bitmapId);
}

void DrawBitmap(uint16_t x, uint16_t y) {
    putch(23);
    putch(27);
    putch(3);
    putwd(x);
    putwd(y);
}

void CreateBitmap(uint16_t width, uint16_t height, uint8_t format) {
    putch(23);
    putch(27);
    putch(0x21);
    putwd(width);
    putwd(height);
    putch(format);
}

void CreateSolidBitmap(uint16_t width, uint16_t height, uint16_t col1, uint16_t col2) {
    putch(23);
    putch(27);
    putch(2);
    putwd(width);
    putwd(height);
    putwd(col1);
    putwd(col2);
}

// Sprites

void SelectSprite( uint8_t spriteId) {
    putch(23);
    putch(27);
    putch(4);
    putch(spriteId);
}

void ClearSprite(void) {
    putch(23);
    putch(27);
    putch(5);
}

void AddSpriteFrame(uint16_t bitmapId) {
    putch(23);
    putch(27);
    putch(0x26);
    putwd(bitmapId);
}

void SelectNthFrame(uint8_t frame) {
    putch(23);
    putch(27);
    putch(10);
    putch(frame);
}

void ShowSprite(void) {
    putch(23);
    putch(27);
    putch(11);
}

void HideSprite(void) {
    putch(23);
    putch(27);
    putch(12);
}

void MoveSprite(int16_t x, int16_t y) {
    putch(23);
    putch(27);
    putch(13);
    putwd(x);
    putwd(y);
}

void SetHardwareSprite(void) {
    putch(23);
    putch(27);
    putch(19);
}

void SetSoftwareSprite(void) {
    putch(23);
    putch(27);
    putch(20);
}

void UpdateSprites(void) {
    putch(23);
    putch(27);
    putch(15);
}

void ActivateSprites(uint8_t count) {
    putch(23);
    putch(27);
    putch(7);
    putch(count);
}

void EnableHardwareSprites(void) {
    putch(23);
    putch(0);
    putch(0xF8);
    putwd(2);
    putwd(1);
}

void EnableTilemap(void) {
    putch(23);
    putch(0);
    putch(0xF8);
    putwd(768);
    putwd(0);

}

void SwapScreen(void) {
    putch(23);
    putch(0);
    putch(0xC3);
}