#include "frame_control.h"
#include <agon/vdp_vdu.h>



void WaitForFrames(uint8_t count) {
	uint8_t i;

	for (i = 0; i < count; ++i)
		FrameSync();
}


// Wait for the vertical refresh
// Swap the display buffers if double buffered
void FrameSync(void) {
	putch(23);
	putch(0);
	putch(0xC3);
}