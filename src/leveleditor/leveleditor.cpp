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
#include "leveleditorfilepanel.h"
#include "leveleditorblockpanel.h"
#include "leveleditorpalettepanel.h"
#include "leveleditormappanel.h"
#include "levelfactory.h"

LevelEditor::LevelEditor() {
	_topGfx = Hardware::getTopGfx();
	_bottomGfx = Hardware::getBottomGfx();

	_level = new Level(LEVEL_WIDTH, LEVEL_HEIGHT, 0, "Test");

	_cursorX = 0;
	_cursorY = 0;
	_timer = 0;

	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	_bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	_buttons = new ButtonBank(this, _bottomGfx);
	_buttons->addButton(new TextButton(2, 174, 60, 16, PANEL_MAP, "Map"));
	_buttons->addButton(new TextButton(66, 174, 60, 16, PANEL_BLOCK, "Block"));
	_buttons->addButton(new TextButton(130, 174, 60, 16, PANEL_PALETTE, "Palette"));
	_buttons->addButton(new TextButton(194, 174, 60, 16, PANEL_FILE, "File"));

	_buttons->render();

	render();

	drawPanelBorder();

	_blockPanel = new LevelEditorBlockPanel(_bottomGfx, this);
	_palettePanel = new LevelEditorPalettePanel(_bottomGfx);
	_mapPanel = new LevelEditorMapPanel(_bottomGfx, _level);
	_filePanel = new LevelEditorFilePanel(_bottomGfx);

	_activePanel = _mapPanel;

	// Wait for A to be released
	const PadState& pad = Hardware::getPadState();

	while(pad.a) {
		Hardware::waitForVBlank();
	}
}

LevelEditor::~LevelEditor() {
	delete _buttons;
	delete _blockPanel;
	delete _palettePanel;
	delete _mapPanel;
	delete _filePanel;
	delete _level;
}

void LevelEditor::main() {
	while (1) {

		Hardware::waitForVBlank();

		_buttons->iterate();
		_activePanel->iterate();

		++_timer;

		if (_timer < ANIMATION_TIME) continue;

		_timer = 0;

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
	
	if ((_level->getPlayerBlock()->getX() == _cursorX) && (_level->getPlayerBlock()->getY() == _cursorY)) {
		// If we're removing the player block we need to forget it
		_level->setPlayerBlock(NULL);
	} else if ((_level->getDoorBlock()->getX() == _cursorX) && (_level->getDoorBlock()->getY() == _cursorY)) {

		// If we're overwriting the door block we need to forget it
		_level->setDoorBlock(NULL);
	}

	_level->removeBlockAt(_cursorX, _cursorY);
}

void LevelEditor::placeBlock() {
	LevelFactory::placeBlock(_level, _blockPanel->getSelectedBlockType(), _cursorX, _cursorY, NULL);
}

void LevelEditor::render() {
	_level->animate();
	_level->render(_cursorX, _cursorY, _topGfx);
	drawCursor();
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
		case PANEL_MAP:
			_activePanel = _mapPanel;
			break;
		case PANEL_BLOCK:
			_activePanel = _blockPanel;
			break;
		case PANEL_PALETTE:
			_activePanel = _palettePanel;
			break;
		case PANEL_FILE:
		_activePanel = _filePanel;
			break;
	}

	_activePanel->render();
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
