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
#include "leveldefinitionbase.h"
#include "immutableleveldefinition.h"
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
#include "leveleditoroptionspanel.h"
#include "leveleditormappanel.h"
#include "levelfactory.h"

#include "leveleditorblockselector.h"

#include "soundplayer.h"

#include "leveldefinitions.h"

LevelEditor::LevelEditor() {
	_topGfx = Hardware::getTopGfx();
	_bottomGfx = Hardware::getBottomGfx();

	BitmapServer::changeBoulderBmp(BOULDER_TYPE_YELLOW);
	BitmapServer::changeSoilBmp(SOIL_TYPE_BLUE);
	BitmapServer::changeWallBmp(WALL_TYPE_BRICK_RED);
	BitmapServer::changeDoorBmp(DOOR_TYPE_GREEN);

	_level = new Level(LEVEL_WIDTH, LEVEL_HEIGHT, 0, "Test");

	_levelData = new u8[LEVEL_WIDTH * LEVEL_HEIGHT];

	resetLevel();

	_blockSelector = new LevelEditorBlockSelector(_topGfx);

	_cursorX = 0;
	_cursorY = 0;
	_animationTimer = 0;
	_movementTimer = 0;

	_buttons = new ButtonBank(this, _bottomGfx);
	_buttons->addButton(new TextButton(2, 174, 80, 16, PANEL_MAP, "Map"));
	_buttons->addButton(new TextButton(88, 174, 80, 16, PANEL_PALETTE, "Options"));
	_buttons->addButton(new TextButton(174, 174, 80, 16, PANEL_FILE, "File"));

	_optionsPanel = new LevelEditorOptionsPanel(_bottomGfx, this);
	_mapPanel = new LevelEditorMapPanel(_bottomGfx, _level);
	_filePanel = new LevelEditorFilePanel(_bottomGfx, this);

	_activePanel = _mapPanel;

	redrawAll();
}

LevelEditor::~LevelEditor() {
	delete _buttons;
	delete _optionsPanel;
	delete _mapPanel;
	delete _filePanel;
	delete _level;
	delete _blockSelector;
	delete[] _levelData;
}

void LevelEditor::main() {
	while (_optionsPanel->isRunning()) {

		Hardware::waitForVBlank();

		_buttons->iterate();
		_activePanel->iterate();

		render();
		
		const Pad& pad = Hardware::getPad();
		
		if (pad.isStartNewPress()) {
			while (pad.isStartHeld()) {
				Hardware::waitForVBlank();
			}
			
			testLevel();
		}
		
		if (pad.isSelectNewPress()) {
			_activePanel->erase();
			
			if (_activePanel == _mapPanel) {
				_activePanel = _optionsPanel;
			} else if (_activePanel == _optionsPanel) {
				_activePanel = _filePanel;
			} else if (_activePanel == _filePanel) {
				_activePanel = _mapPanel;
			}
			
			_activePanel->render();
		}
		
		++_movementTimer;

		if (_movementTimer < MOVEMENT_TIME) continue;

		_movementTimer = 0;

		_blockSelector->iterate();

		if (pad.isAHeld()) {
			placeBlock();
		}

		if (pad.isBHeld()) {
			removeBlock();
		}

		if (pad.isUpHeld()) {
			moveCursorTo(_cursorX, _cursorY - 1);
		} else if (pad.isDownHeld()) {
			moveCursorTo(_cursorX, _cursorY + 1);
		}

		if (pad.isLeftHeld()) {
			moveCursorTo(_cursorX - 1, _cursorY);
		} else if (pad.isRightHeld()) {
			moveCursorTo(_cursorX + 1, _cursorY);
		}
	}
	
	// Reload custom level definitions so that the main menu shows the correct
	// data
	LevelDefinitions::loadCustomLevels();
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

	// Move the map panel cursor
	if (_activePanel == _mapPanel) {
		((LevelEditorMapPanel*)_activePanel)->moveCursorTo(_cursorX, _cursorY);
	}
}

void LevelEditor::removeBlock() {

	s32 dataIndex = (_cursorY * LEVEL_WIDTH) + _cursorX;
	
	if (_levelData[dataIndex] == BLOCK_TYPE_NULL) return;

	if (_level->getPlayerBlock() != NULL) {
		if ((_level->getPlayerBlock()->getX() == _cursorX) && (_level->getPlayerBlock()->getY() == _cursorY)) {
			// If we're removing the player block we need to forget it
			_level->setPlayerBlock(NULL);
		}
	}
	
	if (_level->getDoorBlock() != NULL) {
		if ((_level->getDoorBlock()->getX() == _cursorX) && (_level->getDoorBlock()->getY() == _cursorY)) {

			// If we're removing the door block we need to forget it
			_level->setDoorBlock(NULL);
		}
	}

	_level->removeBlockAt(_cursorX, _cursorY);
	_level->deleteRemovedBlocks();

	_levelData[dataIndex] = BLOCK_TYPE_NULL;

	SoundPlayer::playSoilPoke();
}

