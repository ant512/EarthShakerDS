#ifndef _LEVEL29_H_
#define _LEVEL29_H_

#include "leveldefinition.h"
#include "bitmapserver.h"

/**
 * Level 29.
 */
class Level29 : public LevelDefinition {
public:

	/**
	 * Constructor.
	 */
	Level29();

	/**
	 * Swap bitmaps to use palette of this level.
	 */
	void recolourBitmaps();
};

#endif

