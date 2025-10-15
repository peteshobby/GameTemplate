#include "agon_graphics_init.h"
#include "graphics.h"
#include <agon/vdp_vdu.h>
#include <stdbool.h>

void InitializeGraphics(void) {
vdp_mode(136);
	
// Hide cursor
	vdp_cursor_enable( false );

// Turn off screen scaling.
	vdp_logical_scr_dims(false);
	ClearTextScreen(0);
}