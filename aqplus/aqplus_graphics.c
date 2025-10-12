#include "graphics.h"
#include "system_constants.h"

static uint8_t  *textRam     = (uint8_t *)  CHARRAM;
static uint8_t  *colorRam    = (uint8_t *)  COLRRAM;

#define CLRSCRN 	0x1E45
#define FILLSCRN	0x1e59

#define ARG_COLOR	0

void ClearScreen(uint8_t color) {
__asm
	push	af
	ld 		b, #SPACE_CHAR
	ld 		hl, #CHARRAM
	call 	FILLSCRN
	pop		af
	ld 		b, a
	call 	FILLSCRN
__endasm;
}

void SetBorder(uint8_t color) {
    uint8_t *borderColor = (uint8_t *)BORDER_COLOR;
    *borderColor = color;
}

// This function:
// Sets very character sell on the screen to the space character
// and sets its background to the color given in the parameter.
// It also sets the border to the same color.
void ClearTextScreen(uint8_t backgroundColor) {
	//     for (int i = 0; i < CHARRAM_SIZE; i++) {
    //     textRam[i] = SPACE_CHAR;
    //     colorRam[i] = backgroundColor;
    // }
	ClearScreen(COLOR(0, backgroundColor));
    SetBorder(backgroundColor);
}