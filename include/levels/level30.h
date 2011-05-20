#ifndef _LEVEL30_H_
#define _LEVEL30_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 30.
 */
class Level30 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level30();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

