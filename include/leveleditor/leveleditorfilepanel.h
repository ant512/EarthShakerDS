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

/**
 * Panel with options for loading and saving the current level, reseting the
 * current level, and exiting the editor.
 */
class LevelEditorFilePanel : public LevelEditorPanelBase, public ButtonListener {
public:

	/**
	 * Constructor.
	 * @param gfx Graphics object to draw with.
	 */
	LevelEditorFilePanel(WoopsiGfx::Graphics* gfx, LevelEditor* editor) : LevelEditorPanelBase(gfx) {
		_isRunning = true;
		_editor = editor;

		_buttons = new ButtonBank(this, gfx);

		_buttons->addButton(new TextButton(8, 8, 100, 20, 0, "Load"));
		_buttons->addButton(new TextButton(8, 32, 100, 20, 1, "Save"));
		_buttons->addButton(new TextButton(8, 56, 100, 20, 2, "Test"));
		_buttons->addButton(new TextButton(8, 80, 100, 20, 3, "New"));
		_buttons->addButton(new TextButton(8, 104, 100, 20, 4, "Exit"));
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
		_buttons->render();
	};

	/**
	 * Handles any button selections.
	 * @param source The button that raised the event.
	 */
	void handleButtonAction(ButtonBase* source) {
		switch (source->getId()) {
			case 0:
				break;
			case 1:
				break;
			case 2:
				_editor->testLevel();
				break;
			case 3:
				_editor->resetLevel();
				break;
			case 4:
				_isRunning = false;
				break;
		}
	};

	bool isRunning() const {
		return _isRunning;
	};

private:
	ButtonBank* _buttons;		/**< Collection of buttons in the panel. */
	LevelEditor* _editor;
	bool _isRunning;
};

#endif
