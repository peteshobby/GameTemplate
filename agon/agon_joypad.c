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

#define PC_DR       0x9E
#define PC_DDR      0x9F
#define PD_DR       0xA2
#define PD_DDR      0xA3

uint8_t ReadPort(uint8_t port) {
    uint8_t output;
    __asm__ volatile (
        "ld b, 0 \n"
        "ld c, %1 \n"
        "in a, (c) \n"
        "ld %0, a"
        : "=r"(output)
        : "r"(port)
        : "cc", "memory", "b", "c", "a"
    );
    return output;
}

void WritePort(uint8_t port, uint8_t value) {
    __asm__ volatile (
        "ld b, 0 \n"
        "ld a, %1 \n"
        "ld c, %0 \n"
        "out (c), a"
        :
        : "r"(port), "r"(value)
        : "cc", "memory", "b", "c", "a"
    );
}

uint16_t ReadJoystick1() {
    WritePort(PC_DDR, 0xFF);
	unsigned char temp = ReadPort(PD_DDR);
	WritePort(PD_DDR, temp | 0xF0);

	unsigned char fire = ReadPort(PD_DR);
	unsigned char direction = ReadPort(PC_DR);
    
    return (direction << 8) | fire;
}

uint16_t ReadJoystick2() {
    WritePort(PC_DDR, 0xFF);
	unsigned char temp = ReadPort(PD_DDR);
	WritePort(PD_DDR, temp | 0xF0);

	unsigned char fire = ReadPort(PD_DR);
	unsigned char direction = ReadPort(PC_DR);

// Shift the return value one to the left to match the same
// bit masks as the first joystick.
    return ((direction << 8) | fire) << 1;
}

uint16_t GetRightJoypadState(void) {
    return (~ReadJoystick1()) & 0xFFF0;
}

uint16_t GetLeftJoypadState(void) {
    return (~ReadJoystick2()) & 0xFFF0;
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

    result = JOY_B0;
    return result;
}


