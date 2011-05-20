#ifndef _LEVEL14_H_
#define _LEVEL14_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 14.
 */
class Level14 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level14();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

