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
 * @file  aqplus_sprites.c
 * @brief Aquarius+ sprite functions.
 */

#include "sprites.h"
#include "constants.h"
#include "images.h"
#include "palette.h"


#include <aqplus.h>

void Show88Sprite(uint8_t spriteIndex, uint8_t imageIndex, uint8_t palette, bool flipX, bool flipY, int16_t x, int16_t y) {
    uint16_t image1 = imageIndex;
    uint16_t flip = 0;
    uint16_t nativePalette = palette << 12;

    if (flipX) {
        flip |= SPRITE_FLIP_H;
    }

    if (flipY) 
        flip |= SPRITE_FLIP_V;

    uint16_t attribute = SPRITE_ENABLE | nativePalette | flip | SPRITE_BASE + image1;
    IO_VSPRSEL  = spriteIndex;
    IO_VSPRIDX  = attribute & 0xFF;
    IO_VSPRATTR = attribute >> 8;
    IO_VSPRX_L = x & 0xFF;
    IO_VSPRX_H = x >> 8;
    IO_VSPRY   = y;

}

void Show1616Sprite(uint8_t spriteIndex, uint8_t imageIndex, uint8_t palette, bool flipX, bool flipY, int16_t x, int16_t y) {
    uint16_t image1 = imageIndex * 4;
    uint16_t image2 = image1 + 2;
    uint16_t flip = 0;
    uint16_t nativePalette = palette << 12;

    if (flipX) {
        image2 = imageIndex * 4;
        image1 = image1 + 2;
        flip |= SPRITE_FLIP_H;
    }

    if (flipY) 
        flip |= SPRITE_FLIP_V;


    uint16_t attribute = SPRITE_ENABLE | SPRITE_16 | nativePalette | flip | SPRITE_BASE + image1;
    IO_VSPRSEL  = spriteIndex * 2;
    IO_VSPRIDX  = attribute & 0xFF;
    IO_VSPRATTR = attribute >> 8;
    IO_VSPRX_L = x & 0xFF;
    IO_VSPRX_H = x >> 8;
    IO_VSPRY   = y;

    attribute = SPRITE_ENABLE | SPRITE_16 | nativePalette | flip | SPRITE_BASE + image2;

    x += 8;
    IO_VSPRSEL  = spriteIndex * 2 + 1;
    IO_VSPRIDX  = attribute & 0xFF;
    IO_VSPRATTR = attribute >> 8;
    IO_VSPRX_L = x & 0xFF;
    IO_VSPRX_H = x >> 8;
    IO_VSPRY   = y;
}

void Move1616Sprite(uint8_t spriteIndex, int16_t x, int16_t y) {
    uint16_t ux = (uint16_t) x;
    uint16_t uy = (uint16_t) y;
    IO_VSPRSEL  = spriteIndex;
    IO_VSPRX_L = ux & 0xFF;
    IO_VSPRX_H = ux >> 8;
    IO_VSPRY   = uy;

    ux += 8;

    IO_VSPRSEL  = spriteIndex + 1;
    IO_VSPRX_L = ux & 0xFF;
    IO_VSPRX_H = ux >> 8;
    IO_VSPRY   = uy;
}

void Hide88Sprite(uint8_t spriteIndex) {
    IO_VSPRSEL  = spriteIndex;
    IO_VSPRIDX  = 0;
    IO_VSPRATTR = 0;
}

void Hide1616Sprite(uint8_t spriteIndex) {
    IO_VSPRSEL  = spriteIndex * 2;
    IO_VSPRIDX  = 0;
    IO_VSPRATTR = 0;

    IO_VSPRSEL  = spriteIndex * 2 + 1;
    IO_VSPRIDX  = 0;
    IO_VSPRATTR = 0;
}

