#ifndef _LEVEL_EDITOR_FILE_PANEL_H_
#define _LEVEL_EDITOR_FILE_PANEL_H_

#include <graphics.h>
#include <woopsistring.h>

#include "buttonbank.h"
#include "buttonlistener.h"
#include "level.h"
#include "leveleditorpanelbase.h"
#include "spectrumcolours.h"
#include "textbutton.h"

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
	LevelEditorFilePanel(WoopsiGfx::Graphics* gfx, Level* level) : LevelEditorPanelBase(gfx) {
		_level = level;
		_isRunning = true;

		_buttons = new ButtonBank(this, gfx);

		_buttons->addButton(new TextButton(8, 8, 100, 20, 0, "Load"));
		_buttons->addButton(new TextButton(32, 8, 100, 20, 1, "Save"));
		_buttons->addButton(new TextButton(56, 8, 100, 20, 2, "New"));
		_buttons->addButton(new TextButton(80, 8, 100, 20, 3, "Exit"));
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
				_level->clear();
				break;
			case 3:
				_isRunning = false;
				break;
		}
	};

	bool isRunning() const {
		return _isRunning;
	};

private:
	ButtonBank* _buttons;		/**< Collection of buttons in the panel. */
	Level* _level;
	bool _isRunning;
};

#endif
