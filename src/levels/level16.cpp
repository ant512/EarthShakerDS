#include "level16.h"
#include "bitmapserver.h"
#include "blocktype.h"

const static u8 level16Data[600] = {
	12,12,12,14,14,2 ,14,14,5 ,5 ,5 ,13,13,13,13,10,13,4 ,13,4 ,4 ,4 ,4 ,4 ,4 ,5 ,12,14,13,13,
	12,2 ,14,14,14,14,13,13,8 ,8 ,13,13,2 ,13,2 ,3 ,13,14,13,14,12,14,12,14,12,14,3 ,14,2 ,13,
	2 ,14,14,13,8 ,8 ,13,12,2 ,12,13,14,14,13,14,12,0 ,14,13,13,8 ,13,8 ,13,8 ,13,14,13,14,13,
	12,14,13,12,12,12,13,14,12,14,14,12,13,13,14,12,12,14,14,13,2 ,13,2 ,13,2 ,13,4 ,2 ,2 ,2 ,
	14,14,13,13,8 ,8 ,13,8 ,8 ,8 ,8 ,13,13,3 ,13,12,14,14,14,13,2 ,13,2 ,13,2 ,13,14,14,13,14,
	14,13,13,13,14,14,13,13,12,13,13,13,3 ,3 ,2 ,13,13,14,14,13,13,13,13,13,13,13,14,3 ,14,14,
	14,13,3 ,3 ,14,14,13,13,14,14,13,13,3 ,3 ,12,13,13,13,14,14,14,14,13,13,14,3 ,3 ,3 ,14,2 ,
	14,13,4 ,0 ,3 ,4 ,13,13,2 ,14,14,4 ,2 ,14,14,14,14,14,14,13,2 ,14,14,14,14,3 ,14,3 ,14,13,
	12,13,13,4 ,14,13,13,13,13,13,13,13,13,14,14,13,13,14,14,13,2 ,13,12,14,14,14,14,13,13,13,
	12,13,13,13,4 ,14,3 ,14,4 ,0 ,14,14,3 ,14,14,14,13,13,9 ,13,13,13,2 ,13,12,13,14,13,13,2 ,
	12,13,13,13,14,13,13,13,13,13,14,2 ,13,14,13,8 ,13,2 ,0 ,2 ,2 ,13,10,13,2 ,13,14,2 ,13,2 ,
	12,2 ,13,13,14,14,13,13,2 ,13,3 ,2 ,13,14,13,14,14,14,13,13,14,13,2 ,14,10,13,14,2 ,13,12,
	2 ,12,13,2 ,13,14,13,2 ,2 ,13,10,13,13,14,3 ,14,13,13,13,2 ,13,13,14,14,14,14,14,2 ,12,12,
	13,12,13,2 ,13,12,13,12,13,13,13,13,14,14,3 ,14,2 ,13,13,12,13,13,2 ,2 ,13,13,2 ,2 ,2 ,13,
	13,12,12,12,12,12,12,12,12,13,13,13,14,3 ,14,3 ,13,12,12,12,12,13,13,12,12,13,13,12,12,13,
	13,13,12,12,12,12,12,12,12,12,12,13,14,13,14,13,14,12,12,12,12,12,12,12,12,12,12,12,13,13,
	13,13,13,8 ,13,8 ,13,8 ,13,8 ,13,13,14,14,13,14,14,13,8 ,13,8 ,13,8 ,13,8 ,13,8 ,13,13,13,
	13,13,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,13,13,14,13,14,13,13,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,13,13,
	13,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,13,14,13,14,13,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,13,
	13,4 ,4 ,13,4 ,13,4 ,13,4 ,13,4 ,4 ,13,1 ,13,11,13,4 ,13,4 ,13,4 ,13,4 ,13,4 ,13,4 ,4 ,13
};

Level16::Level16() : ImmutableLevelDefinition(30,
								   20,
								   16,
								   "Hair Brained Surgery",
								   level16Data,
								   BOULDER_TYPE_BLUE,
								   WALL_TYPE_BRAIN,
								   SOIL_TYPE_GREEN,
								   DOOR_TYPE_BLUE) {
}

