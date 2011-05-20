#include "level28.h"
#include "bitmapserver.h"

const static u8 level28Data[600] = {
	0 ,17,0 ,32,32,26,26,10,32,17,17,17,10,0 ,0 ,32,26,26,32,0 ,0 ,0 ,0 ,26,32,3 ,32,26,0 ,17,
	0 ,32,0 ,3 ,32,26,5 ,5 ,2 ,5 ,26,26,26,32,32,0 ,32,32,0 ,0 ,17,0 ,0 ,32,0 ,0 ,0 ,32,0 ,32,
	0 ,32,0 ,0 ,32,26,26,4 ,17,4 ,26,0 ,0 ,0 ,0 ,0 ,32,0 ,0 ,0 ,32,0 ,0 ,32,0 ,0 ,0 ,0 ,0 ,17,
	2 ,32,0 ,0 ,32,0 ,26,26,26,26,26,32,0 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,5 ,0 ,0 ,32,0 ,17,0 ,0 ,26,17,
	17,32,0 ,0 ,32,0 ,32,0 ,0 ,0 ,32,17,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,32,0 ,0 ,3 ,0 ,32,0 ,0 ,26,17,
	2 ,17,0 ,0 ,0 ,0 ,32,0 ,0 ,3 ,0 ,32,0 ,0 ,32,0 ,0 ,0 ,0 ,32,5 ,0 ,0 ,0 ,0 ,32,0 ,26,17,17,
	17,17,4 ,0 ,0 ,4 ,32,0 ,0 ,32,0 ,0 ,0 ,32,32,32,0 ,0 ,0 ,4 ,26,26,0 ,0 ,17,17,26,26,3 ,2 ,
	17,17,2 ,4 ,4 ,26,26,0 ,0 ,0 ,32,4 ,4 ,26,4 ,4 ,4 ,4 ,4 ,2 ,26,4 ,0 ,32,2 ,2 ,17,2 ,17,2 ,
	8 ,26,26,26,26,26,26,26,0 ,0 ,26,26,2 ,26,26,2 ,26,26,2 ,26,26,2 ,26,26,26,26,26,17,3 ,10,
	0 ,26,5 ,26,3 ,26,26,0 ,0 ,26,32,0 ,26,0 ,26,26,7 ,26,26,17,17,26,4 ,32,26,17,17,2 ,17,2 ,
	0 ,26,5 ,32,32,26,0 ,0 ,26,32,1 ,32,0 ,0 ,8 ,8 ,8 ,8 ,8 ,17,17,0 ,4 ,4 ,26,2 ,17,17,17,17,
	0 ,26,26,26,32,26,0 ,0 ,26,2 ,26,2 ,26,0 ,8 ,2 ,2 ,2 ,8 ,17,32,0 ,32,4 ,26,17,32,32,17,17,
	0 ,0 ,32,32,0 ,26,26,0 ,26,26,26,26,26,0 ,8 ,2 ,2 ,2 ,8 ,32,0 ,0 ,0 ,4 ,26,17,0 ,0 ,32,17,
	0 ,32,4 ,26,0 ,0 ,0 ,0 ,0 ,17,0 ,0 ,0 ,0 ,8 ,2 ,2 ,2 ,8 ,17,32,0 ,0 ,32,26,32,0 ,0 ,0 ,17,
	0 ,32,4 ,26,0 ,26,26,0 ,26,26,26,0 ,0 ,17,8 ,8 ,8 ,8 ,8 ,17,2 ,32,0 ,0 ,26,0 ,0 ,0 ,0 ,32,
	0 ,32,32,26,0 ,0 ,26,0 ,26,17,17,32,0 ,32,17,32,0 ,0 ,0 ,32,32,0 ,0 ,0 ,26,0 ,0 ,0 ,0 ,0 ,
	5 ,32,32,32,26,0 ,26,0 ,26,26,26,32,0 ,0 ,32,0 ,0 ,0 ,0 ,32,0 ,0 ,26,0 ,32,0 ,0 ,0 ,0 ,0 ,
	5 ,5 ,32,32,32,9 ,26,0 ,0 ,2 ,26,2 ,32,0 ,0 ,0 ,17,0 ,0 ,0 ,0 ,2 ,26,26,0 ,0 ,0 ,0 ,0 ,0 ,
	5 ,5 ,3 ,32,0 ,0 ,26,0 ,26,26,10,17,0 ,0 ,17,26,32,26,0 ,0 ,32,17,26,5 ,26,0 ,0 ,0 ,0 ,17,
	15,17,0 ,0 ,32,2 ,26,4 ,32,10,2 ,32,2 ,2 ,32,32,2 ,32,2 ,2 ,3 ,10,26,5 ,5 ,0 ,0 ,17,17,17
};

Level28::Level28() : LevelDefinition(30, 20, 28, "Your Safe With Me", level28Data) {
}

void Level28::recolourBitmaps() {
	BitmapServer::makeSoilBlue();
	BitmapServer::makeBouldersYellow();
}