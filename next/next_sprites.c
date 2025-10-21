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
 * @file  next_sprites.c
 * @brief ZX Spectrum Next sprite functions.
 */

#include "sprites.h"
#include "constants.h"
#include "images.h"

#include <arch/zxn.h>
#include <intrinsic.h>
#include <stdint.h>

void Show1616Sprite(uint8_t spriteIndex, uint8_t imageIndex, uint8_t palette, bool flipX, bool flipY, int16_t x, int16_t y) {
        uint8_t flip = 0;
        uint16_t ux = (uint16_t) x;
        uint16_t uy = (uint16_t) y;

        if ( x < 0 || y < 0 || y > 255) {
            Hide1616Sprite(spriteIndex);
            return;
        }
        if (flipX)
            flip |= 8;
        if (flipY)
            flip |= 4;
        if (ux > 255)
            flip |= 1;

        IO_SPRITE_SLOT = spriteIndex;
        IO_SPRITE_ATTRIBUTE = ux & 0xFF;
        IO_SPRITE_ATTRIBUTE = uy;
        IO_SPRITE_ATTRIBUTE = (palette << 4) | flip;
        IO_SPRITE_ATTRIBUTE = 0xC0 + imageIndex;
        IO_SPRITE_ATTRIBUTE = 0x80;
}

void Move1616Sprite(uint8_t spriteIndex, int16_t x, int16_t y) {
        uint16_t ux = (uint16_t) x;
        uint16_t uy = (uint16_t) y;

        if ( x < 0 || y < 0 || y > 255) {
            Hide1616Sprite(spriteIndex);
            return;
        }
        
        IO_SPRITE_SLOT = spriteIndex;
        IO_SPRITE_ATTRIBUTE = ux;
        IO_SPRITE_ATTRIBUTE = uy;
        if (ux > 255)
        IO_SPRITE_ATTRIBUTE = 1;
}

void Hide1616Sprite(uint8_t spriteIndex) {
    IO_SPRITE_SLOT = spriteIndex;
    IO_SPRITE_ATTRIBUTE = 0;
    IO_SPRITE_ATTRIBUTE = 0;
    IO_SPRITE_ATTRIBUTE = 0;
    IO_SPRITE_ATTRIBUTE = 0;
}

void Hide88Sprite(uint8_t spriteIndex) {
    Hide1616Sprite(spriteIndex);
}

void Show88Sprite(uint8_t spriteIndex, uint8_t imageIndex, uint8_t palette,  bool flipH, bool flipV, int16_t x, int16_t y) {
    Show1616Sprite(spriteIndex, imageIndex, palette, flipH, flipV, x, y);
}

