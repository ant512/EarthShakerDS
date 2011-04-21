#include "blockdisplayscreen.h"
#include "spectrumcolours.h"
#include "teleportblock.h"
#include "constants.h"

BlockDisplayScreen::BlockDisplayScreen(WoopsiGfx::Graphics* bottomGfx) : ScreenBase(NULL, bottomGfx) {
	_block = new TeleportBlock(0, 0, NULL);
	_timer = 0;
	_blockX = 120;
	_blockY = 88;
}

BlockDisplayScreen::~BlockDisplayScreen() {
	delete _block;
}

void BlockDisplayScreen::iterate(PadState pad) {
	++_timer;

	if (_timer == ANIMATION_TIME) {
		_timer = 0;

		_block->animate();
		_block->render(_blockX, _blockY, _bottomGfx);

		WoopsiGfx::WoopsiString str = "Teleporter";
		_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 160, &_font, str, 0, str.getLength(), COLOUR_WHITE);
	}
}

bool BlockDisplayScreen::isRunning() const {
	return true;
}
