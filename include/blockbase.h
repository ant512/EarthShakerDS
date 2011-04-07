#ifndef _BLOCK_BASE_H_
#define _BLOCK_BASE_H_

#include <graphics.h>
#include <bitmap.h>

using namespace WoopsiUI;

class BlockBase {
public:
	BlockBase() {
		_bitmap = new Bitmap(16, 16);
		_isDestructable = false;
		_canFall = false;
	};

	inline virtual ~BlockBase() {
		delete _bitmap;
	};

	virtual void render(s32 x, s32 y, Graphics* gfx) {
		gfx->drawBitmap(x * _bitmap->getWidth(), y * _bitmap->getHeight(), _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);
	};

	inline bool isDestructable() { return _isDestructable; }
	inline bool canFall() { return _canFall; }

protected:
	Bitmap* _bitmap;
	bool _isDestructable;
	bool _canFall;
};

#endif
