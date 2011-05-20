#ifndef _LEVEL_6_H_
#define _LEVEL_6_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * level 6.
 */
class Level6 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level6();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif
