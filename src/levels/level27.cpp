#include "level27.h"
#include "bitmapserver.h"
#include "spectrumcolours.h"

const static u8 level27Data[600] = {
	17,17,21,21,17,21,17,21,17,21,2 ,17,17,21,21,0 ,17,2 ,32,17,17,32,32,32,17,0 ,21,21,21,2 ,
	17,21,21,2 ,17,21,17,21,17,21,17,21,17,21,17,17,17,32,32,32,32,32,21,21,32,32,17,21,17,17,
	21,21,21,17,17,2 ,17,21,7 ,21,17,17,17,17,17,17,32,0 ,0 ,0 ,0 ,32,21,21,21,32,32,21,17,17,
	21,17,21,17,2 ,17,2 ,2 ,17,21,21,17,21,17,17,17,21,0 ,0 ,0 ,21,2 ,21,21,21,17,32,21,17,17,
	21,32,32,17,17,17,17,17,17,11,21,17,17,17,17,21,2 ,17,0 ,21,21,21,21,21,17,17,32,17,17,21,
	21,32,21,17,17,17,17,17,17,21,21,21,17,17,21,32,2 ,21,21,21,2 ,21,21,21,17,32,32,2 ,17,21,
	21,32,21,17,17,17,17,17,17,21,21,21,21,17,0 ,32,21,21,17,17,17,21,21,2 ,32,0 ,32,21,17,21,
	21,32,21,32,32,32,32,32,32,32,17,0 ,21,32,32,21,21,2 ,32,17,17,17,21,32,0 ,0 ,21,21,21,21,
	21,32,21,32,32,32,32,32,32,21,32,21,21,32,21,21,2 ,21,17,32,17,17,21,0 ,0 ,0 ,21,17,17,21,
	21,32,21,1 ,32,32,2 ,2 ,32,21,32,32,32,32,21,17,17,32,32,2 ,17,32,21,0 ,0 ,21,21,2 ,2 ,21,
	2 ,32,21,32,32,32,32,2 ,2 ,21,21,0 ,21,32,21,2 ,32,17,17,32,32,32,21,0 ,0 ,21,2 ,17,32,21,
	32,21,21,21,21,21,21,21,21,21,21,2 ,0 ,32,21,21,17,17,2 ,17,32,32,21,32,21,21,2 ,32,32,17,
	32,21,21,32,32,32,32,32,32,32,32,32,21,32,32,21,2 ,17,17,32,32,0 ,0 ,32,32,21,2 ,2 ,32,2 ,
	32,21,32,2 ,21,21,21,21,21,21,21,21,21,32,32,21,21,17,32,32,0 ,0 ,21,0 ,21,21,21,32,32,17,
	32,21,32,21,21,17,32,17,32,17,32,21,32,32,32,17,21,21,21,32,0 ,0 ,21,0 ,0 ,21,21,32,32,2 ,
	32,21,32,32,21,2 ,21,2 ,21,2 ,21,21,32,32,32,32,32,21,2 ,32,0 ,0 ,21,21,0 ,21,2 ,32,2 ,2 ,
	32,21,2 ,32,21,17,21,17,21,17,21,2 ,32,32,32,32,32,21,21,32,0 ,0 ,0 ,21,0 ,21,2 ,2 ,32,21,
	32,21,21,32,32,32,32,32,32,32,21,32,32,32,32,32,32,2 ,21,0 ,0 ,0 ,0 ,21,0 ,21,32,32,21,21,
	32,32,21,21,21,21,21,21,21,0 ,21,21,32,17,32,17,32,21,21,17,0 ,0 ,0 ,21,0 ,0 ,2 ,21,21,17,
	0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,17,0 ,0 ,21,21,2 ,21,32,21,21,21,17,17,0 ,17,21,0 ,21,21,21,17,17
};

Level27::Level27() : LevelDefinition(30, 20, 27, "The Combination Lock", level27Data, COLOUR_CYAN, COLOUR_RED, COLOUR_YELLOW) {
}
