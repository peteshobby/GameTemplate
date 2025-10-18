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
 * @file  aqplus_joypad.c
 * @brief Aquarius+ joypad functions.
 */

#include "joypad.h"

#include <aqplus.h>


// Aquarius joypad pins
#define D0                1
#define D1                2
#define D2                4
#define D3                8
#define D4               16
#define D5               32
#define D6               64
#define D7              128

void InitializeJoypad(void) {
}

uint16_t GetRightJoypadState(void) {
    IO_PSG1ADDR = 15;
    return ~IO_PSG1DATA;
}

uint16_t GetLeftJoypadState(void) {
    IO_PSG1ADDR = 14;
    return ~IO_PSG1DATA;
}

uint8_t GetJoypad4WayDirection(uint16_t state) {
    uint8_t direction = GetJoypad16WayDirection(state);

    switch (direction) {
    case JOY_N:
    case JOY_NW:
    case JOY_NE:
    case JOY_NNW:
    case JOY_NNE:
        return JOY_N;
    case JOY_NWW:
    case JOY_W:
    case JOY_SWW:
        return JOY_W;
    case JOY_NEE:
    case JOY_E:
    case JOY_SEE:
        return JOY_E;
    case JOY_S:
    case JOY_SW:
    case JOY_SE:
    case JOY_SSW:
    case JOY_SSE:
        return JOY_S;
    default:
        return JOY_NONE;
    }

}

uint8_t GetJoypad8WayDirection(uint16_t state) {
    unsigned char direction = GetJoypad16WayDirection(state);

    switch (direction) {
    case JOY_N:
    case JOY_NNW:
    case JOY_NNE:
        return JOY_N;
    case JOY_NW:
    case JOY_NE:
    case JOY_SW:
    case JOY_SE:
        return direction;
    case JOY_NWW:
    case JOY_W:
    case JOY_SWW:
        return JOY_W;
    case JOY_NEE:
    case JOY_E:
    case JOY_SEE:
        return JOY_E;
    case JOY_S:
    case JOY_SSW:
    case JOY_SSE:
        return JOY_S;
    default:
        return JOY_NONE;
    }
}

uint8_t GetJoypad16WayDirection(uint16_t state) {
    // Remove button states
   state &= 0b0000000000011111;
 
    if (state == D0) 
        return JOY_S;

    if (state == (D0 | D1))
        return JOY_SSE;

    if (state == (D0 | D1 | D4))
        return JOY_SE;

    if (state == (D1 | D4))
        return JOY_SEE;

    if (state == D1)
        return JOY_E;

    if (state == (D1 | D2))
    return JOY_NEE;

    if (state == (D1 | D2 | D4))
    return JOY_NE;

    if (state == (D2 | D4))
    return JOY_NNE;

   if (state == D2)
     return JOY_N;

    if (state == (D3 | D2))
        return JOY_NNW;

    if (state == (D2 | D3 | D4))
        return JOY_NW;

    if (state == (D3 | D4))
        return JOY_NWW;

    if (state == D3)
        return JOY_W;

    if (state == (D0 | D3))
        return JOY_SWW;

    if (state == (D0 | D3 | D4))
        return JOY_SW;

    if (state == (D0 | D4))
        return JOY_SSW;
    
    return JOY_NONE;
}

#define B0_STATE    (D6)
#define B1_STATE    (D7 | D2)
#define B2_STATE    (D7 | D5)
#define B3_STATE    (D5)
#define B4_STATE    (D7 | D1)
#define B5_STATE    (D7 | D0)

uint8_t GetJoypadButtons(uint16_t state) {
    uint8_t result = 0;

    if((state & B0_STATE) == B0_STATE)
        result |= JOY_B0;

    if((state & B1_STATE) == B1_STATE)
        result |= JOY_B1;

    if((state & B2_STATE) == B2_STATE)
        result |= JOY_B2;
    else
        if((state & B3_STATE) == B3_STATE)
            result |= JOY_B3;

    if((state & B4_STATE) == B4_STATE )
        result |= JOY_B4;

    if((state & B5_STATE) == B5_STATE)
        result |= JOY_B5;

    return result;
}