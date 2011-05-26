#ifndef _LEVEL_EDITOR_H_
#define _LEVEL_EDITOR_H_

#include "blockbase.h"
#include "constants.h"
#include "hardware.h"
#include "level.h"
#include "leveldefinition.h"

#include "textbutton.h"
#include "buttonbank.h"
#include "buttonlistener.h"

class LevelEditorBlockPanel;
class LevelEditorMapPanel;
class LevelEditorPanelBase;

class LevelEditor : public ButtonListener {
public:
	LevelEditor();

	~LevelEditor();

	void main();

	void moveCursorTo(s32 x, s32 y);

	void removeBlock();

	void placeBlock();

	void render();

	void drawCursor();

	void handleButtonAction(ButtonBase* source);

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

	enum EditorState {
		STATE_MAP = 0,
		STATE_BLOCK = 1,
		STATE_PALETTE = 2,
		STATE_FILE = 3
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
	BlockBase* _playerBlock;
	ButtonBank* _mainButtonBank;
	LevelEditorPanelBase* _activePanel;
	LevelEditorMapPanel* _mapPanel;
	LevelEditorBlockPanel* _blockPanel;

	void drawPanelBorder();
};

#endif
