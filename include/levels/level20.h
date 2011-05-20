#ifndef _LEVEL20_H_
#define _LEVEL20_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 20.
 */
class Level20 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level20();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

