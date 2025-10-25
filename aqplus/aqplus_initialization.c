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
 * @file  aqplus_initialization.c
 * @brief Aquarius+ one time initialization functions.
 */

#include "initialization.h"
#include "aqplus_graphics.h"
#include "aqplus_init_font.h"
#include "aqplus_init_graphics.h"
#include "aqplus_init_images.h"
#include "aqplus_init_palette.h"
#include "aqplus_init_tilemap.h"
#include "constants.h"
#include "graphics.h"
#include "text_color.h"

#include <aqplus.h>

#define TURBO_MODE		0b00000100
#define UNLIMITED_MODE	0b00001000


void EnableTurboMode(void) {
    IO_SYSCTRL |= TURBO_MODE;
}

void InitializeSystem() {
	EnableTurboMode();
	InitializeGraphics();
	InitializePalette();
	InitializeFont();
	InitializeImages();
	InitializeTilemap();

	ClearTextScreen(BLACK);
	SetBorder(BLACK);
}