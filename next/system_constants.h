#ifndef SYSTEM_CONSTANTS_H_
#define SYSTEM_CONSTANTS_H_

// Layer 2
#define LAYER_2_START_BANK		9
#define REG_LAYER_2_CONTROL		0x70
#define LAYER_2_320x256x8		0x10
#define LAYER_2_CLIP_HEIGHT		255
#define LAYER_2_CLIP_WIDTH		159

#define GLOBAL_TRANSPARENT		0xC3

// Color
#define COLOR(fore, back)       (((back << 4) | fore) & 0xFF) 

// Banking
#define BANK_3_START_ADDRESS	0xC000
#define BANK_LENGTH				0x4000

// Screen
#define SCREEN_WIDTH        	40
#define SCREEN_HEIGHT       	32

#endif // SYSTEM_CONSTANTS_H_