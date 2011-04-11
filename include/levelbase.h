#ifndef _LEVEL_BASE_H_
#define _LEVEL_BASE_H_

#include <graphics.h>
#include <woopsistring.h>
#include <woopsiarray.h>

class BlockBase;

class LevelBase {
public:

	LevelBase(s32 width, s32 height, s32 number, const WoopsiGfx::WoopsiString& name);

	virtual ~LevelBase();

	inline s32 getWidth() const { return _width; };

	inline s32 getHeight() const { return _height; };

	inline const WoopsiGfx::WoopsiString& getName() const { return _name; };

	inline s32 getLevelNumber() const { return _levelNumber; };

	BlockBase* getBlockAt(s32 x, s32 y) const;

	void setBlockAt(s32 x, s32 y, BlockBase* block);

	void moveBlock(s32 sourceX, s32 sourceY, s32 destX, s32 destY);

	void render(s32 blockX, s32 blockY, s32 numBlocksX, s32 numBlocksY, WoopsiGfx::Graphics* gfx);

	void iterate(bool isGravityInverted);

	/**
	 * Removes the block at the specified co-ordinates and adds it to the list
	 * of blocks for deletion.
	 * @param x The x co-ordinate of the block to remove.
	 * @param y The y co-ordinate of the block to remove.
	 */
	void removeBlockAt(s32 x, s32 y);

private:
	s32 _width;
	s32 _height;
	BlockBase** _data;
	WoopsiGfx::WoopsiString _name;
	s32 _levelNumber;
	WoopsiArray<BlockBase*> _removedBlockList;

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
