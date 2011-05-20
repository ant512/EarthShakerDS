#ifndef _LEVEL32_H_
#define _LEVEL32_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 32.
 */
class Level32 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level32();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

