#include "barrierblock.h"
#include "barriercontrolblock.h"
#include "beanblock.h"
#include "bitmapserver.h"
#include "blockslideshowscreen.h"
#include "boulderblock.h"
#include "bubbleblock.h"
#include "constants.h"
#include "diamondblock.h"
#include "doorblock.h"
#include "extralifeblock.h"
#include "fireblock.h"
#include "gravityinversionblock.h"
#include "spectrumcolours.h"
#include "teleportblock.h"
#include "wetsoilblock.h"

BlockSlideshowScreen::BlockSlideshowScreen(WoopsiGfx::Graphics* gfx) : ScreenBase(NULL, gfx) {
	_block = new TeleportBlock(0, 0, NULL);
	_timer = 0;
	_state = SCREEN_STATE_DOOR_ERASE;
}

BlockSlideshowScreen::~BlockSlideshowScreen() {
	delete _block;
}

void BlockSlideshowScreen::moveToNextState() {
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
			_state = SCREEN_STATE_BARRIER;
			break;
		case SCREEN_STATE_BARRIER:
			_state = SCREEN_STATE_BARRIER_ERASE;
			break;
		case SCREEN_STATE_BARRIER_ERASE:
			_state = SCREEN_STATE_BARRIER_CONTROLLER;
			break;
		case SCREEN_STATE_BARRIER_CONTROLLER:
			_state = SCREEN_STATE_BARRIER_CONTROLLER_ERASE;
			break;
		case SCREEN_STATE_BARRIER_CONTROLLER_ERASE:
			_state = SCREEN_STATE_BOULDER;
			break;
		case SCREEN_STATE_BOULDER:
			_state = SCREEN_STATE_BOULDER_ERASE;
			break;
		case SCREEN_STATE_BOULDER_ERASE:
			_state = SCREEN_STATE_DOOR;
			break;
		case SCREEN_STATE_DOOR:
			_state = SCREEN_STATE_DOOR_ERASE;
			break;
		case SCREEN_STATE_DOOR_ERASE:
			_state = SCREEN_STATE_WET_SOIL;
			break;
		case SCREEN_STATE_WET_SOIL:
			_state = SCREEN_STATE_WET_SOIL_ERASE;
			break;
		case SCREEN_STATE_WET_SOIL_ERASE:
			_state = SCREEN_STATE_TELEPORT;
			break;
	}
}
		
void BlockSlideshowScreen::getNextBlock() {

	if (_block != NULL) {
		delete _block;
		_block = NULL;
	}

	switch (_state) {
		case SCREEN_STATE_BARRIER:
			_block = new BarrierBlock(0, 0, NULL);
			_blockName.setText("Forcefield");
			_blockDescription.setText("Blocks the path");
			break;
		case SCREEN_STATE_BARRIER_CONTROLLER:
			_block = new BarrierControlBlock(0, 0, NULL);
			_blockName.setText("Forcefield Controller");
			_blockDescription.setText("Crush to disable forcefields");
			break;
		case SCREEN_STATE_BEAN:
			_block = new BeanBlock(0, 0, NULL);
			_blockName.setText("Jelly Bean");
			_blockDescription.setText("Collect for extra time");
			break;
		case SCREEN_STATE_BOULDER:
			_block = new BoulderBlock(0, 0, NULL);
			_blockName.setText("Boulder");
			_blockDescription.setText("Dangerous when falling");
			break;
		case SCREEN_STATE_BUBBLE:
			_block = new BubbleBlock(0, 0, NULL);
			_blockName.setText("Bubble");
			_blockDescription.setText("Extinguishes fires");
			break;
		case SCREEN_STATE_DIAMOND:
			_block = new DiamondBlock(0, 0, NULL);
			_blockName.setText("Diamond");
			_blockDescription.setText("Collect to progress");
			break;
		case SCREEN_STATE_DOOR:
			_block = new DoorBlock(0, 0, NULL);
			_blockName.setText("Door");
			_blockDescription.setText("Enter here to exit level");
			break;
		case SCREEN_STATE_EXTRA_LIFE:
			_block = new ExtraLifeBlock(0, 0, NULL);
			_blockName.setText("Elixir");
			_blockDescription.setText("Collect for an extra life");
			break;
		case SCREEN_STATE_FIRE:
			_block = new FireBlock(0, 0, NULL);
			_blockName.setText("Fire");
			_blockDescription.setText("Dangerous to touch");
			break;
		case SCREEN_STATE_GRAVITY:
			_block = new GravityInversionBlock(0, 0, NULL);
			_blockName.setText("Gravity Inverter");
			_blockDescription.setText("Swaps gravity direction");
			break;
		case SCREEN_STATE_TELEPORT:
			_block = new TeleportBlock(0, 0, NULL);
			_blockName.setText("Teleporter");
			_blockDescription.setText("Teleport to a new place");
			break;
		case SCREEN_STATE_WET_SOIL:
			_block = new WetSoilBlock(0, 0, NULL);
			_blockName.setText("Wet Soil");
			_blockDescription.setText("Soil that can fall");
			break;
		default:
			break;
	}
}

void BlockSlideshowScreen::iterate() {
	switch (_state) {
		case SCREEN_STATE_TELEPORT_ERASE:
		case SCREEN_STATE_BEAN_ERASE:
		case SCREEN_STATE_EXTRA_LIFE_ERASE:
		case SCREEN_STATE_DIAMOND_ERASE:
		case SCREEN_STATE_BUBBLE_ERASE:
		case SCREEN_STATE_FIRE_ERASE:
		case SCREEN_STATE_GRAVITY_ERASE:
		case SCREEN_STATE_BARRIER_ERASE:
		case SCREEN_STATE_BARRIER_CONTROLLER_ERASE:
		case SCREEN_STATE_BOULDER_ERASE:
		case SCREEN_STATE_DOOR_ERASE:
		case SCREEN_STATE_WET_SOIL_ERASE:
			_bottomGfx->drawFilledRect(0, 0, 256, 192, COLOUR_BLACK);
			_timer = 0;
			moveToNextState();
			getNextBlock();
			break;

		default:
			++_timer;

			if (_timer % ANIMATION_TIME == 0) {
				_block->animate();
				_block->render(BLOCK_DISPLAY_X, BLOCK_DISPLAY_Y, _bottomGfx);

				_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(_blockName)) / 2, 144, &_font, _blockName, 0, _blockName.getLength(), COLOUR_WHITE);
				_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(_blockDescription)) / 2, 160, &_font, _blockDescription, 0, _blockDescription.getLength(), COLOUR_CYAN);
			}

			if (_timer == BLOCK_DISPLAY_TIME) moveToNextState();
			break;
	}
}

bool BlockSlideshowScreen::isRunning() const {
	return true;
}
