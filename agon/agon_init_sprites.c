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
 * @file  agon_init_sprites.c
 * @brief Agon Light one time sprite initialization functions.
 */

#include "agon_init_sprites.h"


#include "constants.h"
#include "images.h"
#include "vdp_functions.h"
#include "graphics.h"
#include "frame_sync.h"
#include "text_color.h"

void LoadSpriteFrames(void) {
	uint8_t frame;
	uint8_t sprite;

	for (sprite = 0; sprite < MAX_SPRITE; ++sprite) {
		SelectSprite(sprite);
    	SetHardwareSprite();
    	ClearSprite();
		for (frame = 0; frame < MAX_LARGE_IMAGES + MAX_SMALL_IMAGES; ++frame) {
			AddSpriteFrame(IMAGE_BM_BASE + frame);
		}
	}
}

#define TEST_BM     2000
#define TEST_SPRITE 1

void TestSprite(void) {
	int16_t x = 0;
	int16_t y = 0;
	int16_t dx = 1;
	int16_t dy = 1;
	SelectBitmap(TEST_BM);
	DrawBitmap(10, 10);

    SelectSprite(0);
    SelectNthFrame(0);
    // MoveSprite(100, 100);
    // ShowSprite();

	while(1) {
		FrameSync();
		MoveSprite(x, y);
		ShowSprite();
		ActivateSprites(MAX_SPRITE);
		UpdateSprites();
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

// Note: Hardware sprites do not work correctly in the emulator with a double
// buffered screen.
void InitializeSprites(void) {
	EnableHardwareSprites();
	LoadSpriteFrames();
	ClearTextScreen(CYAN);
	//TestSprite();
	ActivateSprites(MAX_SPRITE);
}