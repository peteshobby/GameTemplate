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
 * @file  next_joypad.c
 * @brief ZX Spectrum Next joypad functions.
 */

#include "joypad.h"

#include <arch/zxn.h>


#define JOY_START   0b10000000
#define JOY_A       0b01000000
#define JOY_C       0b00100000
#define JOY_B       0b00010000
#define JOY_UP      0b00001000
#define JOY_DOWN    0b00000100
#define JOY_LEFT    0b00000010
#define JOY_RIGHT   0b00000001


void InitializeJoypad(void) {
// Set to Megadrive Joypad mapping, 50Mhz, enable scandoubler
    ZXN_NEXTREGA(REG_PERIPHERAL_1, 0x6B);
}

uint8_t GetJoypad4WayDirection(uint16_t state) {
    if (state & JOY_UP)
        return JOY_N;

    if (state & JOY_DOWN)
        return JOY_S;

    if (state & JOY_RIGHT)
        return JOY_E;

    if (state & JOY_LEFT)
        return JOY_W;

    return JOY_NONE;
}

uint8_t GetJoypad8WayDirection(uint16_t state) {
    if (state & JOY_UP) {
        if (state & JOY_RIGHT)
            return JOY_NE;
        if (state & JOY_LEFT)
            return JOY_NW;
        return JOY_N;
    }

    if (state & JOY_DOWN) {
        if (state & JOY_RIGHT)
            return JOY_SE;
        if (state & JOY_LEFT)
            return JOY_SW;
        return JOY_S;
    }

    if (state & JOY_RIGHT)
        return JOY_E;

    if (state & JOY_LEFT)
        return JOY_W;

    return JOY_NONE;
}

uint8_t GetJoypad16WayDirection(uint16_t state) {
    return GetJoypad8WayDirection(state);
}

uint8_t GetJoypadButtons(uint16_t state) {
    unsigned char result = 0;

    if(state & JOY_START)
        result |= JOY_B6;

    if(state & JOY_A)
        result |= JOY_B0;

    if(state & JOY_B)
        result |= JOY_B1;

    if(state & JOY_C)
        result |= JOY_B2;

    return result;
}
