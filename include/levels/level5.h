#ifndef _LEVEL_5_H_
#define _LEVEL_5_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 5.
 */
class Level5 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level5();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif
