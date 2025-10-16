#include "constants.h"
#include "text_utilities.h"

#include <agon/vdp_vdu.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>

uint8_t agonColors[16] = { 0, 58, 42, 35, 47, 39, 24, 7, 0, 12, 9, 13, 10, 14, 11, 15};

void DisplayChar(uint8_t row, uint8_t column, char ch, uint8_t color) {
	vdp_set_text_colour(agonColors[color & 0x0F]);
	vdp_set_text_colour(128 + agonColors[color >> 4]);
	
	//vdp_cursor_tab(row, column);
	vdp_cursor_tab(column, row);
	putch(ch);
    
}


void DisplayText(uint8_t row, uint8_t column, const char* text, uint8_t color) {
	vdp_set_text_colour(agonColors[color & 0x0F]);
	vdp_set_text_colour(128 + agonColors[color >> 4]);
	
	//vdp_cursor_tab(row, column);
	vdp_cursor_tab(column, row);
	puts(text);
  //  putch(8);
}


