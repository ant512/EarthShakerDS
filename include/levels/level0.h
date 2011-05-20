#ifndef _LEVEL_0_H_
#define _LEVEL_0_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Test level.
 */
class Level0 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level0();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif
