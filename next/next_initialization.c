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
 * @file  next_initialization.c
 * @brief ZX Spectrum Next one time initialization functions.
 */

 #include "initialization.h"
#include "constants.h"
#include "graphics.h"
#include "joypad.h"
#include "next_init_graphics.h"
#include "next_init_images.h"
#include "next_init_palette.h"
#include "next_init_tilemap.h"
#include "text_color.h"

#include <arch/zxn.h>

// Move the stack so I can use bank 3
#pragma output REGISTER_SP           = 0xBFFF
#pragma output CLIB_MALLOC_HEAP_SIZE = 0

#define RTM_28MHZ	3

void EnableTurboMode(void) {
	ZXN_NEXTREGA(REG_TURBO_MODE, RTM_28MHZ);
}

void InitializeSystem(void) {
	uint8_t currentBank = ZXN_READ_MMU6();

	EnableTurboMode();
	InitializeJoypad();

	ZXN_WRITE_MMU6(INIT_BANK);
	InitializeGraphics();
	InitializePalette();
	InitializeImages();
	InitializeTilemap();
	ZXN_WRITE_MMU6(currentBank);

	ClearTextScreen(TRANSPARENT);
}