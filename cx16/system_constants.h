#ifndef SYSTEM_CONSTANTS_H_
#define SYSTEM_CONSTANTS_H_

// VERA
// Layers
#define LAYER_0             0b00000001
#define LAYER_1             0b00000010
#define TEXT_LAYER          layer1
#define TILE_LAYER          layer0
#define AUTO_INCREMENT		0b10000

// Colors
#define COLOR(fore, back)	((back << 4) | fore) 
#define	TRANSPARENT			0

// Tile map size
#define TILE_HEIGHT		64
#define TILE_WIDTH		64

// Characters
#define SPACE_CHAR          0x20

#endif // SYSTEM_CONSTANTS_H_