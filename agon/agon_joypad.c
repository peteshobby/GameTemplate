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
 * @file  agon_joypad.c
 * @brief Agon Light joypad functions.
 */

#include "joypad.h"
#include "agon_joypad_utilities.h"
#include "text_color.h"
#include "text_utilities.h"

#include <agon/vdp_vdu.h>
#include <agon/vdp_key.h>

#include "system_constants.h"


// Agon joystick bit masks
//                    7654321076543210
#define JOY_UP      0b0000001000000000
#define JOY_DOWN    0b0000100000000000
#define JOY_LEFT    0b0010000000000000
#define JOY_RIGHT   0b1000000000000000
#define JOY_A       0b0000000000100000
#define JOY_B       0b0000000010000000

uint16_t ReadJoystick1() {
    SetJoyPorts();
    uint8_t direction = ReadDirection();
    uint8_t fire  = ReadFire();
    
    return (direction << 8) | fire;
}

uint16_t ReadJoystick2() {
    SetJoyPorts();
    uint8_t direction = ReadDirection();
    uint8_t fire  = ReadFire();
    uint16_t result =  direction << 8 | fire;

// Shift the return value one to the left to match the same
// bit masks as the first joystick.

    return result << 1;
}

uint16_t GetRightJoypadState(void) {
    return ~ReadJoystick1() & 0xFFF0;
}

uint16_t GetLeftJoypadState(void) {
    return ~ReadJoystick2() & 0xFFF0;
}

uint16_t GetDefaultJoypadState(void) {
    return GetRightJoypadState();
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
    uint8_t result = 0;

    if(state & JOY_A)
        result |= JOY_B0;

    if(state & JOY_B)
        result |= JOY_B1;

    return result;
}