void LevelEditor::placeBlock() {
	
	BlockType type = _blockSelector->getSelectedBlockType();
	s32 dataIndex = (_cursorY * LEVEL_WIDTH) + _cursorX;
	
	// Don't place the block if the existing block at these co-ords is the same
	if (_levelData[dataIndex] == type) return;
	
	// We need to wipe out the existing player block in the local data cache if
	// we're placing it in a new location, or we'll end up with a discrepancy
	// between the level and the cache.
	if (type == BLOCK_TYPE_PLAYER && _level->getPlayerBlock() != NULL) {
		_levelData[(_level->getPlayerBlock()->getY() * LEVEL_WIDTH) + _level->getPlayerBlock()->getX()] = BLOCK_TYPE_NULL;
	}
	
	// Ditto for doors
	if (type == BLOCK_TYPE_DOOR && _level->getDoorBlock() != NULL) {
		_levelData[(_level->getDoorBlock()->getY() * LEVEL_WIDTH) + _level->getDoorBlock()->getX()] = BLOCK_TYPE_NULL;
	}

	if (type != _levelData[dataIndex]) {
		LevelFactory::placeBlock(_level, type, _cursorX, _cursorY, NULL);
		_levelData[dataIndex] = type;

		SoundPlayer::playBlockLand();
	}
}

void LevelEditor::render() {

	++_animationTimer;

	if (_animationTimer < ANIMATION_TIME) return;

	_animationTimer = 0;

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

	_topGfx->drawRect((_cursorX - blockX) * BlockBase::BLOCK_SIZE, (_cursorY - blockY) * BlockBase::BLOCK_SIZE, BlockBase::BLOCK_SIZE, BlockBase::BLOCK_SIZE, COLOUR_WHITE);
}

void LevelEditor::handleButtonAction(ButtonBase* source) {
	_activePanel->erase();

	switch (source->getId()) {
		case PANEL_MAP:
			_activePanel = _mapPanel;
			break;
		case PANEL_PALETTE:
			_activePanel = _optionsPanel;
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

void LevelEditor::testLevel() {
	
	// Prevent the level running if we don't have a start and an exit
	if (_level->getPlayerBlock() == NULL || _level->getDoorBlock() == NULL) {
		SoundPlayer::playPlayerExplode();
		return;
	}
	
	WoopsiArray<LevelDefinitionBase*> levels;
	ImmutableLevelDefinition def(LEVEL_WIDTH, LEVEL_HEIGHT, 1, "test",
								 _levelData, BOULDER_TYPE_YELLOW,
								 WALL_TYPE_BRICK_RED, SOIL_TYPE_BLUE,
								 DOOR_TYPE_GREEN);
	levels.push_back(&def);
	
	GameSession* session = new GameSession();
	session->run(&def);
	delete session;

	redrawAll();
}

void LevelEditor::redrawAll() {
	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	_bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	_buttons->render();
	_blockSelector->render();
	render();
	drawPanelBorder();

	_activePanel->render();
}

void LevelEditor::resetLevel() {
	_level->clear();

	for (s32 i = 0; i < LEVEL_WIDTH * LEVEL_HEIGHT; ++i) {
		_levelData[i] = BLOCK_TYPE_NULL;
	}
}

void LevelEditor::saveLevel(const WoopsiGfx::WoopsiString& filename) {
	ImmutableLevelDefinition def(LEVEL_WIDTH, LEVEL_HEIGHT, 1, filename,
								 _levelData, _optionsPanel->getBoulderType(),
								 _optionsPanel->getWallType(), _optionsPanel->getSoilType(),
								 _optionsPanel->getDoorType());

	LevelIO::save(&def);
}

void LevelEditor::loadLevel(const WoopsiGfx::WoopsiString& filename) {
	resetLevel();

	LevelDefinitionBase* def = LevelIO::load(filename);

	if (def == NULL) return;

	for (s32 i = 0; i < LEVEL_WIDTH * LEVEL_HEIGHT; ++i) {
		_levelData[i] = def->getLayout()[i];
		LevelFactory::placeBlock(_level, (BlockType)_levelData[i], i % LEVEL_WIDTH, i / LEVEL_WIDTH, NULL);

	}
	
	// Set up level options
	BitmapServer::changeBoulderBmp(def->getBoulderType());
	BitmapServer::changeSoilBmp(def->getSoilType());
	BitmapServer::changeWallBmp(def->getWallType());
	BitmapServer::changeDoorBmp(def->getDoorType());

	delete def;

	redrawAll();
}

