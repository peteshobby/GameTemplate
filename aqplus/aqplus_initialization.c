#include "initialization.h"
#include "graphics.h"
#include "system_constants.h"
#include <aqplus.h>

#define TURBO_MODE		0b00000100
#define UNLIMITED_MODE	0b00001000


void EnableTurboMode(void) {
    IO_SYSCTRL |= TURBO_MODE;
}

// This function:
// 1. sets the layer priorities
// 2. remaps the border character
void InitializeGraphics(void) {
	IO_VCTRL =  VCTRL_MODE_TILE | 
				VCTRL_TEXT_PRIO |
				VCTRL_SPR_EN | 
				VCTRL_TEXT_EN | 
				VCTRL_REMAP_BORDER_CH;
}

void InitializeSystem() {
//	EnableTurboMode();
	InitializeGraphics();
	ClearTextScreen(0);
}