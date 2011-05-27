#include "level19.h"
#include "bitmapserver.h"
#include "spectrumcolours.h"

const static u8 level19Data[600] = {
	18,2 ,18,18,2 ,18,18,18,17,17,17,18,18,0 ,0 ,17,17,0 ,2 ,32,32,32,32,32,17,0 ,17,32,18,17,
	17,32,17,18,17,18,17,18,18,17,18,18,17,32,32,18,18,17,18,18,18,18,32,18,32,32,18,32,18,17,
	32,32,32,18,2 ,18,32,32,32,32,2 ,18,17,32,2 ,18,32,32,32,18,2 ,32,32,32,18,2 ,18,32,2 ,2 ,
	0 ,18,32,32,1 ,32,32,18,18,32,18,18,18,32,32,18,32,18,18,18,17,32,18,32,2 ,18,2 ,0 ,32,18,
	2 ,32,18,18,32,18,18,18,32,32,17,18,2 ,18,2 ,18,0 ,32,32,2 ,18,32,2 ,18,32,17,32,18,32,2 ,
	2 ,0 ,0 ,17,32,32,32,18,2 ,32,32,7 ,2 ,18,2 ,18,32,18,17,2 ,2 ,18,18,2 ,32,17,32,2 ,18,18,
	32,0 ,18,18,0 ,18,32,18,18,18,18,32,13,18,18,18,18,18,18,32,18,17,18,18,18,32,18,18,18,17,
	0 ,0 ,0 ,18,18,18,2 ,32,32,18,2 ,32,18,18,2 ,17,17,32,18,32,32,17,17,18,32,32,18,17,18,2 ,
	0 ,18,0 ,18,2 ,18,18,18,32,18,17,18,18,32,32,18,18,32,32,18,32,18,17,17,18,2 ,32,32,32,17,
	0 ,0 ,18,17,32,32,17,18,32,32,18,17,2 ,18,17,18,18,32,32,32,32,18,18,17,18,18,18,18,2 ,18,
	18,0 ,32,32,18,32,18,18,18,32,32,32,32,18,2 ,18,2 ,18,18,32,18,18,32,2 ,17,18,17,2 ,17,0 ,
	18,32,18,32,18,2 ,32,32,2 ,18,18,18,18,2 ,17,18,17,17,2 ,18,0 ,0 ,32,18,2 ,18,32,18,18,32,
	17,18,18,2 ,18,18,18,32,18,17,17,18,32,32,32,18,18,32,32,17,0 ,18,32,32,32,18,32,18,18,0 ,
	32,32,0 ,32,18,17,18,32,2 ,17,17,32,2 ,18,32,32,32,32,18,17,18,2 ,18,0 ,18,18,0 ,18,0 ,2 ,
	32,18,18,18,2 ,2 ,32,32,18,18,2 ,18,18,18,32,18,18,32,18,2 ,18,17,0 ,0 ,0 ,32,0 ,18,32,18,
	32,2 ,32,2 ,18,18,18,18,17,18,2 ,18,2 ,17,18,17,17,18,18,32,17,18,32,18,2 ,18,0 ,0 ,17,0 ,
	32,18,18,32,17,32,17,32,32,32,32,18,2 ,18,18,18,2 ,0 ,0 ,32,18,0 ,0 ,18,32,18,18,2 ,32,17,
	32,32,18,32,18,32,32,18,2 ,18,32,18,17,0 ,17,32,32,18,32,18,17,0 ,18,2 ,18,32,17,18,32,18,
	18,32,17,18,17,18,32,18,18,18,32,32,32,18,18,32,18,18,32,18,2 ,32,18,32,0 ,0 ,17,32,32,32,
	2 ,32,32,32,2 ,32,32,18,2 ,2 ,32,18,32,2 ,32,32,32,18,32,32,32,18,2 ,32,17,2 ,32,18,4 ,2
};

Level19::Level19() : LevelDefinition(30, 20, 19, "The Snare", level19Data, COLOUR_YELLOW, COLOUR_RED, COLOUR_MAGENTA) {
}
