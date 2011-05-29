#ifndef _LEVEL_EDITOR_PALETTE_PANEL_H_
#define _LEVEL_EDITOR_PALETTE_PANEL_H_

#include <graphics.h>
#include <woopsistring.h>

#include "bitmapbase.h"
#include "bitmapserver.h"
#include "buttonbank.h"
#include "buttonlistener.h"
#include "colourbutton.h"
#include "leveleditorpanelbase.h"
#include "spectrumcolours.h"

/**
 * Panel that allows block colours to be chosen.
 */
class LevelEditorPalettePanel : public LevelEditorPanelBase, public ButtonListener {
public:

	/**
	 * Constructor.
	 * @param gfx Graphics object to draw with.
	 */
	LevelEditorPalettePanel(WoopsiGfx::Graphics* gfx) : LevelEditorPanelBase(gfx) {
		_buttons = new ButtonBank(this, gfx);

		_buttons->addButton(new ColourButton(32, 8, 20, 20, 0, COLOUR_WHITE, COLOUR_WHITE_DARK));
		_buttons->addButton(new ColourButton(56, 8, 20, 20, 1, COLOUR_RED, COLOUR_RED_DARK));
		_buttons->addButton(new ColourButton(80, 8, 20, 20, 2, COLOUR_GREEN, COLOUR_GREEN_DARK));
		_buttons->addButton(new ColourButton(104, 8, 20, 20, 3, COLOUR_BLUE, COLOUR_BLUE_DARK));
		_buttons->addButton(new ColourButton(128, 8, 20, 20, 4, COLOUR_CYAN, COLOUR_CYAN_DARK));
		_buttons->addButton(new ColourButton(152, 8, 20, 20, 5, COLOUR_MAGENTA, COLOUR_MAGENTA_DARK));
		_buttons->addButton(new ColourButton(176, 8, 20, 20, 6, COLOUR_YELLOW, COLOUR_YELLOW_DARK));

		_buttons->addButton(new ColourButton(32, 32, 20, 20, 7, COLOUR_WHITE, COLOUR_WHITE_DARK));
		_buttons->addButton(new ColourButton(56, 32, 20, 20, 8, COLOUR_RED, COLOUR_RED_DARK));
		_buttons->addButton(new ColourButton(80, 32, 20, 20, 9, COLOUR_GREEN, COLOUR_GREEN_DARK));
		_buttons->addButton(new ColourButton(104, 32, 20, 20, 10, COLOUR_BLUE, COLOUR_BLUE_DARK));
		_buttons->addButton(new ColourButton(128, 32, 20, 20, 11, COLOUR_CYAN, COLOUR_CYAN_DARK));
		_buttons->addButton(new ColourButton(152, 32, 20, 20, 12, COLOUR_MAGENTA, COLOUR_MAGENTA_DARK));
		_buttons->addButton(new ColourButton(176, 32, 20, 20, 13, COLOUR_YELLOW, COLOUR_YELLOW_DARK));

		_buttons->addButton(new ColourButton(32, 56, 20, 20, 14, COLOUR_WHITE, COLOUR_WHITE_DARK));
		_buttons->addButton(new ColourButton(56, 56, 20, 20, 15, COLOUR_RED, COLOUR_RED_DARK));
		_buttons->addButton(new ColourButton(80, 56, 20, 20, 16, COLOUR_GREEN, COLOUR_GREEN_DARK));
		_buttons->addButton(new ColourButton(104, 56, 20, 20, 17, COLOUR_BLUE, COLOUR_BLUE_DARK));
		_buttons->addButton(new ColourButton(128, 56, 20, 20, 18, COLOUR_CYAN, COLOUR_CYAN_DARK));
		_buttons->addButton(new ColourButton(152, 56, 20, 20, 19, COLOUR_MAGENTA, COLOUR_MAGENTA_DARK));
		_buttons->addButton(new ColourButton(176, 56, 20, 20, 20, COLOUR_YELLOW, COLOUR_YELLOW_DARK));
	};

	/**
	 * Destructor.
	 */
	~LevelEditorPalettePanel() {
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
		renderBitmaps();

		_buttons->render();
	};

	/**
	 * Handles any button selections.
	 * @param source The button that raised the event.
	 */
	void handleButtonAction(ButtonBase* source) {
		/*
		switch (source->getId()) {
			case 0:
				BitmapServer::makeBouldersWhite();
				break;
			case 1:
				BitmapServer::makeBouldersRed();
				break;
			case 2:
				BitmapServer::makeBouldersGreen();
				break;
			case 3:
				BitmapServer::makeBouldersBlue();
				break;
			case 4:
				BitmapServer::makeBouldersCyan();
				break;
			case 5:
				BitmapServer::makeBouldersMagenta();
				break;
			case 6:
				BitmapServer::makeBouldersYellow();
				break;

			case 7:
				BitmapServer::makeSoilWhite();
				break;
			case 8:
				BitmapServer::makeSoilRed();
				break;
			case 9:
				BitmapServer::makeSoilGreen();
				break;
			case 10:
				BitmapServer::makeSoilBlue();
				break;
			case 11:
				BitmapServer::makeSoilCyan();
				break;
			case 12:
				BitmapServer::makeSoilMagenta();
				break;
			case 13:
				BitmapServer::makeSoilYellow();
				break;

			case 14:
				BitmapServer::makeBrickWallWhite();
				break;
			case 15:
				BitmapServer::makeBrickWallRed();
				break;
			case 16:
				BitmapServer::makeBrickWallGreen();
				break;
			case 17:
				BitmapServer::makeBrickWallBlue();
				break;
			case 18:
				BitmapServer::makeBrickWallCyan();
				break;
			case 19:
				BitmapServer::makeBrickWallMagenta();
				break;
			case 20:
				BitmapServer::makeBrickWallYellow();
				break;
		}

		renderBitmaps();
		*/
	};

private:
	ButtonBank* _buttons;		/**< Collection of buttons in the panel. */

	/**
	 * Renders the bitmaps for each block that can be recoloured.
	 */
	void renderBitmaps() {
		WoopsiGfx::BitmapBase* bmp = BitmapServer::getBoulderBmp();
		_gfx->drawBitmap(8, 8, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);

		bmp = BitmapServer::getSoilBmp();
		_gfx->drawBitmap(8, 32, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);

		bmp = BitmapServer::getWallBmp();
		_gfx->drawBitmap(8, 56, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);
	};
};

#endif
