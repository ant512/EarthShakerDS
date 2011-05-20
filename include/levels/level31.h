#ifndef _LEVEL31_H_
#define _LEVEL31_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 31.
 */
class Level31 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level31();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

