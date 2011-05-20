#ifndef _LEVEL17_H_
#define _LEVEL17_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 17.
 */
class Level17 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level17();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

