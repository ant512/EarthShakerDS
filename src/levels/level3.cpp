#include "level3.h"
#include "bitmapserver.h"
#include "blocktype.h"

const static u8 level3Data[600] = {
    12,12,13,13,13,13,13,13,14,14,12,12,12,12,14,14,14,14,14,14,2 ,14,12,12,12,13,13,13,13,13,
    12,13,13,2 ,2 ,12,14,0 ,14,14,12,2 ,14,2 ,14,14,0 ,14,14,14,14,14,14,14,12,12,14,13,11,13,
	13,13,2 ,2 ,12,12,14,2 ,0 ,14,2 ,14,14,14,14,14,0 ,14,14,0 ,14,14,14,14,14,14,14,12,2 ,13,
    13,12,12,12,12,14,14,14,0 ,14,14,14,0 ,14,1 ,14,12,14,14,12,14,14,0 ,14,0 ,14,14,14,12,13,
    13,12,12,14,14,0 ,0 ,14,0 ,14,14,14,12,14,14,14,14,0 ,14,14,14,14,0 ,14,12,14,14,0 ,14,13,
    12,12,14,14,14,0 ,0 ,14,12,14,14,14,14,14,2 ,14,14,0 ,14,12,14,0 ,2 ,14,12,14,14,0 ,14,12,
	12,14,0 ,14,14,12,0 ,14,14,14,14,14,14,14,14,14,0 ,0 ,14,14,14,12,14,14,14,0 ,14,0 ,14,12,
	12,14,0 ,14,0 ,14,0 ,14,12,14,14,14,0 ,14,2 ,14,12,2 ,14,14,14,14,0 ,14,0 ,2 ,14,12,14,12,
	12,14,12,14,0 ,14,12,14,2 ,14,14,0 ,12,13,13,13,14,13,0 ,14,14,0 ,0 ,14,12,14,14,14,14,12,
	14,14,14,14,0 ,0 ,14,0 ,14,14,14,12,13,13,6 ,5 ,2 ,13,2 ,14,14,0 ,0 ,14,14,14,14,14,14,2 ,
	14,14,5 ,14,0 ,2 ,14,2 ,14,14,14,14,13,13,2 ,13,13,13,12,0 ,14,12,2 ,0 ,0 ,14,14,14,14,12,
	14,14,14,14,12,14,14,14,14,0 ,14,12,12,13,13,13,13,12,14,2 ,14,14,14,0 ,0 ,14,14,14,0 ,13,
	13,14,14,14,14,14,0 ,0 ,14,12,14,14,14,12,14,12,12,12,14,14,14,0 ,14,0 ,12,12,14,14,12,13,
	13,14,14,14,0 ,14,2 ,2 ,14,14,0 ,14,14,14,12,2 ,14,2 ,0 ,14,14,0 ,14,0 ,14,14,14,14,14,13,
	13,14,14,14,12,14,14,12,14,0 ,0 ,14,14,0 ,12,2 ,12,12,2 ,14,14,12,12,0 ,14,14,14,0 ,12,13,
	13,13,14,14,14,14,14,12,14,0 ,14,14,14,12,2 ,14,14,14,14,14,0 ,14,14,0 ,14,0 ,0 ,12,14,13,
	13,13,13,14,0 ,14,14,14,14,0 ,14,14,14,2 ,14,14,14,12,14,14,0 ,14,14,0 ,14,2 ,2 ,12,14,13,
	13,12,13,13,0 ,14,5 ,14,14,12,0 ,14,0 ,14,0 ,14,14,14,14,14,12,14,14,12,14,12,2 ,13,13,13,
	13,2 ,6 ,2 ,2 ,14,14,14,14,14,12,14,0 ,0 ,12,14,14,0 ,0 ,14,14,14,13,13,13,13,13,13,12,13,
	13,13,13,13,13,13,13,13,14,14,14,14,2 ,2 ,14,14,14,2 ,2 ,14,14,14,14,14,2 ,2 ,14,6 ,2 ,12
};

Level3::Level3() : LevelDefinition(30,
								   20,
								   3,
								   "The Gravity Chamber",
								   level3Data,
								   BOULDER_TYPE_YELLOW,
								   WALL_TYPE_METAL,
								   SOIL_TYPE_BLUE,
								   DOOR_TYPE_RED) {
}
