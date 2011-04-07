#ifndef _SOIL_BLOCK_H_
#define _SOIL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "blockbase.h"

using namespace WoopsiUI;

class SoilBlock : public BlockBase {
public:
	SoilBlock() {
		Graphics* gfx = _bitmap->newGraphics();
		gfx->drawFilledRect(0, 0, 16, 16, woopsiRGB(17, 8, 2));
		delete gfx;
	};

	~SoilBlock() {};
};

#endif
