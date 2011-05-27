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
	_doorBlock = NULL;

	_cursorX = 0;
	_cursorY = 0;
	_timer = 0;

	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	_bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	_mainButtonBank = new ButtonBank(this, _bottomGfx);
	_mainButtonBank->addButton(new TextButton(2, 174, 60, 16, STATE_MAP, "Map"));
	_mainButtonBank->addButton(new TextButton(66, 174, 60, 16, STATE_BLOCK, "Block"));
	_mainButtonBank->addButton(new TextButton(130, 174, 60, 16, STATE_PALETTE, "Palette"));
	_mainButtonBank->addButton(new TextButton(194, 174, 60, 16, STATE_FILE, "File"));

	_mainButtonBank->render();

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

		_mainButtonBank->iterate();
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
	// If we're removing the player block we need to forget it
	if ((_playerBlock->getX() == _cursorX) && (_playerBlock->getY() == _cursorY)) {
		_playerBlock = NULL;
	}

	_level->removeBlockAt(_cursorX, _cursorY);
}

void LevelEditor::placeBlock() {
	BlockBase* block = NULL;

	if ((_playerBlock->getX() == _cursorX) && (_playerBlock->getY() == _cursorY)) {

		// If we're overwriting the player block we need to forget it
		_playerBlock = NULL;
	} else if ((_doorBlock->getX() == _cursorX) && (_doorBlock->getY() == _cursorY)) {

		// If we're overwriting the door block we need to forget it
		_doorBlock = NULL;
	}

	switch (_blockPanel->getSelectedBlockType()) {
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
		case BLOCK_TYPE_EXTRA_LIFE:
			block = new ExtraLifeBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_BARRIER:
			block = new BarrierBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_BARRIER_CONTROL:
			block = new BarrierControlBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_TELEPORT:
			block = new TeleportBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_DOOR_BLUE:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getBlueDoorBmp());

			// We need to ensure that there is only a single door per level
			if (_doorBlock != NULL) {
				_level->removeBlockAt(_doorBlock->getX(), _doorBlock->getY());
			}
			
			_doorBlock = block;
			break;
		case BLOCK_TYPE_DOOR_CYAN:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getCyanDoorBmp());

			// We need to ensure that there is only a single door per level
			if (_doorBlock != NULL) {
				_level->removeBlockAt(_doorBlock->getX(), _doorBlock->getY());
			}
			
			_doorBlock = block;
			break;
		case BLOCK_TYPE_DOOR_GREEN:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getGreenDoorBmp());

			// We need to ensure that there is only a single door per level
			if (_doorBlock != NULL) {
				_level->removeBlockAt(_doorBlock->getX(), _doorBlock->getY());
			}
			
			_doorBlock = block;
			break;
		case BLOCK_TYPE_DOOR_MAGENTA:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getMagentaDoorBmp());

			// We need to ensure that there is only a single door per level
			if (_doorBlock != NULL) {
				_level->removeBlockAt(_doorBlock->getX(), _doorBlock->getY());
			}
			
			_doorBlock = block;
			break;
		case BLOCK_TYPE_DOOR_RED:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getRedDoorBmp());

			// We need to ensure that there is only a single door per level
			if (_doorBlock != NULL) {
				_level->removeBlockAt(_doorBlock->getX(), _doorBlock->getY());
			}
			
			_doorBlock = block;
			break;
		case BLOCK_TYPE_DOOR_YELLOW:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getYellowDoorBmp());

			// We need to ensure that there is only a single door per level
			if (_doorBlock != NULL) {
				_level->removeBlockAt(_doorBlock->getX(), _doorBlock->getY());
			}
			
			_doorBlock = block;
			break;
		case BLOCK_TYPE_BOULDER:
			block = new BoulderBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_WALL_BRICK:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getBrickWallBmp());
			break;
		case BLOCK_TYPE_WALL_ICE:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getIceWallBmp());
			break;
		case BLOCK_TYPE_WALL_METAL:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getMetalWallBmp());
			break;
		case BLOCK_TYPE_WALL_BRAIN:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getBrainWallBmp());
			break;
		case BLOCK_TYPE_WALL_GIRDER:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getGirderWallBmp());
			break;
		case BLOCK_TYPE_WALL_HEART:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getHeartWallBmp());
			break;
		case BLOCK_TYPE_WALL_HONEYCOMB:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getHoneycombWallBmp());
			break;
		case BLOCK_TYPE_WALL_LEAFY:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getLeafyWallBmp());
			break;
		case BLOCK_TYPE_WALL_NUCLEAR:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getNuclearWallBmp());
			break;
		case BLOCK_TYPE_WALL_PIPE:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getPipeWallBmp());
			break;
		case BLOCK_TYPE_WALL_QUESTION:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getQuestionWallBmp());
			break;
		case BLOCK_TYPE_WALL_SAND:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getSandWallBmp());
			break;
		case BLOCK_TYPE_WALL_SQUARE:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getSquareWallBmp());
			break;
		case BLOCK_TYPE_SOIL:
			block = new SoilBlock(_cursorX, _cursorY, NULL, BitmapServer::getSoilBmp());
			break;
		case BLOCK_TYPE_SOIL_HONEYCOMB:
			block = new SoilBlock(_cursorX, _cursorY, NULL, BitmapServer::getHoneycombSoilBmp());
			break;
		case BLOCK_TYPE_SOIL_QUESTION:
			block = new SoilBlock(_cursorX, _cursorY, NULL, BitmapServer::getQuestionWallBmp());
			break;
		case BLOCK_TYPE_SOIL_WET:
			block = new WetSoilBlock(_cursorX, _cursorY, NULL);
			break;
		case BLOCK_TYPE_DOOR_WHITE:
			block = new DoorBlock(_cursorX, _cursorY, NULL, BitmapServer::getWhiteDoorBmp());

			// We need to ensure that there is only a single door per level
			if (_doorBlock != NULL) {
				_level->removeBlockAt(_doorBlock->getX(), _doorBlock->getY());
			}
			
			_doorBlock = block;
			break;
		case BLOCK_TYPE_SOIL_BOULDER:
			block = new SoilBlock(_cursorX, _cursorY, NULL, BitmapServer::getBoulderBmp());
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
