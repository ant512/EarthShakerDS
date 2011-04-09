#ifndef _LEVEL_BASE_H_
#define _LEVEL_BASE_H_

#include <graphics.h>

using namespace WoopsiUI;

class BlockBase;

class LevelBase {
public:

	LevelBase(s32 width, s32 height);

	virtual ~LevelBase();

	inline s32 getWidth() const { return _width; };

	inline s32 getHeight() const { return _height; };

	BlockBase* getBlockAt(s32 x, s32 y) const;

	void setBlockAt(s32 x, s32 y, BlockBase* block);

	void moveBlock(s32 sourceX, s32 sourceY, s32 destX, s32 destY);

	void render(Graphics* gfx);

	bool iterate();

private:
	s32 _width;
	s32 _height;
	BlockBase** _data;
};

#endif
