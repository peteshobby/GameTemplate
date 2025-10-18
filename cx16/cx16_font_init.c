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
 * @file  cx16_font_init.c
 * @brief Commander X16 one time font initialization function.
 */

#include "cx16_font_init.h"
#include "font.h"

#include <cx16.h>
#include <stdint.h>

void InitializeFont(void) {
    int i;
    unsigned long tileBaseAddress = 0x01F000;
    VERA.address = tileBaseAddress;
    VERA.address_hi = tileBaseAddress>>16;
    VERA.address_hi |= VERA_INC_1;

    for (i = 0; i < FONT_SIZE; i++) {
        VERA.data0 = font[i];
    }
}