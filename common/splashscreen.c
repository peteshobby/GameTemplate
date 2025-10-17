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
 * @file  splashscreen.c
 * @brief Common splash screen shown once immediately after loading.
 */

 #include "splashscreen.h"
#include "constants.h"
#include "frame_control.h"
#include "graphics.h"
#include "text_color.h"
#include "text_utilities.h"

#include <stdio.h>
#include <stdint.h>

#define MAX_COLOR		3
#define SPLASH_DELAY	50

void ShowColors(void) {
	uint8_t color;

	for (color = MAX_COLOR; color != 0; --color) {
		ClearTextScreen(color);
// Need to clear twice for Agon double buffer
		FrameSync();
		ClearTextScreen(color);
	
		WaitForFrames(SPLASH_DELAY);
	}
}

void ShowIntroduction(void) {
	int color;

	for (color = 0; color < MAX_TEXT_COLOR; ++color)
		DisplayChar(0, color, ' ', COLOR(color, color));

	DisplayCenteredText(SCREEN_HEIGHT / 2, GAME_NAME, COLOR(WHITE, BLACK));
	DisplayCenteredText(SCREEN_HEIGHT / 2 + 2, GAME_COPYRIGHT, COLOR(WHITE, BLACK));
	DisplayChar(SCREEN_HEIGHT / 2 + 2, SCREEN_WIDTH / 2 - 9, COPYRIGHT_CHAR, COLOR(WHITE, BLACK));
	DisplayCenteredText(SCREEN_HEIGHT - 3, GAME_WEBSITE, COLOR(WHITE, BLACK));

	// DisplaySigned8Bit(1, 30, 0, COLOR(WHITE, BLACK), '0', 2);
	// DisplaySigned8Bit(2, 30, 99, COLOR(WHITE, BLACK), '0', 4);
	// DisplaySigned8Bit(3, 30, -99, COLOR(WHITE, BLACK), '0', 5);
	// DisplaySigned8Bit(4, 30, 128, COLOR(WHITE, BLACK), '0', 4);
	// DisplaySigned8Bit(5, 30, -127, COLOR(WHITE, BLACK), '0', 5);

	DisplaySigned8Bit(1, 29, -1, COLOR(15, 1), '0', 10);


	FrameSync();
}

void ShowSplashScreen(void) {
	ShowColors();
	ShowIntroduction();
}