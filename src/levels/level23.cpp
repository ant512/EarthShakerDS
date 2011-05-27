#include "level23.h"
#include "bitmapserver.h"
#include "spectrumcolours.h"

const static u8 level23Data[600] = {
	17,17,2 ,18,17,2 ,17,17,2 ,2 ,17,2 ,18,17,18,17,18,32,32,2 ,32,32,32,32,32,32,32,32,32,17,
	10,17,32,18,2 ,2 ,17,17,2 ,17,17,2 ,18,17,18,2 ,18,32,32,17,32,32,18,18,18,18,18,18,32,17,
	32,32,32,18,17,2 ,17,17,17,17,32,2 ,18,2 ,18,17,18,18,32,2 ,32,18,17,2 ,17,18,18,32,32,17,
	32,17,32,8 ,32,3 ,2 ,17,32,32,32,32,8 ,17,32,17,17,18,18,17,18,17,32,17,32,32,18,32,17,17,
	17,32,32,18,2 ,2 ,2 ,17,17,32,32,18,18,17,18,18,17,2 ,18,17,18,2 ,17,32,32,2 ,18,32,17,17,
	2 ,4 ,32,18,32,17,2 ,17,17,32,32,18,18,17,18,32,18,17,18,17,18,17,32,32,32,18,18,32,17,17,
	4 ,32,32,18,32,32,32,32,17,32,17,2 ,18,2 ,18,32,18,17,18,17,18,18,32,32,32,18,32,32,17,17,
	32,3 ,32,18,32,0 ,0 ,0 ,17,2 ,32,32,18,17,32,32,32,17,32,17,32,18,32,32,18,18,32,18,17,17,
	18,10,18,18,0 ,0 ,18,18,18,18,18,32,32,17,18,18,18,17,18,17,18,32,32,32,18,32,32,18,18,18,
	32,0 ,32,18,0 ,0 ,18,2 ,2 ,2 ,18,18,18,17,18,32,32,32,0 ,17,0 ,0 ,32,32,18,0 ,18,18,18,5 ,
	32,0 ,32,18,0 ,18,18,18,18,32,32,32,32,2 ,32,32,18,0 ,18,17,18,0 ,18,18,0 ,0 ,18,17,18,5 ,
	32,0 ,32,18,0 ,18,2 ,17,18,32,18,18,18,4 ,18,18,18,4 ,18,17,18,9 ,18,2 ,0 ,0 ,18,2 ,18,5 ,
	32,32,32,18,0 ,18,18,17,18,0 ,18,32,32,17,32,32,18,3 ,18,17,18,13,18,2 ,18,0 ,18,17,17,17,
	18,18,32,18,0 ,18,18,17,18,32,32,32,18,17,18,32,32,32,18,17,18,18,18,2 ,0 ,2 ,18,17,2 ,17,
	18,32,32,18,0 ,18,2 ,17,18,32,18,18,18,17,18,18,18,32,32,32,32,32,18,18,3 ,18,18,17,17,18,
	18,32,17,18,8 ,18,18,17,18,32,32,32,18,17,18,32,32,32,18,4 ,18,32,32,32,2 ,18,18,17,18,10,
	32,32,17,18,32,32,18,17,18,18,18,32,32,17,32,32,18,18,18,18,18,18,18,32,17,32,32,32,32,32,
	17,32,32,18,32,32,32,17,18,18,18,32,18,17,18,18,32,32,32,32,32,32,18,32,32,32,18,4 ,18,17,
	32,32,32,32,32,32,32,32,32,18,2 ,2 ,18,0 ,18,32,1 ,32,18,18,18,32,32,32,32,32,18,18,18,18,
	2 ,4 ,32,2 ,4 ,4 ,4 ,4 ,4 ,18,2 ,2 ,18,4 ,32,32,32,32,32,32,3 ,32,18,32,2 ,32,2 ,32,32,10
};

Level23::Level23() : LevelDefinition(30, 20, 23, "Alarm Clock Works", level23Data, COLOUR_YELLOW, COLOUR_RED, COLOUR_BLUE) {
}
