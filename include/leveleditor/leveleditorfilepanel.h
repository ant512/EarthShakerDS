#ifndef _LEVEL_EDITOR_FILE_PANEL_H_
#define _LEVEL_EDITOR_FILE_PANEL_H_

#include <graphics.h>
#include <woopsiarray.h>
#include <woopsistring.h>

#include "blocktype.h"
#include "buttonbank.h"
#include "buttonlistener.h"
#include "level.h"
#include "leveleditor.h"
#include "leveleditorpanelbase.h"
#include "spectrumcolours.h"
#include "textbutton.h"

#include "gamesession.h"
#include "menusystem.h"
#include "menu.h"
#include "menulistener.h"

/**
 * Panel with options for loading and saving the current level, reseting the
 * current level, and exiting the editor.
 */
class LevelEditorFilePanel : public LevelEditorPanelBase, public ButtonListener, public MenuListener  {
public:

	/**
	 * Constructor.
	 * @param gfx Graphics object to draw with.
	 * @param editor Pointer to the editor that owns the panel.
	 */
	LevelEditorFilePanel(WoopsiGfx::Graphics* gfx, LevelEditor* editor) : LevelEditorPanelBase(gfx) {
		_editor = editor;

		_buttons = new ButtonBank(this, gfx);

		_buttons->addButton(new TextButton(188, 100, 60, 20, 0, "Load"));
		_buttons->addButton(new TextButton(188, 124, 60, 20, 1, "Save"));
		
		_buttons->addButton(new TextButton(8, 100, 16, 20, 2, "Q"));
		_buttons->addButton(new TextButton(26, 100, 16, 20, 3, "W"));
		_buttons->addButton(new TextButton(44, 100, 16, 20, 4, "E"));
		_buttons->addButton(new TextButton(62, 100, 16, 20, 5, "R"));
		_buttons->addButton(new TextButton(80, 100, 16, 20, 6, "T"));
		_buttons->addButton(new TextButton(98, 100, 16, 20, 7, "Y"));
		_buttons->addButton(new TextButton(116, 100, 16, 20, 8, "U"));
		_buttons->addButton(new TextButton(134, 100, 16, 20, 9, "I"));
		_buttons->addButton(new TextButton(152, 100, 16, 20, 10, "O"));
		_buttons->addButton(new TextButton(170, 100, 16, 20, 11, "P"));
		
		_buttons->addButton(new TextButton(16, 124, 16, 20, 12, "A"));
		_buttons->addButton(new TextButton(34, 124, 16, 20, 13, "S"));
		_buttons->addButton(new TextButton(52, 124, 16, 20, 14, "D"));
		_buttons->addButton(new TextButton(70, 124, 16, 20, 15, "F"));
		_buttons->addButton(new TextButton(88, 124, 16, 20, 16, "G"));
		_buttons->addButton(new TextButton(106, 124, 16, 20, 17, "H"));
		_buttons->addButton(new TextButton(124, 124, 16, 20, 18, "J"));
		_buttons->addButton(new TextButton(142, 124, 16, 20, 19, "K"));
		_buttons->addButton(new TextButton(160, 124, 16, 20, 20, "L"));
		
		_buttons->addButton(new TextButton(24, 148, 16, 20, 21, "Z"));
		_buttons->addButton(new TextButton(42, 148, 16, 20, 22, "X"));
		_buttons->addButton(new TextButton(60, 148, 16, 20, 23, "C"));
		_buttons->addButton(new TextButton(78, 148, 16, 20, 24, "V"));
		_buttons->addButton(new TextButton(96, 148, 16, 20, 25, "B"));
		_buttons->addButton(new TextButton(114, 148, 16, 20, 26, "N"));
		_buttons->addButton(new TextButton(132, 148, 16, 20, 27, "M"));
		_buttons->addButton(new TextButton(150, 148, 32, 20, 28, "SPC"));
		_buttons->addButton(new TextButton(184, 148, 32, 20, 29, "DEL"));
		
		WoopsiGfx::Graphics* bottomGfx = Hardware::getBottomGfx();
		
		_menuSystem = new MenuSystem(this, bottomGfx, "Levels", 0, 10, SCREEN_WIDTH - 20, 8);
		
		Menu* rootMenu = _menuSystem->getRootMenu();

		WoopsiArray<WoopsiGfx::WoopsiString>* customLevelNames = LevelIO::getLevelNames();
		
		for (int i = 0; i < customLevelNames->size(); ++i) {
			rootMenu->addOption(customLevelNames->at(i), i);
		}
		
		delete customLevelNames;
		
		_menuSystem->render();
	};

	/**
	 * Destructor.
	 */
	~LevelEditorFilePanel() {
		delete _buttons;
	};

	/**
	 * Run a single iteration of the panel logic.
	 */
	void iterate() {
		_buttons->iterate();
	};

	/**
	 * Draw the panel.  Should be called when the panel is first displayed;
	 * after that, the iterate() method redraws when needed.
	 */
	void render() {
		_menuSystem->render();
		_buttons->render();
		drawFilename();
	};

	/**
	 * Handles any button selections.
	 * @param source The button that raised the event.
	 */
	void handleButtonAction(ButtonBase* source) {
		switch (source->getId()) {
			case 0:
				if (_filename.getLength() > 0) {
					_editor->loadLevel(_filename);
				}
				break;
			case 1:
				if (_filename.getLength() > 0) {
					_editor->saveLevel(_filename);
				}
				break;
			case 28:
				if (_filename.getLength() < 28) {
					_filename.append(" ");
					drawFilename();
				}
				break;
			case 29:
				_filename.remove(_filename.getLength() - 1);
				drawFilename();
				break;
			default:
				if (_filename.getLength() < 28) {
					_filename.append(((TextButton*)source)->getText());
					drawFilename();
				}
				break;
		}
	};
	
	void drawFilename() {
		_gfx->drawRect(10, 80, 236, 16, COLOUR_WHITE);
		_gfx->drawFilledRect(11, 81, 234, 14, COLOUR_BLACK);
		
		GameFont* font = new GameFont();
		_gfx->drawText(14, 84, font, _filename, 0, _filename.getLength(), COLOUR_WHITE);
		delete font;
	};
	
	void handleMenuAction(Menu* source) {
		//switch (source->getId()) {
	};

private:
	ButtonBank* _buttons;		/**< Collection of buttons in the panel. */
	LevelEditor* _editor;		/**< Pointer to the owning level editor. */
	WoopsiGfx::WoopsiString _filename;	/**< The filename to load/save. */
	
	MenuSystem* _menuSystem;
};

#endif
