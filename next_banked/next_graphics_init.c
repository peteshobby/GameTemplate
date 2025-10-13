#include "next_graphics_init.h"
#include "system_constants.h"
#include <arch/zxn.h>


#define RTM_28MHZ	3

void EnableTurboMode(void) {
   //  ZXN_NEXTREGA(REG_TURBO_MODE, RTM_3MHZ);
	ZXN_NEXTREGA(REG_TURBO_MODE, RTM_28MHZ);
}

// Sets layer order to layer 2 on top, then sprites, then tilemap
void SetLayerPriority(void) {
	ZXN_NEXTREGA(REG_VIDEO_PARAM, 
		RSLS_LAYER_PRIORITY_LSU | 
		RSLS_SPRITES_OVER_BORDER |
		RSLS_SPRITES_VISIBLE);
}





void EnableLayer2(void) {
// Enable layer 2 
    IO_LAYER_2_CONFIG = IL2C_SHOW_LAYER_2 ;
    ZXN_NEXTREGA(REG_LAYER_2_CONTROL, LAYER_2_320x256x8);

// set Layer 2 bank to 9 (page 18)
    ZXN_NEXTREGA(REG_LAYER_2_RAM_BANK, LAYER_2_START_BANK);

// Set layer 2 clip region to the whole of the visible screen
    ZXN_NEXTREGA(REG_CLIP_WINDOW_CONTROL, RCWC_RESET_LAYER_2_CLIP_INDEX);
    ZXN_NEXTREGA(REG_CLIP_WINDOW_LAYER_2, 0);
    ZXN_NEXTREGA(REG_CLIP_WINDOW_LAYER_2, LAYER_2_CLIP_WIDTH);
    ZXN_NEXTREGA(REG_CLIP_WINDOW_LAYER_2, 0);
    ZXN_NEXTREGA(REG_CLIP_WINDOW_LAYER_2, LAYER_2_CLIP_HEIGHT);
}

// Sets the 
void SetGlobalTransparency(void) {
	ZXN_NEXTREGA(REG_GLOBAL_TRANSPARENCY_COLOR, GLOBAL_TRANSPARENT);
}
// Set layer order to tilmap, sprites, layer2 text
// enable layer2
void InitializeGraphics(void) {
    SetLayerPriority();
    EnableLayer2();
	SetGlobalTransparency();
}
