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
 * @file  cx16_init_graphics.c
 * @brief Commander X16 one time graphics initialization functions.
 */

#include "cx16_init_graphics.h"
#include "constants.h"
#include "graphics.h"
#include "text_color.h"

#include <cx16.h>


// This function:
// Enables both graphics layers and configures them.
// Layer 0 is configured as the tile layer.
// Layer 1 is configured as the text layer.
// The display is scaled to give a resolution of 320 x 240.
void InitializeGraphics(void) {

	vera_layer_enable(LAYER_0 | LAYER_1);

// Scale to 320x240
    VERA.display.hscale = 64;
    VERA.display.vscale = 64;

	ClearTextScreen(TRANSPARENT);
}