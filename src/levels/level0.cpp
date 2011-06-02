#include "level0.h"
#include "bitmapserver.h"
#include "blocktype.h"

const static u8 level0Data[600] = {
	13,13,13,13,11,14,14,14,14,14,12,14,14,15,15,15,14,14,12,12,14,14,14,14,13,13,13,13,13,13,
	13,13,14,14,14,14,14,14,14,14,14,14,14,15,15,15,14,14,14,14,12,14,14,2, 13,2, 2, 2, 13,13,
	13,2, 14,14,14,14,14,12,14,14,14,14,14,12,15,12,14,14,14,14,12,14,14,14,14,2, 2, 2, 2, 13,
	2, 14,14,14,2, 14,14,12,14,14,2, 14,14,15,15,15,14,2, 14,14,14,14,14,14,14,14,14,2, 13,13,
	14,14,14,14,14,14,14,14,14,14,10,14,14,15,15,5, 14,14,14,14,14,14,3, 14,14,14,14,14,14,14,
	14,14,14,2, 14,14,14,14,14,14,14,12,14,15,15,13,14,14,14,14,2, 14,14,14,14,2, 14,14,14,14,
	14,14,14,14,14,14,14,14,5, 14,14,14,14,15,15,12,14,14,14,14,14,14,14,5, 14,12,14,14,14,12,
	14,14,14,14,14,12,12,14,14,10,14,14,2, 15,15,15,14,2, 14,14,14,14,14,14,14,14,14,14,14,14,
	2, 14,14,14,14,12,14,14,3, 14,14,14,14,15,15,15,7 ,14,14,12,14,14,2, 14,14,2, 14,14,14,14,
	13,14,14,14,14,14,14,14,14,14,14,14,14,12,15,1, 14,14,14,14,14,14,14,8 ,14,12,14,14,2, 12,
	13,14,14,14,14,14,14,2, 14,14,2, 14,14,15,15,15,14,14,14,14,14,14,14,8 ,14,14,14,14,12,12,
	2, 14,14,2, 14,14,14,14,14,14,14,14,14,15,15,15,14,3, 14,14,14,14,12,8 ,14,9 ,14,14,12,12,
	13,14,14,14,14,12,14,14,14,14,12,12,14,15,2, 15,14,14,14,2, 14,14,14,8 ,14,14,14,14,13,13,
	13,13,14,14,14,14,14,14,14,14,12,14,14,15,15,15,14,14,14,14,14,14,14,14,14,12,14,14,14,13,
	13,13,14,14,14,14,14,14,14,14,14,14,14,15,3, 15,14,14,14,2, 14,14,14,14,14,14,14,14,12,13,
	13,13,14,2, 14,14,14,14,14,14,2, 2, 2, 15,15,15,14,14,14,14,14,12,14,14,14,14,14,14,12,13,
	13,13,13,14,14,14,14,14,14,14,14,14,14,0, 12,14,14,14,14,14,14,14,14,14,14,14,14,12,12,13,
	13,13,13,13,14,14,14,2, 14,14,14,14,14,14,13,14,14,14,14,14,14,14,14,12,14,14,12,12,12,13,
	13,13,13,13,13,0, 13,13,13,0, 13,13,13,2, 13,13,13,0, 13,13,13,0, 13,12,12,12,12,12,13,13,
	13,13,13,13,13,4, 13,13,13,4, 13,13,13,4, 13,13,13,4, 13,13,13,4, 13,13,13,13,13,13,13,13
};

Level0::Level0() : ImmutableLevelDefinition(30,
								   20,
								   0,
								   "Testing Ground",
								   level0Data,
								   BOULDER_TYPE_YELLOW,
								   WALL_TYPE_BRICK_RED,
								   SOIL_TYPE_BLUE,
								   DOOR_TYPE_GREEN) {
}
