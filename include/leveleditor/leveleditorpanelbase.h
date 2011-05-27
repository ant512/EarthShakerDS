#ifndef _LEVEL_EDITOR_PANEL_BASE_H_
#define _LEVEL_EDITOR_PANEL_BASE_H_

#include <graphics.h>

#include "spectrumcolours.h"

/**
 * Base class for all panels that appear in the lower display of the level
 * editor.
 */
class LevelEditorPanelBase {
public:

	/**
	 * Constructor.
	 * @param gfx Graphics object to draw with.
	 */
	LevelEditorPanelBase(WoopsiGfx::Graphics* gfx) {
		_gfx = gfx;
	};

	/**
	 * Destructor.
	 */
	virtual ~LevelEditorPanelBase() {};

	/**
	 * Run a single iteration of the panel logic.
	 */
	virtual void iterate() = 0;

	/**
	 * Draw the panel.  Should be called when the panel is first displayed;
	 * after that, the iterate() method redraws when needed.
	 */
	virtual void render() = 0;

	/**
	 * Erases the panel from the screen.
	 */
	void erase() {
		_gfx->drawFilledRect(PANEL_X, PANEL_Y, PANEL_WIDTH, PANEL_HEIGHT, COLOUR_BLACK);
	};

protected:
	static const s32 PANEL_X = 8;			/**< X co-ordinate of the panel. */
	static const s32 PANEL_Y = 8;			/**< Y co-ordinate of the panel. */
	static const s32 PANEL_WIDTH = 240;		/**< Width of the panel. */
	static const s32 PANEL_HEIGHT = 160;	/**< Height of the panel. */

	WoopsiGfx::Graphics* _gfx;				/**< Graphics object to draw with. */
};

#endif
