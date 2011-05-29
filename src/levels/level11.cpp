#include "level11.h"
#include "bitmapserver.h"
#include "blocktype.h"

const static u8 level11Data[600] = {
	12,12,13,13,13,13,13,13,10,12,0 ,12,14,14,14,2 ,14,6 ,13,13,13,13,13,13,13,13,3 ,12,12,12,
	3 ,13,13,13,10,13,13,13,13,14,14,14,14,12,12,14,12,14,2 ,14,14,12,13,13,13,13,13,13,3 ,12,
	12,13,13,0 ,14,12,13,13,13,13,13,14,12,12,14,12,12,12,14,12,14,14,2 ,12,13,13,13,13,13,3 ,
	13,13,6 ,2 ,14,14,0 ,13,13,13,13,13,13,13,13,13,13,13,12,12,12,2 ,2 ,2 ,12,13,13,12,13,3 ,
	13,2 ,12,12,14,0 ,12,12,13,13,13,13,12,12,12,13,13,13,13,13,13,12,12,2 ,2 ,13,13,13,13,13,
	13,13,13,12,14,12,13,13,13,13,12,12,2 ,14,12,12,2 ,13,13,13,13,13,12,12,2 ,12,13,13,13,13,
	13,12,13,14,0 ,12,13,13,13,12,12,14,12,14,14,14,12,12,13,13,12,13,12,12,14,12,13,12,13,13,
	13,13,13,4 ,0 ,14,13,13,13,14,12,14,14,14,14,3 ,14,12,13,13,13,13,13,12,14,12,13,13,13,13,
	13,13,13,0 ,12,0 ,13,13,14,14,14,14,13,8 ,13,14,14,12,14,13,13,13,13,12,0 ,12,13,13,12,13,
	12,13,13,0 ,14,4 ,13,13,2 ,3 ,14,14,8 ,11,8 ,14,14,14,14,13,13,12,13,14,0 ,14,13,13,13,13,
	13,13,13,4 ,0 ,12,0 ,13,14,14,14,14,13,8 ,13,14,3 ,14,14,13,13,13,13,0 ,0 ,0 ,13,13,13,13,
	13,13,13,12,4 ,14,4 ,13,13,14,14,14,14,14,14,14,14,14,13,13,2 ,12,12,0 ,0 ,0 ,12,12,2 ,13,
	13,13,13,13,12,13,12,13,13,4 ,14,14,14,10,14,14,14,4 ,13,13,14,12,14,0 ,0 ,0 ,14,12,13,13,
	13,13,13,13,12,0 ,12,12,13,13,4 ,4 ,14,14,14,4 ,4 ,13,13,13,13,12,0 ,0 ,3 ,0 ,14,12,13,13,
	13,1 ,2 ,13,13,12,14,12,12,13,13,13,4 ,9 ,4 ,13,13,13,2 ,13,13,14,14,0 ,0 ,0 ,0 ,14,13,13,
	13,13,14,12,13,12,14,14,12,12,14,13,13,13,13,13,14,14,2 ,13,13,13,0 ,0 ,0 ,0 ,0 ,13,13,13,
	12,14,14,14,13,13,14,14,12,12,12,14,14,14,14,14,2 ,14,14,14,4 ,13,0 ,0 ,0 ,0 ,0 ,13,13,3 ,
	2 ,14,12,14,13,13,13,2 ,14,14,14,3 ,14,12,12,14,2 ,2 ,14,13,13,13,13,0 ,0 ,0 ,13,13,13,3 ,
	13,6 ,10,13,13,12,13,13,13,14,14,14,12,12,12,14,14,14,14,4 ,6 ,10,13,4 ,4 ,4 ,13,13,3 ,3 ,
	13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,10,13,13,3 ,12,12
};

Level11::Level11() : LevelDefinition(30,
								   20,
								   11,
								   "Graviton Shells",
								   level11Data,
								   BOULDER_TYPE_RED,
								   WALL_TYPE_METAL,
								   SOIL_TYPE_MAGENTA,
								   DOOR_TYPE_BLUE) {
}