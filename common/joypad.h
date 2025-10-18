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
 * @brief Joypad API.
 */
#ifndef JOYPAD_H_
#define JOYPAD_H_

#include <stdint.h>

void InitializeJoypad(void);

uint16_t GetRightJoypadState(void);
uint16_t GetLeftJoypadState(void);
uint8_t GetJoypad4WayDirection(uint16_t state);
uint8_t GetJoypad8WayDirection(uint16_t state);
uint8_t GetJoypad16WayDirection(uint16_t state);
uint8_t GetJoypadButtons(uint16_t state);


// Joypad Directions
#define JOY_NONE        255
#define JOY_N           0
#define JOY_NNE         1
#define JOY_NE          2
#define JOY_NEE         3
#define JOY_E           4
#define JOY_SEE         5
#define JOY_SE          6
#define JOY_SSE         7
#define JOY_S           8
#define JOY_SSW         9
#define JOY_SW          10
#define JOY_SWW         11
#define JOY_W           12
#define JOY_NWW         13
#define JOY_NW          14
#define JOY_NNW         15

#define JOY_B0          0b00000001
#define JOY_B1          0b00000010
#define JOY_B2          0b00000100
#define JOY_B3          0b00001000
#define JOY_B4          0b00010000
#define JOY_B5          0b00100000
#define JOY_B6          0b01000000
#define JOY_B7          0b10000000


#endif // JOYPAD_H_
