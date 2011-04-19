#ifndef _LEVEL_5_H_
#define _LEVEL_5_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Test level.
 */
class Level5 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level5() : LevelDefinition(30, 20, 5, "Hush Toed Iceland") {
		u8 layout[600] = {
			20,2 ,20,2 ,20,32,2 ,20,2 ,20,2 ,32,20,20,2 ,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			2 ,5 ,20,32,2 ,32,20,2 ,32,20,20,17,20,20,32,2 ,20,32,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			20,32,32,20,20,32,20,20,32,2 ,20,32,32,20,32,20,20,2 ,32,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			20,20,32,32,20,2 ,20,2 ,20,32,32,32,32,32,32,2 ,20,32,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			2 ,17,20,32,32,32,32,32,20,20,20,9 ,20,32,20,20,20,32,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			20,32,32,20,20,20,20,32,32,32,20,20,20,32,20,2 ,20,32,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			20,20,32,2 ,32,32,32,20,20,2 ,32,32,32,32,20,32,32,32,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			2 ,32,32,20,32,20,2 ,32,32,20,20,32,20,20,8 ,8 ,20,32,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			2 ,20,20,32,32,20,2 ,20,32,32,32,32,20,32,32,20,20,32,32,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			20,20,0 ,17,32,20,20,20,20,32,20,32,32,1 ,32,32,20,2 ,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			2 ,32,32,20,0 ,20,2 ,20,2 ,32,20,20,20,32,10,32,20,20,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			0 ,0 ,0 ,0 ,0 ,32,32,32,20,20,20,8 ,8 ,8 ,20,32,8 ,2 ,32,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			0 ,0 ,0 ,2 ,2 ,20,20,20,20,32,32,2 ,20,32,32,20,20,20,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			0 ,0 ,0 ,20,20,20,32,32,2 ,32,20,32,32,20,32,2 ,32,32,32,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			0 ,0 ,0 ,32,32,32,32,20,20,20,20,32,20,20,20,32,20,20,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			0 ,0 ,0 ,0 ,0 ,0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
			0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };

		setLayout(layout);

		BitmapServer::makeSoilBlue();
		BitmapServer::makeBrickWallRed();
		BitmapServer::makeBouldersYellow();
	};
};

#endif
