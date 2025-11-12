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
 * @file  cx16_joypad.c
 * @brief Commander X16 joypad functions.
 */

#include "joypad.h"

#include <cx16.h>

// Undefine some of the Joypad defines in cx16.h
#undef JOY_SELECT
#undef JOY_START

//                     7654321076543210
#define JOY_SELECT   0b0010000000000000
#define JOY_START    0b0001000000000000
#define JOY_A        0b0000000010000000
#define JOY_B        0b1000000000000000
#define JOY_X        0b0000000001000000
#define JOY_Y        0b0100000000000000
#define JOY_L        0b0000000000100000
#define JOY_R        0b0000000000010000

//                    7654321076543210
#define JOY_UP      0b0000100000000000
#define JOY_DOWN    0b0000010000000000
#define JOY_LEFT    0b0000001000000000
#define JOY_RIGHT   0b0000000100000000

unsigned char joy1A;
unsigned char joy1X;
unsigned char joy1Y;
unsigned char joy2A;
unsigned char joy2X;
unsigned char joy2Y;


void InitializeJoypad(void) {
}

uint16_t ReadJoypad1() {
    asm("lda #0");
    asm("jsr $FF56");
    asm("sta %v", joy1A);
    asm("stx %v", joy1X);
    asm("sty %v", joy1Y);

    return (joy1A << 8) | joy1X;
}

uint16_t ReadJoypad2() {
    asm("lda #1");
    asm("jsr $FF56");
    asm("sta %v", joy2A);
    asm("stx %v", joy2X);
    asm("sty %v", joy2Y);

    return (joy2A << 8) | joy2X;
}

uint16_t GetRightJoypadState(void) {
    return ~ReadJoypad1();
}
uint16_t GetLeftJoypadState(void) {
    return ~ReadJoypad2();
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

    if(state & JOY_SELECT)
        result |= JOY_B7;

    if(state & JOY_A)
        result |= JOY_B0;

    if(state & JOY_B)
        result |= JOY_B1;

        if(state & JOY_X)
        result |= JOY_B2;

    if(state & JOY_Y)
        result |= JOY_B3;

    if(state & JOY_L)
        result |= JOY_B4;

    if(state & JOY_R)
        result |= JOY_B5;

    return result;
}