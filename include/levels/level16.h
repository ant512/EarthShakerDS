#ifndef _LEVEL16_H_
#define _LEVEL16_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 16.
 */
class Level16 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level16();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

