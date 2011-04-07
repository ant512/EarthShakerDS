#ifndef _BLOCK_BASE_H_
#define _BLOCK_BASE_H_

#include <graphics.h>

#include <mutablebitmapbase.h>

using namespace WoopsiUI;

class BlockBase {
public:
	BlockBase(BitmapBase* bitmap) {
		_bitmap = bitmap;
	};

	inline virtual ~BlockBase() {};

	void render(s32 x, s32 y, Graphics* gfx) {
		gfx->drawBitmap(x * _bitmap->getWidth(), y * _bitmap->getHeight(), _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);
	};

private:
	BitmapBase* _bitmap;
};

#endif
