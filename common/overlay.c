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

#ifdef AGON
#define OVERLAY_LINE_0	(SCREEN_HEIGHT - 4)
#define OVERLAY_LINE_1 (OVERLAY_LINE_0 + 1)
#define OVERLAY_LINE_2 (OVERLAY_LINE_1 + 1)
#define OVERLAY_LINE_3 (OVERLAY_LINE_2 + 1)
#else
#define OVERLAY_LINE_0	0
#define OVERLAY_LINE_1 (OVERLAY_LINE_0 + 1)
#define OVERLAY_LINE_2 (SCREEN_HEIGHT - 2)
#define OVERLAY_LINE_3 (SCREEN_HEIGHT - 1)
#endif // AGON

const char *emptyLine = "                                        ";
void SetupOverlay(void) {

	DisplayText(OVERLAY_LINE_0, 0, emptyLine, COLOR(WHITE, PURPLE));
	DisplayCenteredText(OVERLAY_LINE_0, "Game Template", COLOR(WHITE, PURPLE));
	DisplayText(OVERLAY_LINE_1, 0, emptyLine, COLOR(WHITE, PURPLE));
	
	DisplayText(OVERLAY_LINE_2, 0, emptyLine, COLOR(WHITE, PURPLE));
	DisplayText(OVERLAY_LINE_3, 0, emptyLine, COLOR(WHITE, PURPLE));

#ifdef AGON
	DisplayText(OVERLAY_LINE_0 - 1, 0, emptyLine, COLOR(WHITE, PURPLE));
#endif // AGON

}

void UpdateOverlay(void) {
}