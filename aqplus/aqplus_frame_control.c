#include "frame_control.h"

#include <aqplus.h>

void WaitForFrames(uint8_t count) {
	uint8_t i;

	for (i = 0; i < count; ++i)
		FrameSync();
}


// Wait for the vertical refresh
void FrameSync(void) {
	video_wait_eof();
}