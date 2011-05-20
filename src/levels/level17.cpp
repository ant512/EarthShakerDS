#include "level17.h"
#include "bitmapserver.h"

const static u8 level17Data[600] = {
	21,21,21,21,35,10,35,35,35,21,21,21,21,21,21,21,21,17,17,35,21,21,21,21,21,21,21,21,21,21,
	21,21,35,2 ,35,35,35,2 ,35,17,35,21,21,21,21,35,35,2 ,35,6 ,35,35,35,17,35,35,2 ,21,21,21,
	21,35,35,35,35,6 ,35,35,35,17,35,35,21,21,35,2 ,35,35,35,35,35,2 ,35,17,35,35,35,35,21,21,
	21,35,35,2 ,17,35,35,21,21,21,21,21,21,2 ,35,35,35,35,35,21,21,35,35,35,2 ,17,17,35,10,21,
	21,35,35,2 ,17,35,21,21,21,21,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,21,21,21,21,17,35,35,35,17,35,21,21,
	21,21,2 ,17,17,35,35,21,21,2 ,2 ,2 ,35,2 ,35,17,17,17,21,21,21,21,35,2 ,35,2 ,35,35,21,21,
	21,10,2 ,17,17,35,35,8 ,35,35,2 ,21,21,2 ,5 ,35,2 ,17,17,21,21,21,21,35,35,35,10,21,21,21,
	21,21,21,21,21,21,35,8 ,35,35,21,21,2 ,21,21,35,35,2 ,17,17,8 ,21,21,21,21,21,21,21,21,21,
	21,21,21,4 ,21,21,21,8 ,35,5 ,2 ,21,2 ,17,21,21,35,35,17,17,8 ,0 ,0 ,35,35,2 ,35,35,21,21,
	21,21,4 ,35,10,21,21,8 ,35,3 ,2 ,21,21,17,21,35,5 ,35,17,17,8 ,0 ,35,0 ,10,35,35,35,35,21,
	21,21,4 ,35,4 ,21,21,21,21,35,35,35,21,35,35,35,35,35,21,21,21,0 ,0 ,2 ,2 ,35,35,3 ,35,35,
	21,4 ,35,35,9 ,21,21,21,21,21,35,35,35,35,5 ,35,35,21,21,21,21,21,0 ,35,35,35,35,35,35,35,
	21,4 ,35,4 ,21,21,21,21,21,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,21,21,21,21,21,0 ,35,3 ,35,35,6 ,35,35,
	21,4 ,35,35,4 ,4 ,21,3 ,3 ,35,2 ,35,35,35,21,21,21,21,21,21,21,35,0 ,35,35,35,35,35,35,35,
	21,21,21,35,35,4 ,21,3 ,2 ,3 ,35,3 ,3 ,3 ,35,21,21,35,2 ,2 ,35,35,0 ,35,35,2 ,35,3 ,35,21,
	21,21,21,21,35,4 ,2 ,35,35,35,3 ,35,2 ,3 ,35,21,35,1 ,35,35,35,35,35,0 ,35,35,35,35,35,21,
	21,17,35,21,35,4 ,21,3 ,35,3 ,35,35,35,35,35,21,35,35,35,35,2 ,21,0 ,21,17,35,35,35,35,21,
	16,35,35,4 ,35,35,2 ,35,35,3 ,3 ,35,3 ,35,3 ,21,21,35,35,17,2 ,21,0 ,21,17,2 ,35,35,21,21,
	21,35,17,21,21,35,21,35,35,35,35,3 ,35,35,21,21,21,17,2 ,17,17,21,0 ,21,17,2 ,2 ,21,21,21,
	21,17,21,21,21,21,21,21,21,35,35,35,35,21,21,21,21,21,17,17,17,21,2 ,21,21,21,21,21,21,21
};

Level17::Level17() : LevelDefinition(30, 20, 17, "Bury Drainage Hirers", level17Data) {
}

void Level17::recolourBitmaps() {
	BitmapServer::makeBouldersBlue();
}