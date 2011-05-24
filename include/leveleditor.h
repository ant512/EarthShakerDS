#ifndef _LEVEL_EDITOR_H_
#define _LEVEL_EDITOR_H_

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

class LevelEditor {
public:
	LevelEditor() {
		_topGfx = Hardware::getTopGfx();
		_bottomGfx = Hardware::getBottomGfx();

		_level = new Level(LEVEL_WIDTH, LEVEL_HEIGHT, 0, "Test");

		_paintBlock = BLOCK_TYPE_BOULDER;
		_cursorX = 0;
		_cursorY = 0;
		_timer = 0;

		render();
	};

	~LevelEditor() { };

	void main() {
		while (1) {

			Hardware::waitForVBlank();

			++_timer;

			if (_timer < ANIMATION_TIME) continue;

			_timer = 0;

			const PadState& pad = Hardware::getPadState();

			if (pad.a) {
				placeBlock();
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
		}
	};

	void moveCursorTo(s32 x, s32 y) {
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

		render();
	}

	void placeBlock() {
		BlockBase* newBlock;

		switch (_paintBlock) {
			case BLOCK_TYPE_NULL:
				break;
			case BLOCK_TYPE_BOULDER:
				newBlock = new BoulderBlock(_cursorX, _cursorY, NULL);
				break;
			default:
				break;
		}

		_level->removeBlockAt(_cursorX, _cursorY);
		_level->setBlockAt(_cursorX, _cursorY, newBlock);

		render();
	};

	void render() {
		_level->render(_cursorX, _cursorY, _topGfx);
		drawCursor();
	};

	void drawCursor() {
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

		_topGfx->drawFilledXORRect((_cursorX - blockX) * BlockBase::BLOCK_SIZE, (_cursorY - blockY) * BlockBase::BLOCK_SIZE, BlockBase::BLOCK_SIZE, BlockBase::BLOCK_SIZE);
	};

private:

	enum BlockType {
		BLOCK_TYPE_NULL = 0,
		BLOCK_TYPE_PLAYER = 1,
		BLOCK_TYPE_DIAMOND = 2,
		BLOCK_TYPE_BUBBLE = 3,
		BLOCK_TYPE_FIRE = 4,
		BLOCK_TYPE_BEAN = 5,
		BLOCK_TYPE_GRAVITY = 6,
		BLOCK_TYPE_EXTRA_LIFE = 7,
		BLOCK_TYPE_BARRIER = 8,
		BLOCK_TYPE_BARRIER_CONTROL = 9,
		BLOCK_TYPE_TELEPORT = 10,
		BLOCK_TYPE_DOOR_BLUE = 11,
		BLOCK_TYPE_DOOR_CYAN = 12,
		BLOCK_TYPE_DOOR_GREEN = 13,
		BLOCK_TYPE_DOOR_MAGENTA = 14,
		BLOCK_TYPE_DOOR_RED = 15,
		BLOCK_TYPE_DOOR_YELLOW = 16,
		BLOCK_TYPE_BOULDER = 17,
		BLOCK_TYPE_WALL_BRICK = 18,
		BLOCK_TYPE_WALL_ROCK = 19,
		BLOCK_TYPE_WALL_ICE = 20,
		BLOCK_TYPE_WALL_METAL = 21,
		BLOCK_TYPE_WALL_BRAIN = 22,
		BLOCK_TYPE_WALL_GIRDER = 23,
		BLOCK_TYPE_WALL_HEART = 24,
		BLOCK_TYPE_WALL_HONEYCOMB = 25,
		BLOCK_TYPE_WALL_LEAFY = 26,
		BLOCK_TYPE_WALL_NUCLEAR = 27,
		BLOCK_TYPE_WALL_PIPE = 28,
		BLOCK_TYPE_WALL_QUESTION = 29,
		BLOCK_TYPE_WALL_SAND = 30,
		BLOCK_TYPE_WALL_SQUARE = 31,
		BLOCK_TYPE_SOIL = 32,
		BLOCK_TYPE_SOIL_HONEYCOMB = 33,
		BLOCK_TYPE_SOIL_QUESTION = 34,
		BLOCK_TYPE_SOIL_WET = 35,
		BLOCK_TYPE_DOOR_WHITE = 36,
		BLOCK_TYPE_SOIL_BOULDER = 37
	};

	static const s32 LEVEL_WIDTH = 30;
	static const s32 LEVEL_HEIGHT = 20;

	WoopsiGfx::Graphics* _topGfx;			/**< Pointer to the graphics object for the top display. */
	WoopsiGfx::Graphics* _bottomGfx;		/**< Pointer to the graphics object for the bottom display. */

	Level* _level;							/**< The currently-active level.*/
	s32 _timer;

	s32 _cursorX;
	s32 _cursorY;

	BlockType _paintBlock;
};

#endif
