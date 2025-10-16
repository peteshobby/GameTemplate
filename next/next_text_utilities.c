#include "constants.h"
#include "text_utilities.h"
#include <stdlib.h>
#include <string.h>

void DisplayText(uint8_t row, uint8_t column, char* text, uint8_t color) {
   	for (int i = 0; i < strlen(text); ++i) {
      DisplayChar(row, column + i, text[i], color);
	} 
}

