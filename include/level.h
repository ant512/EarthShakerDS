#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <graphics.h>
#include <woopsistring.h>
#include <woopsiarray.h>

class BlockBase;
class PlayerBlock;

/**
 * Base class for all levels.  Controls the entire grid of blocks.
 */
class Level {
public:

	/**
	 * Constructor.
	 * @param width Width of the level in blocks.
	 * @param height Height of the level in blocks.
	 * @param number The level number.
	 * @param name The level name.
	 */
	Level(s32 width, s32 height, s32 number, const WoopsiGfx::WoopsiString& name);

	/**
	 * Destructor.
	 */
	virtual ~Level();

	/**
	 * Gets the width of the level in blocks.
	 * @return The width of the level in blocks.
	 */
	inline s32 getWidth() const { return _width; };

	/**
	 * Gets the height of the level in blocks.
	 * @return The height of the level in blocks.
	 */
	inline s32 getHeight() const { return _height; };

	/**
	 * Gets the name of the level.
	 * @return The name of the level.
	 */
	inline const WoopsiGfx::WoopsiString& getName() const { return _name; };

	/**
	 * Gets the number of the level.
	 * @return The number of the level.
	 */
	inline s32 getNumber() const { return _number; };

	/**
	 * Increases the total number of diamonds in the level by one.
	 */
	inline void increaseDiamondCount() { ++_diamondCount; };

	/**
	 * Gets the total number of diamonds in the level.
	 * @return The total number of diamonds in the level.
	 */
	inline s32 getDiamondCount() { return _diamondCount; };

	/**
	 * Gets a pointer to the block representing the player.
	 * @return A pointer to the player block.
	 */
	PlayerBlock* getPlayerBlock() const;

	/**
	 * Sets the player block pointer to the specified block.
	 * @param block A pointer to the player block.
	 */
	void setPlayerBlock(PlayerBlock* block);

	/**
	 * Gets the block at the specified co-ordinates.
	 * @param x The x co-ordinate of the block to retrieve.
	 * @param y The y co-ordinate of the block to retrieve.
	 * @return The block at the specified co-ordinates, or NULL if there is no
	 * block at those co-ordinates.
	 */
	BlockBase* getBlockAt(s32 x, s32 y) const;

	/**
	 * Sets the block at the specified co-ordinates.  If another block is
	 * already at the co-ordinates it will be overwritten.  If the existing
	 * block at the co-ordinates should be deleted, the call to setBlockAt()
	 * should be preceeded by a call to removeBlockAt().  If the new block is
	 * already in the map at another set of co-ordinates, you will need to
	 * ensure that you set the block at those co-ordinates to NULL.
	 * Alternatively, consider using the moveBlock() method.
	 * @param x The x co-ordinate to replace with the specified block.
	 * @param y The y co-ordinate to replace with the specified block.
	 * @param block The block to place at the specified co-ordinates.
	 */
	void setBlockAt(s32 x, s32 y, BlockBase* block);

	/**
	 * Moves the block from the source co-ordinates to the destination
	 * co-ordinates.  The source co-ordinates are set to NULL.  If a block
	 * already exists at the destination co-ordinates it is overwritten and
	 * its pointer is added to the removed block list ready to be deleted.
	 * @param sourceX The x co-ordinate of the block to move.
	 * @param sourceY The y co-ordinate of the block to move.
	 * @param destX The x co-ordinate to move to.
	 * @param destY The y co-ordinate to move to.
	 */
	void moveBlock(s32 sourceX, s32 sourceY, s32 destX, s32 destY);

	/**
	 * Renders the rectangular subset of blocks indicated to the supplied
	 * graphics object.
	 * @param centreX The x co-ordinate of the block to centre on if possible.
	 * @param centreY The y co-ordinate of the block to centre on if possible.
	 * @param gfx The graphics object to draw to.
	 */
	void render(s32 centreX, s32 centreY, WoopsiGfx::Graphics* gfx);

	/**
	 * Renders the level as a map.
	 * @param gfx The graphics object to draw to.
	 */
	void renderMap(WoopsiGfx::Graphics* gfx);

	/**
	 * Animates all blocks in the level.
	 */
	void animate();

	/**
	 * Iterates all blocks in the level.  The gravity state determines the order
	 * in which blocks are iterated.
	 * @param isGravityInverted True for inverted gravity; false for normal
	 * gravity.
	 */
	void iterate(bool isGravityInverted);

	/**
	 * Removes the block at the specified co-ordinates and adds it to the list
	 * of blocks for deletion.
	 * @param x The x co-ordinate of the block to remove.
	 * @param y The y co-ordinate of the block to remove.
	 */
	void removeBlockAt(s32 x, s32 y);

private:
	s32 _width;									/**< The width of the level. */
	s32 _height;								/**< The height of the level. */
	BlockBase** _data;							/**< Array of blocks that make up the level. */
	WoopsiGfx::WoopsiString _name;				/**< The name of the level. */
	s32 _number;								/**< The number of the level. */
	s32 _diamondCount;							/**< The total number of diamonds in the level. */
	PlayerBlock* _playerBlock;					/**< The player's block within the level. */
	WoopsiArray<BlockBase*> _removedBlockList;	/**< Array of blocks that have been removed
													 from the level and are awaiting deletion. */

	/**
	 * Deletes any blocks in the removed list.
	 */
	void deleteRemovedBlocks();

	/**
	 * Calls the iterate() method of all child blocks.
	 */
	void iterateBlocks(bool isGravityInverted);
};

#endif
