#include "splashscreen.h"
#include "system_constants.h"
#include "frame_control.h"
#include "graphics.h"
#include <stdio.h>
#include <stdint.h>

#define MAX_COLOR		7
#define SPLASH_DELAY	50

void ShowSplashScreen(void) {
	uint8_t color;

	for (color = MAX_COLOR; color != 0; --color) {
		ClearTextScreen(color);
		WaitForFrames(SPLASH_DELAY);
	}
}