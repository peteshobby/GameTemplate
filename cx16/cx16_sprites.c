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
 * @file  cx16_sprites.c
 * @brief Commander X16 sprite functions.
 */

#include "sprites.h"
#include "constants.h"
#include "images.h"

#include <cx16.h>

void Show1616Sprite(uint8_t spriteIndex, uint8_t imageIndex, uint8_t palette, bool flipH, bool flipV, int16_t x, int16_t y) {
    unsigned long spriteAddress = 0x1FC00 + 8*spriteIndex;
    unsigned long spriteGraphicAddress = 0x2000;
    uint8_t flip = 0;

    if (x < 0)
        x = REAL_MAX_SPRITE_X - x;
    if (x > REAL_MAX_SPRITE_X)   
        x -= REAL_MAX_SPRITE_X;

    if (flipH)
        flip |= SPRITE_FLIP_H;

    if (flipV)
        flip |= SPRITE_FLIP_V;

    spriteGraphicAddress += imageIndex*128;


    VERA.address = spriteAddress;
    VERA.address_hi = spriteAddress>>16;
    // Set the Increment Mode, turn on bit 4
    VERA.address_hi |= 0b10000;

    VERA.data0 = spriteGraphicAddress>>5;
    VERA.data0 = 0b00000000 | spriteGraphicAddress>>13;

    VERA.data0 = x & 0xFF;
    VERA.data0 = (x >> 8) & 3;
    VERA.data0 = y & 0xFF; 
    VERA.data0 = (y >> 8) & 1;

    VERA.data0 = 0b00001000 | flip; // Z-Depth=2
    VERA.data0 = 0b00000000 | palette | SPRITE16X16; // 16x16 pixel image
}

void Move1616Sprite(uint8_t spriteIndex, int16_t x, int16_t y) {
    unsigned long spriteAddress = 0x1FC00 + 8*spriteIndex;

    if (x < 0)
        x = MAX_SPRITE_X - x;

    spriteAddress += 2;
    VERA.address = spriteAddress;
    VERA.address_hi = spriteAddress>>16;
    // Set the Increment Mode, turn on bit 4
    VERA.address_hi |= 0b10000;

    VERA.data0 = x;
    VERA.data0 = x >> 8;
    VERA.data0 = y; 
    VERA.data0 = y >> 8;
}

void Hide1616Sprite(uint8_t spriteIndex) {
    unsigned long spriteAddress = 0x1FC00 + 8*spriteIndex;
    spriteAddress += 6;
    VERA.address = spriteAddress;
    VERA.address_hi = spriteAddress>>16;
    // Set the Increment Mode, turn on bit 4
    VERA.address_hi |= 0b10000;

    VERA.data0 = 0;
 
}

void Hide88Sprite(uint8_t spriteIndex) {
    Hide1616Sprite(spriteIndex);
}

void Show88Sprite(uint8_t spriteIndex, uint8_t imageIndex, uint8_t palette, bool flipH, bool flipV, int16_t x, int16_t y) {
    Show1616Sprite(spriteIndex, imageIndex, palette, flipH,  flipV, x, y);
}
