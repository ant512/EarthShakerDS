#ifndef _HEAVY_BLOCK_BASE_H_
#define _HEAVY_BLOCK_BASE_H_

#include <bitmap.h>
#include <graphics.h>

#include "blockbase.h"

class LevelBase;
class Game;

/**
 * Base class for all blocks that fall when they are not sitting on anything.
 */
class HeavyBlockBase : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate of the block within the current level.
	 * @param y The y co-ordinate of the block within the current level.
	 * @param game Pointe to the game that contains this block.
	 */
	HeavyBlockBase(s32 x, s32 y, Game* game);

	/**
	 * Destructor.
	 */
	virtual ~HeavyBlockBase() { };

	/**
	 * Check if the block is falling.  This is set to true during an iteration
	 * if the block drops.
	 * @return True if the block is falling; false if not.
	 */
	bool isFalling() const;

protected:
	bool _isFalling;		/**< The falling state of the block. */

	/**
	 * Drops the block from its current position to a free block below.  Will
	 * drop vertically if the block beneath is empty.  Will drop to the left if
	 * the left block and the one below that are empty.  Will drop to the right
	 * if the right block and the one below that are empty.
	 */
	void drop();

	/**
	 * Uses the same algorithm as drop() but raises the block instead of
	 * lowering it.  To be used when gravity is inverted.
	 */
	void raise();
};

#endif
