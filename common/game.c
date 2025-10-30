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
	int16_t x = MIN_SPRITE_X;
	int16_t y = MIN_SPRITE_Y;
	int16_t dx = 1;
	int16_t dy = 1;
	int16_t sx = 0;
	int16_t sy = 0;
	SetupOverlay();
#ifdef DBLBUF
	FrameSync();
	SetupOverlay();
#endif // DBLBUF

	while(1) {
		FrameSync();
		Show1616Sprite(1, TILE_EXAMPLE_IMAGE_3, GRID_AND_ENEMIES, false, false, x, y);
		ScrollTilemap(++sx, sy);
		UpdateOverlay();
		x += dx;
		y += dy;

		if (x <= MIN_SPRITE_X)
			dx = 1;
		if (x >= MAX_SPRITE_X - 15)
			dx = -1;
		if (y <= MIN_SPRITE_Y)
			dy = 1;
		if (y >= MAX_SPRITE_Y - 15)
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