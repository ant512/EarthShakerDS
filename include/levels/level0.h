#ifndef _LEVEL_0_H_
#define _LEVEL_0_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Test level.
 */
class Level0 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level0() : LevelDefinition(30, 20, 0, "Testing Ground") {
		u8 layout[600] = {
			6,6,6,6,14,1,18,1,18,1,2,1,1,1,1,1,1,1,2,2,1,1,1,1,6,6,6,6,6,6,
			6,6,1,1,1,1,1,1,16,1,1,1,1,1,1,1,1,1,1,1,2,1,1,3,6,3,3,3,6,6,
			6,3,1,1,1,1,1,2,16,1,1,1,1,2,1,2,1,1,1,1,2,1,1,1,1,3,3,3,3,6,
			3,1,1,1,3,1,1,2,16,1,3,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,3,6,6,
			1,1,1,1,1,1,1,1,16,1,1,1,1,1,1,9,1,1,1,1,1,1,5,1,1,1,1,1,1,1,
			1,1,1,3,1,1,1,1,1,1,1,2,1,1,1,6,1,1,1,1,3,1,1,1,1,3,1,1,1,1,
			1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,2,1,1,1,1,1,1,1,8,1,2,1,1,1,2,
			1,1,1,1,1,2,2,1,1,1,1,1,3,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,
			3,1,1,1,1,2,1,1,5,1,1,1,1,1,1,1,1,1,1,2,1,1,3,1,1,3,1,1,1,1,
			6,1,1,1,1,1,1,1,1,1,1,1,1,2,1,4,1,1,1,1,1,1,1,1,1,2,1,1,3,2,
			6,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,
			3,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,2,1,1,1,1,1,2,2,
			6,1,1,1,1,2,1,1,1,1,2,2,1,1,3,1,1,1,1,3,1,1,1,1,1,1,1,1,6,6,
			6,6,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,17,1,1,2,1,1,1,6,
			6,6,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,3,1,1,1,1,1,1,1,1,2,6,
			6,6,1,3,1,1,1,1,1,1,3,3,3,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,2,6,
			6,6,6,1,1,1,1,1,1,1,1,1,1,0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,6,
			6,6,6,6,1,1,1,3,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,2,1,1,2,2,2,6,
			6,6,6,6,6,0,6,6,6,0,6,6,6,3,6,6,6,0,6,6,6,0,6,2,2,2,2,2,6,6,
			6,6,6,6,6,7,6,6,6,7,6,6,6,7,6,6,6,7,6,6,6,7,6,6,6,6,6,6,6,6};

		setLayout(layout);
		addTeleportLink(6, 0, 8, 0);

		BitmapServer::makeDoorGreen();
		BitmapServer::makeBouldersYellow();
		BitmapServer::makeSoilBlue();
	};
};

#endif
