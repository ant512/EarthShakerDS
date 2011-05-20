#ifndef _LEVEL24_H_
#define _LEVEL24_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 24.
 */
class Level24 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level24();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

