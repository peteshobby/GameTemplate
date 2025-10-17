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
 * @file  cx16_frame_control.c
 * @brief Commander X16 wait for the next vertical sync.
 */

 #include "frame_control.h"
#include <cx16.h>
#include <time.h>
#include <stdbool.h>

void WaitForFrames(uint8_t count) {
	uint8_t i;

	for (i = 0; i < count; ++i)
		FrameSync();
}

static clock_t start; 
static clock_t next;

// This function:
// Waits for the system clock to change.
// The clock is incremented by the default interrupt handler every VSYNC.
void FrameSync(void) {
    start = clock();

    do {
        next = clock();
    } while (start == next);
}