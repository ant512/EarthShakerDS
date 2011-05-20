#ifndef _LEVEL28_H_
#define _LEVEL28_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 28.
 */
class Level28 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level28();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

