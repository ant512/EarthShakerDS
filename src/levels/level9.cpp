#include "level9.h"
#include "bitmapserver.h"
#include "blocktype.h"

const static u8 level9Data[600] = {
	13,13,13,2 ,14,13,13,13,12,13,13,13,13,12,13,14,12,2 ,2 ,2 ,13,2 ,13,2 ,13,13,13,12,12,12,
	13,13,12,2 ,14,14,13,13,2 ,13,13,12,13,12,13,14,14,13,13,13,13,12,13,12,14,14,13,13,12,12,
	13,12,13,2 ,14,14,14,13,2 ,13,14,14,13,2 ,13,14,14,13,14,14,14,12,0 ,12,0 ,0 ,0 ,13,13,13,
	13,12,12,2 ,13,13,12,14,14,14,12,13,13,12,13,14,13,13,14,14,12,2 ,12,2 ,12,0 ,14,14,13,12,
	13,13,12,2 ,13,13,12,12,14,12,12,13,13,12,14,14,13,0 ,14,12,12,12,12,12,12,14,14,14,13,13,
	13,13,13,2 ,13,13,8 ,8 ,8 ,8 ,8 ,13,13,2 ,13,14,0 ,0 ,13,12,12,13,13,12,12,12,12,14,14,13,
	13,13,12,2 ,13,13,0 ,3 ,3 ,3 ,0 ,13,13,12,13,14,0 ,13,13,12,12,12,12,12,12,12,12,14,14,2 ,
	13,12,2 ,2 ,13,3 ,3 ,14,8 ,14,3 ,3 ,13,12,14,14,0 ,13,12,12,14,13,12,13,12,13,2 ,2 ,14,2 ,
	13,2 ,2 ,14,13,3 ,13,8 ,8 ,8 ,13,3 ,13,2 ,13,14,14,13,12,12,12,12,12,12,12,14,2 ,14,14,2 ,
	13,2 ,14,13,13,12,8 ,13,4 ,13,8 ,12,13,12,13,14,13,13,12,12,12,12,12,14,12,12,2 ,14,14,2 ,
	13,14,14,13,13,12,8 ,4 ,2 ,4 ,8 ,12,13,12,14,14,13,13,10,12,12,12,14,14,12,12,12,2 ,14,2 ,
	14,14,2 ,13,13,12,8 ,13,4 ,13,8 ,12,13,2 ,13,14,14,14,14,14,12,12,14,12,12,2 ,2 ,2 ,2 ,2 ,
	7 ,14,14,14,13,12,13,8 ,8 ,8 ,13,12,13,12,13,14,14,13,14,14,12,2 ,14,14,14,2 ,2 ,2 ,2 ,2 ,
	13,13,14,13,13,12,14,14,8 ,14,14,12,13,12,14,14,14,13,13,13,13,13,13,13,13,13,13,13,13,13,
	13,13,14,13,13,13,14,14,14,14,14,13,13,12,13,14,14,13,12,12,12,12,12,12,12,12,12,12,14,14,
	14,3 ,3 ,13,13,13,13,0 ,13,0 ,13,13,13,12,13,14,14,13,14,14,14,14,14,14,14,14,14,14,13,14,
	13,14,14,13,13,13,0 ,4 ,4 ,4 ,14,13,13,14,14,14,13,13,1 ,13,13,13,13,13,13,13,13,13,13,14,
	13,14,13,13,13,13,4 ,13,3 ,13,4 ,13,13,14,13,14,13,13,13,13,13,13,13,2 ,13,2 ,13,2 ,13,14,
	13,14,14,14,11,13,13,2 ,2 ,2 ,13,13,13,2 ,14,14,12,12,2 ,13,14,14,12,12,12,12,12,12,12,14,
	13,13,13,13,13,13,10,2 ,9 ,2 ,2 ,13,13,13,13,14,2 ,14,14,14,14,13,14,14,2 ,14,14,14,14,14
};

Level9::Level9() : ImmutableLevelDefinition(30,
								   20,
								   9,
								   "Internal Reactor Inc",
								   level9Data,
								   BOULDER_TYPE_CYAN,
								   WALL_TYPE_SAND,
								   SOIL_TYPE_GREEN,
								   DOOR_TYPE_MAGENTA) {
}
