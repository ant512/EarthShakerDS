#ifndef _LEVEL_8_H_
#define _LEVEL_8_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 8.
 */
class Level8 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level8();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif
