#ifndef _LEVEL_EDITOR_PALETTE_PANEL_H_
#define _LEVEL_EDITOR_PALETTE_PANEL_H_

#include <graphics.h>
#include <woopsistring.h>

#include "bitmapbase.h"
#include "bitmapbutton.h"
#include "bitmapserver.h"
#include "buttonbank.h"
#include "buttonlistener.h"
#include "leveleditorpanelbase.h"
#include "spectrumcolours.h"
#include "leftarrowbmp.h"
#include "rightarrowbmp.h"

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

		_buttons->addButton(new BitmapButton(8, 8, 16, 16, 0, &_leftArrowBmp));
		_buttons->addButton(new BitmapButton(56, 8, 16, 16, 1, &_rightArrowBmp));

		_buttons->addButton(new BitmapButton(8, 32, 16, 16, 2, &_leftArrowBmp));
		_buttons->addButton(new BitmapButton(56, 32, 16, 16, 3, &_rightArrowBmp));

		_buttons->addButton(new BitmapButton(8, 56, 16, 16, 4, &_leftArrowBmp));
		_buttons->addButton(new BitmapButton(56, 56, 16, 16, 5, &_rightArrowBmp));
	
		_buttons->addButton(new BitmapButton(8, 80, 16, 16, 6, &_leftArrowBmp));
		_buttons->addButton(new BitmapButton(56, 80, 16, 16, 7, &_rightArrowBmp));

		_doorType = DOOR_TYPE_GREEN;
		_wallType = WALL_TYPE_BRICK_RED;
		_soilType = SOIL_TYPE_BLUE;
		_boulderType = BOULDER_TYPE_YELLOW;
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
		switch (source->getId()) {
			case 0:
				_boulderType--;
				if (_boulderType < 0) _boulderType = BOULDER_TYPE_COUNT - 1;
				BitmapServer::changeBoulderBmp((BoulderType)_boulderType);
				renderBitmaps();
				break;
			case 1:
				_boulderType++;
				if (_boulderType > BOULDER_TYPE_COUNT - 1) _boulderType = 0;
				BitmapServer::changeBoulderBmp((BoulderType)_boulderType);
				renderBitmaps();
				break;

			case 2:
				_soilType--;
				if (_soilType < 0) _soilType = SOIL_TYPE_COUNT - 1;
				BitmapServer::changeSoilBmp((SoilType)_soilType);
				renderBitmaps();
				break;
			case 3:
				_soilType++;
				if (_soilType > SOIL_TYPE_COUNT - 1) _soilType = 0;
				BitmapServer::changeSoilBmp((SoilType)_soilType);
				renderBitmaps();
				break;

			case 4:
				_wallType--;
				if (_wallType < 0) _wallType = WALL_TYPE_COUNT - 1;
				BitmapServer::changeWallBmp((WallType)_wallType);
				renderBitmaps();
				break;
			case 5:
				_wallType++;
				if (_wallType > WALL_TYPE_COUNT - 1) _wallType = 0;
				BitmapServer::changeWallBmp((WallType)_wallType);
				renderBitmaps();
				break;

			case 6:
				_doorType--;
				if (_doorType < 0) _doorType = DOOR_TYPE_COUNT - 1;
				BitmapServer::changeDoorBmp((DoorType)_doorType);
				renderBitmaps();
				break;
			case 7:
				_doorType++;
				if (_doorType > DOOR_TYPE_COUNT - 1) _doorType = 0;
				BitmapServer::changeDoorBmp((DoorType)_doorType);
				renderBitmaps();
				break;	
		}
	};

private:
	ButtonBank* _buttons;			/**< Collection of buttons in the panel. */
	LeftArrowBmp _leftArrowBmp;
	RightArrowBmp _rightArrowBmp;

	s32 _boulderType;
	s32 _wallType;
	s32 _soilType;
	s32 _doorType;

	/**
	 * Renders the bitmaps for each block that can be recoloured.
	 */
	void renderBitmaps() {
		WoopsiGfx::BitmapBase* bmp = BitmapServer::getBoulderBmp();
		_gfx->drawBitmap(32, 8, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);

		bmp = BitmapServer::getSoilBmp();
		_gfx->drawBitmap(32, 32, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);

		bmp = BitmapServer::getWallBmp();
		_gfx->drawBitmap(32, 56, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);

		bmp = BitmapServer::getDoorBmp();
		_gfx->drawBitmap(32, 80, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);
	};
};

#endif
