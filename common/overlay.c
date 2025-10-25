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
 * @file  overlay.c
 * @brief Common text overlay functions.
 */

#include "overlay.h"
#include "constants.h"
#include "text_color.h"
#include "text_utilities.h"

const char *emptyLine = "                                        ";
void SetupOverlay(void) {
	//int row;

	DisplayText(0, 0, emptyLine, COLOR(WHITE, PURPLE));
	DisplayText(1, 0, emptyLine, COLOR(WHITE, PURPLE));
	DisplayCenteredText(0, "Text Overlay", COLOR(WHITE, PURPLE));

	DisplayText(SCREEN_HEIGHT - 1, 0, emptyLine, COLOR(WHITE, PURPLE));
	DisplayText(SCREEN_HEIGHT - 2, 0, emptyLine, COLOR(WHITE, PURPLE));

	// for (row = 0; row <= SCREEN_HEIGHT - 1 ; ++row) {
	// 	DisplayText(row, 0, "  ", COLOR(WHITE, PURPLE));
	// 	DisplayText(row, SCREEN_WIDTH - 2, "  ", COLOR(WHITE, PURPLE));
	// }
}

void UpdateOverlay(void) {
#ifdef DBLBUF
	SetupOverlay();
#endif // DBLBUF
}