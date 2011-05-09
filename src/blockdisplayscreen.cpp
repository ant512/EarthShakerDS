#include "beanblock.h"
#include "blockdisplayscreen.h"
#include "bubbleblock.h"
#include "diamondblock.h"
#include "extralifeblock.h"
#include "fireblock.h"
#include "gravityinversionblock.h"
#include "spectrumcolours.h"
#include "teleportblock.h"
#include "constants.h"

BlockDisplayScreen::BlockDisplayScreen(WoopsiGfx::Graphics* bottomGfx) : ScreenBase(NULL, bottomGfx) {
	_block = new TeleportBlock(0, 0, NULL);
	_timer = 0;
	_blockX = 120;
	_blockY = 88;
	_state = SCREEN_STATE_GRAVITY_ERASE;
}

BlockDisplayScreen::~BlockDisplayScreen() {
	delete _block;
}

void BlockDisplayScreen::iterate(PadState pad) {

	switch (_state) {
		case SCREEN_STATE_TELEPORT_ERASE:
			_bottomGfx->drawFilledRect(0, 0, 256, 192, COLOUR_BLACK);
			_state = SCREEN_STATE_BEAN;
			_timer = 0;

			if (_block != NULL) {
				delete _block;
			}
			_block = new BeanBlock(0, 0, NULL);

			break;

		case SCREEN_STATE_BEAN_ERASE:
			_bottomGfx->drawFilledRect(0, 0, 256, 192, COLOUR_BLACK);
			_state = SCREEN_STATE_EXTRA_LIFE;
			_timer = 0;

			if (_block != NULL) {
				delete _block;
			}
			_block = new ExtraLifeBlock(0, 0, NULL);

			break;
		case SCREEN_STATE_EXTRA_LIFE_ERASE:
			_bottomGfx->drawFilledRect(0, 0, 256, 192, COLOUR_BLACK);
			_state = SCREEN_STATE_DIAMOND;
			_timer = 0;

			if (_block != NULL) {
				delete _block;
			}
			_block = new DiamondBlock(0, 0, NULL);

			break;
		case SCREEN_STATE_DIAMOND_ERASE:
			_bottomGfx->drawFilledRect(0, 0, 256, 192, COLOUR_BLACK);
			_state = SCREEN_STATE_BUBBLE;

			_timer = 0;

			if (_block != NULL) {
				delete _block;
			}
			_block = new BubbleBlock(0, 0, NULL);

			break;
		case SCREEN_STATE_BUBBLE_ERASE:
			_bottomGfx->drawFilledRect(0, 0, 256, 192, COLOUR_BLACK);
			_state = SCREEN_STATE_FIRE;
			_timer = 0;

			if (_block != NULL) {
				delete _block;
			}
			_block = new FireBlock(0, 0, NULL);

			break;
		case SCREEN_STATE_FIRE_ERASE:
			_bottomGfx->drawFilledRect(0, 0, 256, 192, COLOUR_BLACK);
			_state = SCREEN_STATE_GRAVITY;
			_timer = 0;

			if (_block != NULL) {
				delete _block;
			}
			_block = new GravityInversionBlock(0, 0, NULL);

			break;
		case SCREEN_STATE_GRAVITY_ERASE:
			_bottomGfx->drawFilledRect(0, 0, 256, 192, COLOUR_BLACK);
			_state = SCREEN_STATE_TELEPORT;
			_timer = 0;

			if (_block != NULL) {
				delete _block;
			}
			_block = new TeleportBlock(0, 0, NULL);

			break;

		default:
			++_timer;

			if (_timer % ANIMATION_TIME == 0) {
				_block->animate();
				_block->render(_blockX, _blockY, _bottomGfx);

				WoopsiGfx::WoopsiString str = "Teleporter";
				_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 160, &_font, str, 0, str.getLength(), COLOUR_WHITE);
			}
	}
}

bool BlockDisplayScreen::isRunning() const {
	return true;
}
