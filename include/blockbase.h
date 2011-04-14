#ifndef _BLOCK_BASE_H_
#define _BLOCK_BASE_H_

#include <bitmap.h>
#include <graphics.h>
#include <animation.h>

class LevelBase;
class Game;

/**
 * Base class for all blocks that appear in the game.
 */
class BlockBase {
public:

	static const s32 BLOCK_SIZE = 16;			/**< The width and height of a block in pixels. */

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BlockBase(s32 x, s32 y, Game* game);

	/**
	 * Destructor.
	 */
	virtual ~BlockBase();

	/**
	 * Sets the x co-ordinate of the block.  Typically the LevelBase class
	 * should be left alone to manage block co-ordinates using this method.
	 * @param x The x co-ordinate of the block.
	 */
	void setX(s32 x);

	/**
	 * Sets the y co-ordinate of the block.  Typically the LevelBase class
	 * should be left alone to manage block co-ordinates using this method.
	 * @param y The y co-ordinate of the block.
	 */
	void setY(s32 y);

	/**
	 * Gets the x co-ordinate of the block.
	 * @return The x co-ordinate of the block.
	 */
	s32 getX() const;

	/**
	 * Gets the y co-ordinate of the block.
	 * @return The y co-ordinate of the block.
	 */
	s32 getY() const;

	/**
	 * Draw the block to the graphics object using the supplied map co-ordinates
	 * to inform the location the block's bitmap will be drawn at.
	 * @param x The x co-ordinate to render to.
	 * @param y The y co-ordinate to render to.
	 * @param gfx The graphics object to draw to.
	 */
	virtual void render(s32 x, s32 y, WoopsiGfx::Graphics* gfx);

	/**
	 * The block examines the level and based on its layout acts appropriately.
	 * @return True if the block performs an action that changes the layout of
	 * the map; false if not.
	 */
	void iterate();

	/**
	 * Check if the block is slippy.  If this is true, blocks sitting on this
	 * block will slip to the left or right if the left or right block adjacent
	 * to this is empty.  For example:
	 *
	 *   x   If block o is slippy, x slides to the left.
	 *   oo
	 *  ooo
	 *
	 *   x   If block o is slippy, x will not fall.
	 *  ooo
	 *
	 *   x   If block o is not slippy, x will not fall.
	 *   o
	 *  ooo
	 * @return True if the block is slippy; false if not.
	 */
	inline bool isSlippy() const { return _isSlippy; };

	/**
	 * Gets whether or not the block is hot.  Hot blocks can be extinguished
	 * and removed by bubbles.  They cause boulders to explode.
	 * @return True if the block is hot; false if not.
	 */
	bool isHot() const;

	/**
	 * Check if the block is exploding.
	 * @return True if the block is exploding; false if not.
	 */
	inline bool isExploding() const { return _isExploding; };

	/**
	 * Check if the block has been destroyed.  Blocks are considered destroyed
	 * if they are exploding and their exploding animation has finished
	 * playing.
	 * @return True if the block is destroyed; false if not.
	 */
	bool isDestroyed() const;

	/**
	 * Check if the block is currently falling.
	 * @return True if the block is falling; false if not.
	 */
	bool isFalling() const;

	/**
	 * Explodes the block.  The block will switch to showing its exploded
	 * animation and can no longer be interacted with.  Once the animation ends,
	 * the block orders the level to remove it.
	 */
	void explode();

	/**
	 * Slides the block to the left if it is not falling, is sat on a slippy
	 * block, and has an empty space to slide into that also has an empty space
	 * below it.
	 */
	void slideLeft();

	/**
	 * Slides the block to the right if it is not falling, is sat on a slippy
	 * block, and has an empty space to slide into that also has an empty space
	 * below it.
	 */
	void slideRight();

	/**
	 * Either drops or raises the block depending on gravity.
	 */
	void fall();

	/**
	 * Squashes the block.  Called when a heavy block lands on it.
	 */
	virtual void squash() { };

	/**
	 * Attempt to dig this block from below.
	 * @return True if the dig attempt was successful; false if not.
	 */
	virtual bool digFromBelow() { return false; };

	/**
	 * Attempt to dig this block from below.
	 * @return True if the dig attempt was successful; false if not.
	 */
	virtual bool digFromAbove() { return false; };

	/**
	 * Attempt to dig this block from below.
	 * @return True if the dig attempt was successful; false if not.
	 */
	virtual bool digFromLeft() { return false; };

	/**
	 * Attempt to dig this block from below.
	 * @return True if the dig attempt was successful; false if not.
	 */
	virtual bool digFromRight() { return false; };

	/**
	 * Attempt to push this block upwards.
	 * @return True if the attempt was successful; false if not.
	 */
	virtual bool pushUp() { return false; };

	/**
	 * Attempt to push this block downwards.
	 * @return True if the attempt was successful; false if not.
	 */
	virtual bool pushDown() { return false; };

	/**
	 * Attempt to push this block leftwards.
	 * @return True if the attempt was successful; false if not.
	 */
	virtual bool pushLeft() { return false; };

	/**
	 * Attempt to push this block rightwards.
	 * @return True if the attempt was successful; false if not.
	 */
	virtual bool pushRight() { return false; };

protected:
	WoopsiGfx::Animation* _animation;			/**< Standard animation. */
	WoopsiGfx::Animation* _explodingAnimation;	/**< Animation shown when the block is exploding. */
	s32 _x;										/**< The x co-ordinate of the block within the level. */
	s32 _y;										/**< The y co-ordinate of the block within the level. */
	Game* _game;								/**< Pointer to the game that contains this block. */
	bool _isSlippy;								/**< If true, blocks sitting on this will slip to
													 the left or right if this block has empty space
													 next to it. */
	bool _isHot;								/**< Indicates whether or not the block is hot; hot
													 blocks cause boulders to explode. */
	bool _isExploding;							/**< Indicates whether or not the block is exploding. */
	bool _isOddIteration;						/**< Remembers if the block is currently at an odd
													 or even iteration.  Prevents the block iterating
													 twice during a single iteration of the game if it
													 moves. */
	bool _isFalling;							/**< Indicates whether or not the block is falling. */
	bool _isHeavyEnoughToKill;					/**< Indicates whether or not having the block land
													 on the player kills him. */
	bool _isHeavy;								/**< Indicates whether or not the block falls when
													 unsupported. */

	/**
	 * Called when the block's iterate() method runs.
	 */
	virtual void onIterate() { };

	/**
	 * Called when an exploded block is finally destroyed.  Don't confuse this
	 * with the C++ destructor, which is called when the block is deleted from
	 * memory.
	 */
	virtual void onDestroyed() { };

	/**
	 * Called when the block explodes.
	 */
	virtual void onExplode() { };

	/**
	 * Called when the block falls.
	 */
	virtual void onFall() { };

	/**
	 * Drops the block from its current position to a free block below.
	 */
	void drop();

	/**
	 * Uses the same algorithm as drop() but raises the block instead of
	 * lowering it.  To be used when gravity is inverted.
	 */
	void raise();

	/**
	 * Squashes the block we're falling onto.
	 */
	void squashBlock();
};

#endif
