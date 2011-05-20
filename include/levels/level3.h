#ifndef _LEVEL_3_H_
#define _LEVEL_3_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 3.
 */
class Level3 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level3();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif
