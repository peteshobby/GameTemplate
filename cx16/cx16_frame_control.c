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