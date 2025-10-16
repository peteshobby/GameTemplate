#include "system_constants.h"
#include "text_utilities.h"

#include <string.h>
#include<stdlib.h>


void DisplayChar(uint8_t row, uint8_t column, char ch, uint8_t color) {
    uint16_t offset = (row * SCREEN_WIDTH) + column;
	uint8_t *char_addr = (uint8_t *)(CHARRAM + offset);
    uint8_t *color_addr = (uint8_t *)(COLRRAM + offset);

    *char_addr = ch;
    *color_addr = color;
}

void DisplayText(uint8_t row, uint8_t column, const char* text, uint8_t color) {
    uint16_t offset = (row * SCREEN_WIDTH) + column;
	uint8_t *char_addr = (uint8_t *)(CHARRAM + offset);
    uint8_t *color_addr = (uint8_t *)(COLRRAM + offset);

	while(*(text)) {
        *char_addr++ = *(text++);
        *color_addr++ = color;
    }
}







