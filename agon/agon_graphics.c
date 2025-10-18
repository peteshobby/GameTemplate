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
 * @file  agon_graphics.c
 * @brief Agon Light graphics functions.
 */

#include "graphics.h"
#include "frame_sync.h"
#include "agon_text_palette.h"
#include <agon/vdp_vdu.h>
#include <stdbool.h>



void ClearTextScreen(uint8_t backgroundColor) {
	vdp_set_text_colour(agonTextPalette[backgroundColor] + 128);
	vdp_clear_screen();
	FrameSync();
	vdp_clear_screen();
}


