#ifndef _EMPTY_LEVEL_H_
#define _EMPTY_LEVEL_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Test level.
 */
class EmptyLevel : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	EmptyLevel();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif
