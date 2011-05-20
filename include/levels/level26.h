#ifndef _LEVEL26_H_
#define _LEVEL26_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 26.
 */
class Level26 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level26();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

