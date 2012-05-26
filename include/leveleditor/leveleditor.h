#ifndef _LEVEL_EDITOR_H_
#define _LEVEL_EDITOR_H_

#include "blockbase.h"
#include "blocktype.h"
#include "constants.h"
#include "hardware.h"
#include "level.h"
#include "leveldefinitionbase.h"

#include "textbutton.h"
#include "buttonbank.h"
#include "buttonlistener.h"

#include "levelio.h"

class LevelEditorFilePanel;
class LevelEditorMapPanel;
class LevelEditorOptionsPanel;
class LevelEditorPanelBase;
class LevelEditorBlockSelector;

/**
 * The level editor.
 */
class LevelEditor : public ButtonListener {
public:

	/**
	 * Constructor.
	 */
	LevelEditor();

	/**
	 * Destructor.
	 */
	~LevelEditor();

	/**
	 * Runs all level editor logic.
	 */
	void main();

	/**
	 * Tests the current level.
	 */
	void testLevel();

	/**
	 * Blanks the current level.
	 */
	void resetLevel();
	
	/**
	 * Listens for button presses on lower screen and responds appropriately.
	 * @param source The button that raised the event.
	 */
	void handleButtonAction(ButtonBase* source);

	void saveLevel(const WoopsiGfx::WoopsiString& filename);
	void loadLevel(const WoopsiGfx::WoopsiString& filename);
	void deleteLevel(const WoopsiGfx::WoopsiString& filename);

private:

	enum PanelType {
		PANEL_MAP = 0,
		PANEL_PALETTE = 1,
		PANEL_FILE = 2
	};

	static const s32 LEVEL_WIDTH = 30;
	static const s32 LEVEL_HEIGHT = 20;

	WoopsiGfx::Graphics* _topGfx;			/**< Pointer to the graphics object for the top display. */
	WoopsiGfx::Graphics* _bottomGfx;		/**< Pointer to the graphics object for the bottom display. */

	Level* _level;							/**< The currently-active level.*/
	s32 _animationTimer;
	s32 _movementTimer;

	s32 _cursorX;
	s32 _cursorY;

	ButtonBank* _buttons;

	LevelEditorFilePanel* _filePanel;
	LevelEditorOptionsPanel* _optionsPanel;
	LevelEditorPanelBase* _activePanel;
	LevelEditorMapPanel* _mapPanel;

	LevelEditorBlockSelector* _blockSelector;

	u8* _levelData;

	void drawPanelBorder();

	void redrawAll();

	void moveCursorTo(s32 x, s32 y);

	void removeBlock();

	void placeBlock();

	void render();

	void drawCursor();
};

#endif
