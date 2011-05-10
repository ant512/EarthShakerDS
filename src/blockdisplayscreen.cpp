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

void BlockDisplayScreen::moveToNextState() {
	switch (_state) {
		case SCREEN_STATE_TELEPORT:
			_state = SCREEN_STATE_TELEPORT_ERASE;
			break;
		case SCREEN_STATE_TELEPORT_ERASE:
			_state = SCREEN_STATE_BEAN;
			break;
		case SCREEN_STATE_BEAN:
			_state = SCREEN_STATE_BEAN_ERASE;
			break;
		case SCREEN_STATE_BEAN_ERASE:
			_state = SCREEN_STATE_EXTRA_LIFE;
			break;
		case SCREEN_STATE_EXTRA_LIFE:
			_state = SCREEN_STATE_EXTRA_LIFE_ERASE;
			break;
		case SCREEN_STATE_EXTRA_LIFE_ERASE:
			_state = SCREEN_STATE_DIAMOND;
			break;
		case SCREEN_STATE_DIAMOND:
			_state = SCREEN_STATE_DIAMOND_ERASE;
			break;
		case SCREEN_STATE_DIAMOND_ERASE:
			_state = SCREEN_STATE_BUBBLE;
			break;
		case SCREEN_STATE_BUBBLE:
			_state = SCREEN_STATE_BUBBLE_ERASE;
			break;
		case SCREEN_STATE_BUBBLE_ERASE:
			_state = SCREEN_STATE_FIRE;
			break;
		case SCREEN_STATE_FIRE:
			_state = SCREEN_STATE_FIRE_ERASE;
			break;
		case SCREEN_STATE_FIRE_ERASE:
			_state = SCREEN_STATE_GRAVITY;
			break;
		case SCREEN_STATE_GRAVITY:
			_state = SCREEN_STATE_GRAVITY_ERASE;
			break;
		case SCREEN_STATE_GRAVITY_ERASE:
			_state = SCREEN_STATE_TELEPORT;
			break;
	}
}
		
void BlockDisplayScreen::getNextBlock() {

	if (_block != NULL) {
		delete _block;
		_block = NULL;
	}

	switch (_state) {
		case SCREEN_STATE_BEAN:
			_block = new BeanBlock(0, 0, NULL);
			_blockName.setText("Jelly Bean");
			break;
		case SCREEN_STATE_BUBBLE:
			_block = new BubbleBlock(0, 0, NULL);
			_blockName.setText("Bubble");
			break;
		case SCREEN_STATE_DIAMOND:
			_block = new DiamondBlock(0, 0, NULL);
			_blockName.setText("Diamond");
			break;
		case SCREEN_STATE_EXTRA_LIFE:
			_block = new ExtraLifeBlock(0, 0, NULL);
			_blockName.setText("Extra Life");
			break;
		case SCREEN_STATE_FIRE:
			_block = new FireBlock(0, 0, NULL);
			_blockName.setText("Fire");
			break;
		case SCREEN_STATE_GRAVITY:
			_block = new GravityInversionBlock(0, 0, NULL);
			_blockName.setText("Gravity Inverter");
			break;
		case SCREEN_STATE_TELEPORT:
			_block = new TeleportBlock(0, 0, NULL);
			_blockName.setText("Teleporter");
			break;
		default:
			break;
	}
}

void BlockDisplayScreen::iterate(PadState pad) {

	switch (_state) {
		case SCREEN_STATE_TELEPORT_ERASE:
		case SCREEN_STATE_BEAN_ERASE:
		case SCREEN_STATE_EXTRA_LIFE_ERASE:
		case SCREEN_STATE_DIAMOND_ERASE:
		case SCREEN_STATE_BUBBLE_ERASE:
		case SCREEN_STATE_FIRE_ERASE:
		case SCREEN_STATE_GRAVITY_ERASE:
			_bottomGfx->drawFilledRect(0, 0, 256, 192, COLOUR_BLACK);
			_timer = 0;
			moveToNextState();
			getNextBlock();
			break;

		default:
			++_timer;

			if (_timer % ANIMATION_TIME == 0) {
				_block->animate();
				_block->render(_blockX, _blockY, _bottomGfx);

				_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(_blockName)) / 2, 160, &_font, _blockName, 0, _blockName.getLength(), COLOUR_WHITE);
			}

			if (_timer == BLOCK_DISPLAY_TIME) moveToNextState();
			break;
	}
}

bool BlockDisplayScreen::isRunning() const {
	return true;
}
