#ifndef SYSTEM_CONSTANTS_H_
#define SYSTEM_CONSTANTS_H_

// Graphics
#define COLOR(fore, back)             ((fore << 4) | back)

// Screen
#define SCREEN_WIDTH		40
#define SCREEN_HEIGHT		25

// Text RAM 
#define CHARRAM             0x3000
#define COLRRAM             0x3400
#define BORDER_COLOR        0x37FF
#define CHARRAM_SIZE        0x0400

#endif // SYSTEM_CONSTANTS_H_
