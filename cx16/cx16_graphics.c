#include "graphics.h"
#include "system_constants.h"
#include <cx16.h>

// This function:
// Sets the text layer to the space charater with the given
// background color.
// Note the text layer is 64x64 characters but only 40x30
// is visible on the screen.
void ClearTextScreen(uint8_t backgroundColor) {
    unsigned long mapBaseAddr = 0x1B000;
    uint8_t color = COLOR(1, backgroundColor);
    uint8_t count;

    VERA.address = mapBaseAddr;
    VERA.address_hi = mapBaseAddr>>16;
    VERA.control = 0b00000100;
    VERA.display.fxctrl = 0b01000000;
    VERA.control = 0b00001100;
    VERA.display.fxcachel = SPACE_CHAR;
    VERA.display.fxcachem = color;
    VERA.display.fxcacheh = SPACE_CHAR;
    VERA.display.fxcacheu = color;
    VERA.address_hi |= 0b00110000;

// Need to write 2048 times:
// 64x64 character positions = 4096
// 2 bytes per position = 8192
// divided by 4 bytes = 2048
// 2048 = 256 * 8 writes;
    count = 255;
    do {
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
        VERA.data0 = 0;
    } while (--count != 255);

    VERA.control = 0b00000100;
    VERA.display.fxctrl = 0b00000000;

}