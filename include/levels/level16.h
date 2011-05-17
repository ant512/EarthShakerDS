#ifndef _LEVEL16_H_
#define _LEVEL16_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 16.
 */
class Level16 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level16() : LevelDefinition(30, 20, 16, "Hair Brained Surgery") {
		u8 layout[600] = {
			17,17,17,32,32,2 ,32,32,5 ,5 ,5 ,22,22,22,22,10,22,4 ,22,4 ,4 ,4 ,4 ,4 ,4 ,5 ,17,32,22,22,
			17,2 ,32,32,32,32,22,22,8 ,8 ,22,22,2 ,22,2 ,3 ,22,32,22,32,17,32,17,32,17,32,3 ,32,2 ,22,
			2 ,32,32,22,8 ,8 ,22,17,2 ,17,22,32,32,22,32,17,0 ,32,22,22,8 ,22,8 ,22,8 ,22,32,22,32,22,
			17,32,22,17,17,17,22,32,17,32,32,17,22,22,32,17,17,32,32,22,2 ,22,2 ,22,2 ,22,4 ,2 ,2 ,2 ,
			32,32,22,22,8 ,8 ,22,8 ,8 ,8 ,8 ,22,22,3 ,22,17,32,32,32,22,2 ,22,2 ,22,2 ,22,32,32,22,32,
			32,22,22,22,32,32,22,22,17,22,22,22,3 ,3 ,2 ,22,22,32,32,22,22,22,22,22,22,22,32,3 ,32,32,
			32,22,3 ,3 ,32,32,22,22,32,32,22,22,3 ,3 ,17,22,22,22,32,32,32,32,22,22,32,3 ,3 ,3 ,32,2 ,
			32,22,4 ,0 ,3 ,4 ,22,22,2 ,32,32,4 ,2 ,32,32,32,32,32,32,22,2 ,32,32,32,32,3 ,32,3 ,32,22,
			17,22,22,4 ,32,22,22,22,22,22,22,22,22,32,32,22,22,32,32,22,2 ,22,17,32,32,32,32,22,22,22,
			17,22,22,22,4 ,32,3 ,32,4 ,0 ,32,32,3 ,32,32,32,22,22,9 ,22,22,22,2 ,22,17,22,32,22,22,2 ,
			17,22,22,22,32,22,22,22,22,22,32,2 ,22,32,22,8 ,22,2 ,0 ,2 ,2 ,22,10,22,2 ,22,32,2 ,22,2 ,
			17,2 ,22,22,32,32,22,22,2 ,22,3 ,2 ,22,32,22,32,32,32,22,22,32,22,2 ,32,10,22,32,2 ,22,17,
			2 ,17,22,2 ,22,32,22,2 ,2 ,22,10,22,22,32,3 ,32,22,22,22,2 ,22,22,32,32,32,32,32,2 ,17,17,
			22,17,22,2 ,22,17,22,17,22,22,22,22,32,32,3 ,32,2 ,22,22,17,22,22,2 ,2 ,22,22,2 ,2 ,2 ,22,
			22,17,17,17,17,17,17,17,17,22,22,22,32,3 ,32,3 ,22,17,17,17,17,22,22,17,17,22,22,17,17,22,
			22,22,17,17,17,17,17,17,17,17,17,22,32,22,32,22,32,17,17,17,17,17,17,17,17,17,17,17,22,22,
			22,22,22,8 ,22,8 ,22,8 ,22,8 ,22,22,32,32,22,32,32,22,8 ,22,8 ,22,8 ,22,8 ,22,8 ,22,22,22,
			22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,32,22,32,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,
			22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,32,22,32,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,
			22,4 ,4 ,22,4 ,22,4 ,22,4 ,22,4 ,4 ,22,1 ,22,11,22,4 ,22,4 ,22,4 ,22,4 ,22,4 ,22,4 ,4 ,22};

		setLayout(layout);
	};

	void recolourBitmaps() {
		BitmapServer::makeSoilGreen();
		BitmapServer::makeBouldersBlue();
	};
};

#endif

