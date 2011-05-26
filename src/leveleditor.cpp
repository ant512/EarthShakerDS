#include "leveleditor.h"

#include "barrierblock.h"
#include "barriercontrolblock.h"
#include "beanblock.h"
#include "blockbase.h"
#include "boulderblock.h"
#include "bubbleblock.h"
#include "constants.h"
#include "diamondblock.h"
#include "doorblock.h"
#include "extralifeblock.h"
#include "fireblock.h"
#include "gravityinversionblock.h"
#include "hardware.h"
#include "level.h"
#include "leveldefinition.h"
#include "playerblock.h"
#include "soilblock.h"
#include "teleportblock.h"
#include "wallblock.h"
#include "wetsoilblock.h"

#include "textbutton.h"
#include "buttonbank.h"
#include "buttonlistener.h"
#include "leveleditorpanelbase.h"
#include "leveleditorblockpanel.h"
#include "leveleditormappanel.h"

LevelEditor::LevelEditor() {
	_topGfx = Hardware::getTopGfx();
	_bottomGfx = Hardware::getBottomGfx();

	_level = new Level(LEVEL_WIDTH, LEVEL_HEIGHT, 0, "Test");

	_playerBlock = NULL;

	_paintBlock = BLOCK_TYPE_BUBBLE;
	_cursorX = 0;
	_cursorY = 0;
	_timer = 0;

	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	_bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	_mainButtonBank = new ButtonBank(this);
	_mainButtonBank->addButton(new TextButton(2, 180, 60, 10, STATE_MAP, "Map"));
	_mainButtonBank->addButton(new TextButton(66, 180, 60, 10, STATE_BLOCK, "Block"));
	_mainButtonBank->addButton(new TextButton(130, 180, 60, 10, STATE_PALETTE, "Palette"));
	_mainButtonBank->addButton(new TextButton(194, 180, 60, 10, STATE_FILE, "File"));

	_mainButtonBank->render(_bottomGfx);

	render();

	drawPanelBorder();

	_mapPanel = new LevelEditorMapPanel(_bottomGfx, _level);
	_blockPanel = new LevelEditorBlockPanel(_bottomGfx, this);

	_activePanel = _mapPanel;

	// Wait for A to be released
	const PadState& pad = Hardware::getPadState();

	while(pad.a) {
		Hardware::waitForVBlank();
	}
}

LevelEditor::~LevelEditor() {
	delete _mainButtonBank;
	delete _level;
}

void LevelEditor::main() {
	while (1) {

		Hardware::waitForVBlank();

		// Update stylus stuff every frame
		const StylusState& stylus = Hardware::getStylusState();

		if (stylus.newPress) {
			_mainButtonBank->click(stylus.x, stylus.y);
		}

		++_timer;

		if (_timer < ANIMATION_TIME) continue;

		_timer = 0;

		_activePanel->iterate();

		const PadState& pad = Hardware::getPadState();

		if (pad.a) {
			placeBlock();
		}

		if (pad.b) {
			removeBlock();
		}

		if (pad.up) {
			moveCursorTo(_cursorX, _cursorY - 1);
		} else if (pad.down) {
			moveCursorTo(_cursorX, _cursorY + 1);
		}

		if (pad.left) {
			moveCursorTo(_cursorX - 1, _cursorY);
		} else if (pad.right) {
			moveCursorTo(_cursorX + 1, _cursorY);
		}

		render();
	}
}

void LevelEditor::moveCursorTo(s32 x, s32 y) {
	_cursorX = x;
	_cursorY = y;

	if (_cursorY < 0) {
		_cursorY = 0;
	} else  if (_cursorY >= _level->getHeight()) {
		_cursorY = _level->getHeight() - 1;
	}

	if (_cursorX < 0) {
		_cursorX = 0;
	} else if (_cursorX >= _level->getWidth()) {
		_cursorX = _level->getWidth() - 1;
	}
}

void LevelEditor::removeBlock() {
	// If we're removing the player block we need to forget it
	if ((_playerBlock->getX() == _cursorX) && (_playerBlock->getY() == _cursorY)) {
		_playerBlock = NULL;
	}

	_level->removeBlockAt(_cursorX, _cursorY);
}

