#include "initialization.h"
#include "system_constants.h"
#include "graphics.h"
#include "next_graphics_init.h"

// Move the stack so I can use bank 3
#pragma output REGISTER_SP           = 0xBFFF
#pragma output CLIB_MALLOC_HEAP_SIZE = 0

void InitializeSystem(void) {
	EnableTurboMode();
	InitializeGraphics();
	ClearTextScreen(TRANSPARENT);
}