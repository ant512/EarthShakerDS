#ifndef _BLOCK_BASE_H_
#define _BLOCK_BASE_H_

#include <bitmap.h>
#include <graphics.h>

using namespace WoopsiUI;

class LevelBase;

class BlockBase {
public:
	BlockBase();

	virtual ~BlockBase();

	virtual void render(s32 x, s32 y, Graphics* gfx);

	virtual bool iterate(s32 x, s32 y, LevelBase* level);

	bool tryToDrop(s32 x, s32 y, LevelBase* level);

protected:
	Bitmap* _bitmap;
};

#endif
