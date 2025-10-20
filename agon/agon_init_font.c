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
 * @file  agon_init_font.c
 * @brief Agon Light one time font initialization function.
 */

#include "agon_init_font.h"
#include "font.h"

#include <agon/vdp_vdu.h>
#include <stdint.h>

void InitializeFont(void) {
    uint16_t ch;
    uint8_t data;

    for (ch = 0; ch <= 255; ++ch) {
        putch(23);
        putch(0);
        putch(0x90);
        putch(ch);
        for (data = 0; data < 8; ++data) {
            putch(font[ch * 8 + data]);
        }
    }
}