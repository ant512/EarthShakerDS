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
	 * @param game Pointer to the game that contains this block.
	 */
	HeavyBlockBase(s32 x, s32 y, Game* game);

	/**
	 * Destructor.
	 */
	virtual ~HeavyBlockBase() { };

protected:
	bool _isOnPlayer;					/**< Indicates that the block is sitting
											 on top of the player. */
	bool _isHeavyEnoughToKill;			/**< Indicates whether or not having the
											 block land on the player kills him. */

	/**
	 * Called when the block falls.
	 */
	virtual void onFall() { };

	/**
	 * Called when the block's iterate() method runs.
	 */
	virtual void onIterate();

private:

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

	/**
	 * Either drops or raises the block depending on gravity.
	 */
	void fall();

	/**
	 * Squashes the block we're falling onto.
	 */
	void squashBlock();
};

#endif
