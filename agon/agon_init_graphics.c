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
 * @file  agon_init_graphics.c
 * @brief Agon Light one time graphics initialization functions.
 */

#include "agon_init_graphics.h"
#include "constants.h"
#include "frame_sync.h"
#include "graphics.h"
#include "text_color.h"
#include "text_utilities.h"
#include "vdp_functions.h"

#include <agon/vdp_vdu.h>
#include <stdbool.h>

void InitializeGraphics(void) {
	vdp_mode(MODE_320_200_64 + DOUBLE_BUFFER);
	
// Hide cursor
	vdp_cursor_enable( false );

// Turn off screen scaling.
	vdp_logical_scr_dims(false);
	EnableScrollProtection();
}