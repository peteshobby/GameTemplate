#ifndef TEXT_UTILITIES_H_
#define TEXT_UTILITIES_H_

#include <stdint.h>
#include <stdlib.h>

void DisplayText(uint8_t row, uint8_t column, const char* text, uint8_t color);
void DisplayCenteredText(uint8_t row, const char* text, uint8_t color);
void DisplayChar(uint8_t row, uint8_t column, char ch, uint8_t color);
void DisplaySigned8Bit(uint8_t row, uint8_t column, int8_t number, uint8_t color, char padding, uint8_t length);
void DisplaySigned16Bit(uint8_t row, uint8_t column, int16_t number, uint8_t color, char padding, uint8_t length);

// Support functions
void PaddedItoa(int16_t num, char *buffer, int8_t radix, int fixedLength, char padding);
void ReverseString(char str[]);

#endif // TEXT_UTILITIES_H_