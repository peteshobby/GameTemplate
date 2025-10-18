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
 * @file  agon_graphics_init.c
 * @brief Agon Light one time graphics initialization functions.
 */

#include "agon_graphics_init.h"
#include "graphics.h"
#include <agon/vdp_vdu.h>
#include <stdbool.h>

#define MODE_320_240_64		8
#define DOUBLE_BUFFER		128

void InitializeGraphics(void) {
	vdp_mode(MODE_320_240_64 + DOUBLE_BUFFER);
	
// Hide cursor
	vdp_cursor_enable( false );

// Turn off screen scaling.
	vdp_logical_scr_dims(false);
	ClearTextScreen(0);
}