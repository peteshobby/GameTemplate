#include <cx16.h>
#include "system_constants.h"
#include "graphics.h"


// This function:
// Enables both graphics layers and configures them.
// Layer 0 is configured as the tile layer.
// Layer 1 is configured as the text layer.
// The display is scaled to give a resolution of 320 x 240.
void InitializeGraphics(void) {

	vera_layer_enable(LAYER_0 | LAYER_1);

// Scale to 320x240
    VERA.display.hscale = 64;
    VERA.display.vscale = 64;

	ClearTextScreen(TRANSPARENT);
}