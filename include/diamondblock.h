#ifndef _DIAMOND_BLOCK_H_
#define _DIAMOND_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "blockbase.h"

using namespace WoopsiUI;

class DiamondBlock : public BlockBase {
public:
	DiamondBlock() {
		_canFall = true;
		
		Graphics* gfx = _bitmap->newGraphics();

		gfx->drawLine(0, 7, 7, 0, woopsiRGB(0, 0, 31));
		gfx->drawLine(8, 0, 15, 7, woopsiRGB(0, 0, 31));
		gfx->drawLine(0, 8, 7, 15, woopsiRGB(0, 0, 31));
		gfx->drawLine(8, 15, 15, 8, woopsiRGB(0, 0, 31));

		gfx->floodFill(7, 7, woopsiRGB(0, 0, 31));

		delete gfx;
	};

	~DiamondBlock() {};
};

#endif
