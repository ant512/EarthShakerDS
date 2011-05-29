#include "level13.h"
#include "bitmapserver.h"
#include "blocktype.h"

const static u8 level13Data[600] = {
	13,12,12,15,15,2 ,15,15,15,15,15,15,15,2 ,15,15,15,15,15,2 ,15,15,15,15,15,12,12,15,15,13,
	13,12,15,15,15,15,15,15,12,15,15,15,15,15,15,15,15,12,15,15,15,15,2 ,15,15,15,12,15,15,12,
	12,12,15,15,15,15,15,15,15,15,15,15,15,15,12,15,15,15,15,15,15,15,15,15,15,15,15,15,15,13,
	12,15,15,15,12,15,15,2 ,15,15,2 ,15,15,15,15,15,15,15,15,15,15,2 ,15,15,2 ,15,15,2 ,15,13,
	13,2 ,15,15,15,15,15,15,15,15,15,12,12,15,15,15,12,15,15,12,15,15,15,12,15,15,15,15,15,13,
	13,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,12,12,
	13,2 ,15,12,15,2 ,15,15,12,15,15,15,15,15,15,15,15,15,15,15,15,15,12,15,15,15,15,15,15,12,
	13,15,15,15,15,15,15,15,13,4 ,4 ,15,0 ,15,15,12,15,15,15,4 ,4 ,13,15,15,15,2 ,15,15,15,13,
	13,15,1 ,15,15,12,15,15,13,13,13,4 ,4 ,13,15,13,4 ,4 ,4 ,13,13,13,15,15,15,15,15,15,15,13,
	12,15,15,15,15,15,15,15,15,13,13,13,13,13,15,13,13,13,13,13,13,15,15,15,15,12,15,15,15,13,
	12,15,15,15,2 ,15,15,15,2 ,15,15,15,12,13,15,13,15,15,15,15,12,15,2 ,15,15,15,15,15,2 ,13,
	12,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,13,
	12,12,15,15,15,15,12,12,12,15,15,15,2 ,15,2 ,15,15,15,15,2 ,15,15,15,15,15,15,15,2 ,15,13,
	13,12,15,12,15,15,15,15,12,12,15,15,15,15,15,15,12,15,15,15,15,15,15,12,15,15,15,15,15,12,
	13,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,12,12,
	13,15,15,15,2 ,15,15,15,15,2 ,15,15,12,15,2 ,15,15,15,15,15,12,15,15,15,15,15,15,15,12,13,
	13,13,15,15,15,15,15,12,15,15,15,15,15,15,15,15,12,15,15,15,15,15,2 ,15,15,15,15,12,12,13,
	13,13,13,13,15,15,15,15,15,15,15,15,15,12,15,15,15,15,15,15,15,15,15,15,15,15,12,12,13,13,
	13,13,13,11,15,15,15,15,15,15,15,2 ,15,15,15,15,2 ,15,15,15,15,15,15,15,15,12,13,13,13,13,
	13,13,13,13,13,13,12,12,13,4 ,4 ,13,4 ,4 ,13,4 ,4 ,13,4 ,4 ,13,12,13,13,13,13,13,13,13,13
};

Level13::Level13() : LevelDefinition(30,
								   20,
								   13,
								   "Wet Hell Soil",
								   level13Data,
								   BOULDER_TYPE_GREEN,
								   WALL_TYPE_SAND,
								   SOIL_TYPE_BLUE,
								   DOOR_TYPE_MAGENTA) {
}

