#ifndef _LEVEL_2_H_
#define _LEVEL_2_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 2.
 */
class Level2 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level2();
	
	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif
