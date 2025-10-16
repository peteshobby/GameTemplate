#ifndef SYSTEM_CONSTANTS_H_
#define SYSTEM_CONSTANTS_H_

// VERA
// Layers
#define LAYER_0             0b00000001
#define LAYER_1             0b00000010
#define TEXT_LAYER          layer1
#define TILE_LAYER          layer0

// Colors
#define COLOR(fore, back)	((back << 4) | fore) 

// Screen
#define SCREEN_WIDTH		40
#define SCREEN_HEIGHT		30

// Tile map size
#define MAX_TILE_ROW    64
#define MAX_TILE_COLUMN 128 // Seems to be broken for text

#endif // SYSTEM_CONSTANTS_H_