void LevelEditor::placeBlock() {
	BlockBase* block = NULL;

	// If we're overwriting the player block we need to forget it
	if ((_playerBlock->getX() == _cursorX) && (_playerBlock->getY() == _cursorY)) {
		_playerBlock = NULL;
	}

	switch (_paintBlock) {
		case BLOCK_TYPE_NULL:
			break;
		case BLOCK_TYPE_PLAYER:
			block = new PlayerBlock(_cursorX, _cursorY, NULL);

			// We need to ensure that there is only a single player per
			// level
			if (_playerBlock != NULL) {
				_level->removeBlockAt(_playerBlock->getX(), _playerBlock->getY());
			}
			
			_playerBlock = block;	
			break;
		case BLOCK_TYPE_DIAMOND:
			block = new DiamondBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_BUBBLE:
			block = new BubbleBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_FIRE:
			block = new FireBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_BEAN:
			block = new BeanBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_GRAVITY:
			block = new GravityInversionBlock(_cursorX, _cursorY, NULL);
			break;

		case BLOCK_TYPE_BOULDER:
			block = new BoulderBlock(_cursorX, _cursorY, NULL);
			break;
		default:
			break;
	}

	_level->removeBlockAt(_cursorX, _cursorY);
	_level->setBlockAt(_cursorX, _cursorY, block);
	_level->deleteRemovedBlocks();
}

void LevelEditor::render() {
	_level->animate();
	_level->render(_cursorX, _cursorY, _topGfx);
	drawCursor();

	_mainButtonBank->render(_bottomGfx);
}

void LevelEditor::drawCursor() {
	// Get the size of the display measured in blocks
	s32 numBlocksX = GAME_WIDTH / BlockBase::BLOCK_SIZE;
	s32 numBlocksY = GAME_HEIGHT / BlockBase::BLOCK_SIZE;

	// Get the top-left corner based on the assumption that the cursor is
	// at the centre of the screen
	s32 blockX = _cursorX - (numBlocksX / 2);
	s32 blockY = _cursorY - (numBlocksY / 2);

	// Prevent scrolling past the end of the level.  The central point will
	// not be at the centre of the screen
	if (blockX + numBlocksX > _level->getWidth()) blockX = _level->getWidth() - numBlocksX;
	if (blockX < 0) blockX = 0;

	if (blockY + numBlocksY > _level->getHeight()) blockY = _level->getHeight() - numBlocksY;
	if (blockY < 0) blockY = 0;

	_topGfx->drawXORRect((_cursorX - blockX) * BlockBase::BLOCK_SIZE, (_cursorY - blockY) * BlockBase::BLOCK_SIZE, BlockBase::BLOCK_SIZE, BlockBase::BLOCK_SIZE);
}

void LevelEditor::handleButtonAction(ButtonBase* source) {
	_activePanel->erase();

	switch (source->getId()) {
		case STATE_MAP:
			_activePanel = _mapPanel;
			break;
		case STATE_BLOCK:
			_activePanel = _blockPanel;
			break;
		case STATE_PALETTE:
			break;
		case STATE_FILE:
			break;
	}
}

void LevelEditor::drawPanelBorder() {
	// Top border
	_bottomGfx->drawLine(5, 4, 250, 4, COLOUR_MAGENTA);
	_bottomGfx->drawLine(4, 5, 251, 5, COLOUR_MAGENTA);

	// Left border
	_bottomGfx->drawLine(4, 5, 4, 170, COLOUR_MAGENTA);
	_bottomGfx->drawLine(5, 5, 5, 170, COLOUR_MAGENTA);

	// Right border
	_bottomGfx->drawLine(250, 5, 250, 170, COLOUR_MAGENTA);
	_bottomGfx->drawLine(251, 5, 251, 170, COLOUR_MAGENTA);

	// Bottom border
	_bottomGfx->drawLine(5, 171, 250, 171, COLOUR_MAGENTA);
	_bottomGfx->drawLine(4, 170, 250, 170, COLOUR_MAGENTA);
}
