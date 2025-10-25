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
 * @file  cx16_graphics.c
 * @brief Commander X16 graphics functions.
 */

 #include "graphics.h"
#include "constants.h"
#include <cx16.h>

// This function:
// Sets the text layer to the space charater with the given
// background color.
// Note the text layer is 64x64 characters but only 40x30
// is visible on the screen.
void ClearTextScreen(uint8_t backgroundColor) {
    unsigned long mapBaseAddr = 0x1B000;
    uint8_t color = COLOR(1, backgroundColor);
    uint8_t count;

    VERA.address = mapBaseAddr;
    VERA.address_hi = mapBaseAddr>>16;
    VERA.control = 0b00000100;
    VERA.display.fxctrl = 0b01000000;
    VERA.control = 0b00001100;
    VERA.display.fxcachel = SPACE_CHAR;
    VERA.display.fxcachem = color;
    VERA.display.fxcacheh = SPACE_CHAR;
    VERA.display.fxcacheu = color;
    VERA.address_hi |= 0b00110000;

// Need to write 2048 times:
// 64x64 character positions = 4096
// 2 bytes per position = 8192
// divided by 4 bytes = 2048
// 2048 = 256 * 8 writes;
    count = 255;
    do {
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
    } while (--count != 255);

    VERA.control = 0b00000100;
    VERA.display.fxctrl = 0b00000000;

}

void ScrollTilemap(int16_t x, int16_t y) {
    VERA.TILE_LAYER.hscroll = x;
    VERA.TILE_LAYER.vscroll = y;
}