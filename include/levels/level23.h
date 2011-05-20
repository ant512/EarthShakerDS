#ifndef _LEVEL23_H_
#define _LEVEL23_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 23.
 */
class Level23 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level23();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

