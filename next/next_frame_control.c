#include "frame_control.h"
#include <stdint.h>


void WaitForFrames(uint8_t count) {
	uint8_t i;

	for (i = 0; i < count; ++i)
		FrameSync();
}

