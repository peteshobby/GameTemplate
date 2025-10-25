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
 * @file  agon_initialization.c
 * @brief Agon Light one time initialization functions.
 */

#include "initialization.h"
#include "agon_init_graphics.h"
#include "agon_init_font.h"
#include "agon_init_images.h"
#include "agon_init_sprites.h"
#include "agon_init_tilemap.h"

#include <agon/vdp_vdu.h>
#include <agon/vdp_key.h>

// Not handling errors
void InitializeAgon(void) {
	vdp_vdu_init();
	vdp_key_init();
}

void InitializeSystem(void) {
	InitializeAgon();
	InitializeGraphics();
	InitializeFont();
	InitializeImages();
	InitializeSprites();
	InitializeTilemap();
}