#include "level0.h"
#include "bitmapserver.h"
#include "spectrumcolours.h"

const static u8 level0Data[600] = {
	18,18,18,18,13,32,32,32,32,32,17,32,32,35,35,35,32,32,17,17,32,32,32,32,18,18,18,18,18,18,
	18,18,32,32,32,32,32,32,32,32,32,32,32,35,35,35,32,32,32,32,17,32,32,2, 18,2, 2, 2, 18,18,
	18,2, 32,32,32,32,32,17,32,32,32,32,32,17,35,17,32,32,32,32,17,32,32,32,32,2, 2, 2, 2, 18,
	2, 32,32,32,2, 32,32,17,32,32,2, 32,32,35,35,35,32,2, 32,32,32,32,32,32,32,32,32,2, 18,18,
	32,32,32,32,32,32,32,32,32,32,10,32,32,35,35,5, 32,32,32,32,32,32,3, 32,32,32,32,32,32,32,
	32,32,32,2, 32,32,32,32,32,32,32,17,32,35,35,18,32,32,32,32,2, 32,32,32,32,2, 32,32,32,32,
	32,32,32,32,32,32,32,32,5, 32,32,32,32,35,35,17,32,32,32,32,32,32,32,5, 32,17,32,32,32,17,
	32,32,32,32,32,17,17,32,32,10,32,32,2, 35,35,35,32,2, 32,32,32,32,32,32,32,32,32,32,32,32,
	2, 32,32,32,32,17,32,32,3, 32,32,32,32,35,35,35,7 ,32,32,17,32,32,2, 32,32,2, 32,32,32,32,
	18,32,32,32,32,32,32,32,32,32,32,32,32,17,35,1, 32,32,32,32,32,32,32,8 ,32,17,32,32,2, 17,
	18,32,32,32,32,32,32,2, 32,32,2, 32,32,35,35,35,32,32,32,32,32,32,32,8 ,32,32,32,32,17,17,
	2, 32,32,2, 32,32,32,32,32,32,32,32,32,35,35,35,32,3, 32,32,32,32,17,8 ,32,9 ,32,32,17,17,
	18,32,32,32,32,17,32,32,32,32,17,17,32,35,2, 35,32,32,32,2, 32,32,32,8 ,32,32,32,32,18,18,
	18,18,32,32,32,32,32,32,32,32,17,32,32,35,35,35,32,32,32,32,32,32,32,32,32,17,32,32,32,18,
	18,18,32,32,32,32,32,32,32,32,32,32,32,35,3, 35,32,32,32,2, 32,32,32,32,32,32,32,32,17,18,
	18,18,32,2, 32,32,32,32,32,32,2, 2, 2, 35,35,35,32,32,32,32,32,17,32,32,32,32,32,32,17,18,
	18,18,18,32,32,32,32,32,32,32,32,32,32,0, 17,32,32,32,32,32,32,32,32,32,32,32,32,17,17,18,
	18,18,18,18,32,32,32,2, 32,32,32,32,32,32,18,32,32,32,32,32,32,32,32,17,32,32,17,17,17,18,
	18,18,18,18,18,0, 18,18,18,0, 18,18,18,2, 18,18,18,0, 18,18,18,0, 18,17,17,17,17,17,18,18,
	18,18,18,18,18,4, 18,18,18,4, 18,18,18,4, 18,18,18,4, 18,18,18,4, 18,18,18,18,18,18,18,18
};

Level0::Level0() : LevelDefinition(30, 20, 0, "Testing Ground", level0Data, COLOUR_YELLOW, COLOUR_RED, COLOUR_BLUE) {
}
