#include "initialization.h"
#include "agon_graphics_init.h"


#include <agon/vdp_vdu.h>
#include <agon/vdp_key.h>

// Not handling errors
void InitializeAgon(void) {
	vdp_vdu_init();
	vdp_key_init();
}

void InitializeSystem(void) {
	InitializeAgon();
	InitializeGraphics();
}