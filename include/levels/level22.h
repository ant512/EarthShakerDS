#ifndef _LEVEL22_H_
#define _LEVEL22_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 22.
 */
class Level22 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level22();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

