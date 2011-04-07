#ifndef _BLOCK_BASE_H_
#define _BLOCK_BASE_H_

#include <graphics.h>
#include <bitmap.h>

using namespace WoopsiUI;

class BlockBase {
public:
	BlockBase() {
		_bitmap = new Bitmap(16, 16);
	};

	inline virtual ~BlockBase() {
		delete _bitmap;
	};

	virtual void render(s32 x, s32 y, Graphics* gfx) {
		gfx->drawBitmap(x * _bitmap->getWidth(), y * _bitmap->getHeight(), _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);
	};

protected:
	Bitmap* _bitmap;
};

#endif
