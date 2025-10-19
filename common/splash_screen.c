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

#include "splash_screen.h"
#include "constants.h"
#include "frame_sync.h"
#include "graphics.h"
#include "text_color.h"
#include "text_utilities.h"

#include <stdio.h>
#include <stdint.h>

#define SPLASH_DELAY	50

void ShowColors(void) {
	uint8_t row;
	uint8_t column;

	for (row = 0; row < MAX_TEXT_COLOR; ++row) {
		for (column = 0; column < SCREEN_WIDTH; ++column)
			DisplayChar(row, column, ' ', COLOR(row, row));
	}
}

void ShowIntroduction(void) {
	
	DisplayCenteredText(MAX_TEXT_COLOR + 2, GAME_NAME, COLOR(WHITE, BLACK));
	DisplayCenteredText(MAX_TEXT_COLOR + 4, GAME_COPYRIGHT, COLOR(WHITE, BLACK));
	DisplayChar(MAX_TEXT_COLOR + 4, SCREEN_WIDTH / 2 - 9, COPYRIGHT_CHAR, COLOR(WHITE, BLACK));
	DisplayCenteredText(SCREEN_HEIGHT - 3, GAME_WEBSITE, COLOR(WHITE, BLACK));
}

void ShowSplashScreen(void) {
	ClearTextScreen(BLACK);
	ShowColors();
	ShowIntroduction();
	FrameSync();
	
// Draw it again for double buffered systems.
#ifdef DBLBUF
	ClearTextScreen(BLACK);
	ShowColors();
	ShowIntroduction();
#endif // DBLBUF

// Pause briefly so it can be read
	WaitForFrames(SPLASH_DELAY);
}