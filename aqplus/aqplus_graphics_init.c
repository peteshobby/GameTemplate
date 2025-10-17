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
 * @file  aqplus_graphics_init.c
 * @brief Aquarius+ one time graphics initialization functions.
 */

#include "graphics.h"
#include "constants.h"

#include <aqplus.h>

// This function:
// 1. sets the layer priorities
// 2. remaps the border character
void InitializeGraphics(void) {
	IO_VCTRL =  VCTRL_MODE_TILE | 
				VCTRL_TEXT_PRIO |
				VCTRL_SPR_EN | 
				VCTRL_TEXT_EN | 
				VCTRL_REMAP_BORDER_CH;
}