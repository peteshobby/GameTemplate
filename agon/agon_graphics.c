#include "graphics.h"
#include "frame_control.h"
#include <agon/vdp_vdu.h>
#include <stdbool.h>



void ClearTextScreen(uint8_t backgroundColor) {
	vdp_set_text_colour(backgroundColor + 127);
	vdp_clear_screen();
	FrameSync();
	vdp_clear_screen();
}


