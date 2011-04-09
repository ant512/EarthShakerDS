#ifndef _HEAVY_BLOCK_BASE_H_
#define _HEAVY_BLOCK_BASE_H_

#include <bitmap.h>
#include <graphics.h>

#include "blockbase.h"

class LevelBase;
class Game;

class HeavyBlockBase : public BlockBase {
public:

	/**
	 * Constructor.
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

	/**
	 * Pushes this block to the left if the block to the left is empty.
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param level The level containing this block.
	 * @return True if the block moves; false if not.
	 */
	bool applyLeftwardForce();

	/**
	 * Pushes this block to the right if the block to the left is empty.
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param level The level containing this block.
	 * @return True if the block moves; false if not.
	 */
	bool applyRightwardForce();

protected:
	bool _isFalling;		/**< The falling state of the block. */

	/**
	 * Drops the block from its current position to a free block below.  Will
	 * drop vertically if the block beneath is empty.  Will drop to the left if
	 * the left block and the one below that are empty.  Will drop to the right
	 * if the right block and the one below that are empty.
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param level The level containing this block.
	 * @return True if the block drops; false if not.
	 */
	bool drop();
};

#endif
