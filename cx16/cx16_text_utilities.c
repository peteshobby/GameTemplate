#include "constants.h"
#include "text_utilities.h"
#include <stdlib.h>
#include <string.h>

#include <cx16.h>

// Need ascii_charmap.h to map character codes to standard ascii.
#include <ascii_charmap.h>

void DisplayText(uint8_t row, uint8_t column, const char* text, uint8_t color) {
	uint32_t offset = ((row * MAX_TILE_COLUMN) + column) * 2;
	uint32_t mapBaseAddr = 0x1B000 + offset;

    VERA.address = mapBaseAddr;
    VERA.address_hi = mapBaseAddr >> 16;
	VERA.address_hi |= VERA_INC_1;

	while(*(text)) {
		uint8_t ch = *(text++);

		VERA.data0 = ch;
		VERA.data0 = color; 
    }
}    

void DisplayChar(uint8_t row, uint8_t column, char ch, uint8_t color) {
	uint32_t offset = ((row * MAX_TILE_COLUMN) + column) * 2;
	uint32_t mapBaseAddr = 0x1B000 + offset;

    VERA.address = mapBaseAddr;
    VERA.address_hi = mapBaseAddr>>16;
	VERA.address_hi |= VERA_INC_1;

	VERA.data0 = ch;
	VERA.data0 = color;
}