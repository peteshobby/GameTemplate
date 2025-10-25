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
 * @file  game.h
 * @brief Game API.
 */

#include "game.h"
#include "constants.h"
#include "frame_sync.h"
#include "graphics.h"
#include "images.h"
#include "overlay.h"
#include "palette.h"
#include "sprites.h"
#include "text_color.h"

bool gameQuit = false;


void GameLoop(void) {
	int16_t x = 0;
	int16_t y = 0;
	int16_t dx = 1;
	int16_t dy = 1;

	SetupOverlay();
#ifdef DBLBUF
	FrameSync();
	SetupOverlay();
#endif // DBLBUF

	while(1) {
		FrameSync();
		UpdateOverlay();
		Show1616Sprite(1, TILE_EXAMPLE_IMAGE_0, GRID_AND_ENEMIES, false, false, x, y);
		x += dx;
		y += dy;

		if (x <= 0)
			dx = 1;
		if (x >= SCREEN_PIXEL_WIDTH - 15)
			dx = -1;
		if (y <= 0)
			dy = 1;
		if (y >= SCREEN_PIXEL_HEIGHT - 15)
			dy = -1;

	}
}

void PlayGame(void) {
	ClearTextScreen(TRANSPARENT);
#ifdef DBLBUF
	FrameSync();
	ClearTextScreen(TRANSPARENT);
#endif // DBLBUF

	GameLoop();
 }