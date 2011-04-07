#ifndef _LEVEL_BASE_H_
#define _LEVEL_BASE_H_

#include <graphics.h>

#include "blockbase.h"

using namespace WoopsiUI;

class LevelBase {
public:

	LevelBase(s32 width, s32 height);

	virtual ~LevelBase();

	inline s32 getWidth() const { return _width; };

	inline s32 getHeight() const { return _height; };

	inline BlockBase* getBlockAt(s32 x, s32 y) const { return _data[(y * _width) + x]; };

	inline void setBlockAt(s32 x, s32 y, BlockBase* block) { _data[(y * _width) + x] = block; };

	void render(Graphics* gfx);

private:
	s32 _width;
	s32 _height;
	BlockBase** _data;
};

#endif
