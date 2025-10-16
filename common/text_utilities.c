#include "system_constants.h"
#include "text_utilities.h"

#include <string.h>
#include <stdbool.h>

#define MAX_TEXT_NUMBER_LENGTH   20


void DisplaySigned8Bit(uint8_t row, uint8_t column, int8_t number, uint8_t color, char padding, uint8_t length) {
	char buffer[MAX_TEXT_NUMBER_LENGTH + 1];
  	uint8_t actualLength = length > MAX_TEXT_NUMBER_LENGTH ? MAX_TEXT_NUMBER_LENGTH : length;

	PaddedItoa(number, buffer, 10, actualLength, padding);
	DisplayText(row, column, buffer, color);
}

void DisplaySigned16Bit(uint8_t row, uint8_t column, int16_t number, uint8_t color, char padding, uint8_t length) {
	char buffer[MAX_TEXT_NUMBER_LENGTH + 1];
  	uint8_t actualLength = length > MAX_TEXT_NUMBER_LENGTH ? MAX_TEXT_NUMBER_LENGTH : length;

	PaddedItoa(number, buffer, 10, actualLength, padding);
	DisplayText(row, column, buffer, color);
}

void DisplayCenteredText(uint8_t row, const char* text, uint8_t color) {
    uint8_t centeredColumn = SCREEN_WIDTH / 2 - strlen(text) / 2;

    DisplayText(row, centeredColumn, text, color);
}

void ReverseString(char str[]) {
	int len = strlen(str);
	int i;
	char temp;
	
	for (i = 0; i < len/2; i++)
	{
		temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	}
  str[len] = 0;
}

void PaddedItoa(int16_t num, char *buffer, int8_t radix, int fixedLength, char padding) {
	int16_t current = num;
	int index = 0;
 	bool negative = false;

	if(current == 0) {
		buffer[index++] = '0';
	} else {
		if(current < 0) {
		negative = true;
		current = -current;
		fixedLength -= 1;
		}
		while(current != 0) {
			int16_t digit = current % radix;
			current /= radix;
			buffer[index++] = '0' + digit;
		}
	}

	while(index < fixedLength) {
		buffer[index++] = padding;
	}

	if (negative)
		buffer[index++] = '-';

	buffer[index] = 0;

	ReverseString(buffer);
}