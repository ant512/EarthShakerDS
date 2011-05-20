#ifndef _LEVEL_10_H_
#define _LEVEL_10_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 10.
 */
class Level10 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level10();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif
