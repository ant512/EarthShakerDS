#include <bitmap.h>
#include <graphics.h>

#include "game.h"
#include "playersprite.h"
#include "mapitembase.h"

using namespace WoopsiUI;

PlayerSprite::PlayerSprite(s32 x, s32 y, Game* game) : MapItemBase(x, y, game) {
	_bitmap = new Bitmap(16, 16);

	Graphics* gfx = _bitmap->newGraphics();
	gfx->drawFilledRect(0, 0, 16, 16, woopsiRGB(0, 0, 0));
	gfx->drawLine(0, 0, 15, 15, woopsiRGB(0, 31, 0));
	gfx->drawLine(0, 15, 15, 0, woopsiRGB(0, 31, 0));
	delete gfx;
}

PlayerSprite::~PlayerSprite() {
	delete _bitmap;
}

void PlayerSprite::render(Graphics* gfx) {
	gfx->drawBitmap(_x * _bitmap->getWidth(), _y * _bitmap->getHeight(), _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);
}
