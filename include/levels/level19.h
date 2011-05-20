#ifndef _LEVEL19_H_
#define _LEVEL19_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 19.
 */
class Level19 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level19();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

