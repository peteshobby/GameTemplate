#ifndef SYSTEM_CONSTANTS_H_
#define SYSTEM_CONSTANTS_H_

// Graphics
#define COLOR(fore, back)             ((fore << 4) | back)

// Colors
#define ORANGE                  0x01
#define BROWN                   0x02
#define INDIGO                  0x03
#define PURPLE                  0x04

#define VIOLET                  0x05
#define LIGHT_GREEN             0x06
#define GREY                    0x07

#define BLACK                   0x08
#define BLUE                    0x09
#define RED                     0x0A
#define MAGENTA                 0x0B
#define GREEN                   0x0C
#define CYAN                    0x0D
#define YELLOW                  0x0E
#define WHITE                   0x0F

// Text RAM 
#define CHARRAM             0x3000
#define COLRRAM             0x3400
#define BORDER_COLOR        0x37FF
#define CHARRAM_SIZE        0x0400

// Characters
#define SPACE_CHAR          0x20

#endif // SYSTEM_CONSTANTS_H_
