#ifndef _LEVEL_1_H_
#define _LEVEL_1_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 1.
 */
class Level1 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level1();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif
