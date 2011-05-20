#ifndef _LEVEL21_H_
#define _LEVEL21_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 21.
 */
class Level21 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level21();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

