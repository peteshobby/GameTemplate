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
 * @file  attract_screen.c
 * @brief Common attract screen shown once immediately after loading.
 */

#include "attract_screen.h"
#include "constants.h"
#include "frame_sync.h"
#include "graphics.h"
#include "text_color.h"
#include "text_utilities.h"

#include <stdbool.h>

#define ATTRACT_DELAY	30

void ShowInformation(void) {

	DisplayCenteredText(SCREEN_HEIGHT - 3, GAME_WEBSITE, COLOR(WHITE, BLACK));
	DisplayCenteredText(SCREEN_HEIGHT - 2, GAME_COPYRIGHT, COLOR(WHITE, BLACK));
	DisplayChar(SCREEN_HEIGHT - 2, SCREEN_WIDTH / 2 - 9, COPYRIGHT_CHAR, COLOR(WHITE, BLACK));
}

void WaitForAttractInput(void) {
	bool startGame = false;

	while (!startGame) {
		DisplayCenteredText(SCREEN_HEIGHT / 2, START_MESSAGE, COLOR(BLUE, YELLOW));
#ifdef DBLBUF
		FrameSync();
		DisplayCenteredText(SCREEN_HEIGHT / 2, START_MESSAGE, COLOR(BLUE, YELLOW));
#endif // DBLBUF

		WaitForFramesCheckForFire(ATTRACT_DELAY);
		DisplayCenteredText(SCREEN_HEIGHT / 2, START_MESSAGE, COLOR(YELLOW, BLUE));
#ifdef DBLBUF
		FrameSync();
		DisplayCenteredText(SCREEN_HEIGHT / 2, START_MESSAGE, COLOR(YELLOW, BLUE));
#endif // DBLBUF

		startGame = WaitForFramesCheckForFire(ATTRACT_DELAY);
	}
}

void ShowAttractScreen(void) {
	ClearTextScreen(BLACK);
	ShowInformation();
	FrameSync();

	WaitForAttractInput();
}