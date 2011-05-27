#ifndef _LEVEL_EDITOR_H_
#define _LEVEL_EDITOR_H_

#include "blockbase.h"
#include "blocktype.h"
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

	BlockBase* _playerBlock;
	BlockBase* _doorBlock;
	ButtonBank* _mainButtonBank;
	LevelEditorPanelBase* _activePanel;
	LevelEditorMapPanel* _mapPanel;
	LevelEditorBlockPanel* _blockPanel;

	void drawPanelBorder();
};

#endif