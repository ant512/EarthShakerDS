#ifndef _BLOCK_BASE_H_
#define _BLOCK_BASE_H_

#include <bitmap.h>
#include <graphics.h>

using namespace WoopsiUI;

class LevelBase;
class Game;

class BlockBase {
public:

	/**
	 * Constructor.
	 */
	BlockBase();

	/**
	 * Destructor.
	 */
	virtual ~BlockBase();

	/**
	 * Draw the block to the graphics object using the supplied map co-ordinates
	 * to inform the location the block's bitmap will be drawn at.
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param gfx The graphics object to draw to.
	 */
	virtual void render(s32 x, s32 y, Graphics* gfx);

	/**
	 * The block examines the level and based on its layout acts appropriately.
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param level The level containing this block.
	 * @return True if the block performs an action that changes the layout of
	 * the map; false if not.
	 */
	virtual bool iterate(s32 x, s32 y, LevelBase* level);

	/**
	 * Check if the block is falling.  This is set to true during an iteration
	 * if the block drops.
	 * @return True if the block is falling; false if not.
	 */
	bool isFalling() const;

	/**
	 * Player is moving into this block.  The direction in which the player is
	 * moving can be determined by calculating the co-ordinates of this block
	 * (given in x,y) and the co-ordinates of the player (given in playerX,
	 * playerY).
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param playerX The x co-ordinate of the player within the level map.
	 * @param playerY The y co-ordinate of the player within the level map.
	 * @return True if the player successfully moves into this block; false if
	 * not.
	 */
	inline virtual bool movePlayerInside(s32 x, s32 y, s32 playerX, s32 playerY, Game* game) = 0;

protected:
	Bitmap* _bitmap;		/**< The bitmap representing the appearance of the block. */
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
	bool drop(s32 x, s32 y, LevelBase* level);

	/**
	 * Pushes this block to the left if the block to the left is empty.
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param level The level containing this block.
	 * @return True if the block moves; false if not.
	 */
	bool pushLeft(s32 x, s32 y, LevelBase* level);

	/**
	 * Pushes this block to the right if the block to the left is empty.
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param level The level containing this block.
	 * @return True if the block moves; false if not.
	 */
	bool pushRight(s32 x, s32 y, LevelBase* level);
};

#endif
