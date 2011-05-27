#ifndef _LEVEL_EDITOR_FILE_PANEL_H_
#define _LEVEL_EDITOR_FILE_PANEL_H_

#include <graphics.h>
#include <woopsistring.h>

#include "buttonbank.h"
#include "buttonlistener.h"
#include "leveleditorpanelbase.h"
#include "spectrumcolours.h"

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
	LevelEditorFilePanel(WoopsiGfx::Graphics* gfx) : LevelEditorPanelBase(gfx) {
		_buttons = new ButtonBank(this, gfx);
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
		}
	};

private:
	ButtonBank* _buttons;		/**< Collection of buttons in the panel. */
};

#endif
