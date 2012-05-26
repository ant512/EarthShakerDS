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
 * Panel that allows block colours and other options to be chosen.
 */
class LevelEditorOptionsPanel : public LevelEditorPanelBase, public ButtonListener {
public:

	/**
	 * Constructor.
	 * @param gfx Graphics object to draw with.
	 * @param editor Pointer to the editor that owns the panel.
	 */
	LevelEditorOptionsPanel(WoopsiGfx::Graphics* gfx, LevelEditor* editor) : LevelEditorPanelBase(gfx) {
		_isRunning = true;
		_editor = editor;
		
		_buttons = new ButtonBank(this, gfx);

		_buttons->addButton(new BitmapButton(8, 24, 16, 16, 0, &_leftArrowBmp));
		_buttons->addButton(new BitmapButton(56, 24, 16, 16, 1, &_rightArrowBmp));

		_buttons->addButton(new BitmapButton(8, 48, 16, 16, 2, &_leftArrowBmp));
		_buttons->addButton(new BitmapButton(56, 48, 16, 16, 3, &_rightArrowBmp));

		_buttons->addButton(new BitmapButton(8, 72, 16, 16, 4, &_leftArrowBmp));
		_buttons->addButton(new BitmapButton(56, 72, 16, 16, 5, &_rightArrowBmp));
	
		_buttons->addButton(new BitmapButton(8, 96, 16, 16, 6, &_leftArrowBmp));
		_buttons->addButton(new BitmapButton(56, 96, 16, 16, 7, &_rightArrowBmp));
		
		_buttons->addButton(new TextButton(92, 24, 84, 20, 8, "Test"));
		_buttons->addButton(new TextButton(92, 48, 84, 20, 9, "New"));
		_buttons->addButton(new TextButton(92, 72, 84, 20, 10, "Exit"));

		_doorType = DOOR_TYPE_GREEN;
		_wallType = WALL_TYPE_BRICK_RED;
		_soilType = SOIL_TYPE_BLUE;
		_boulderType = BOULDER_TYPE_YELLOW;
	};

	/**
	 * Destructor.
	 */
	~LevelEditorOptionsPanel() {
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

		s32 tmp;

		switch (source->getId()) {
			case 0:
				tmp = _boulderType;
				--tmp;
				_boulderType = (BoulderType)tmp;
				if (_boulderType < 0) _boulderType = (BoulderType)(BOULDER_TYPE_COUNT - 1);
				BitmapServer::changeBoulderBmp(_boulderType);
				renderBitmaps();
				break;
			case 1:
				tmp = _boulderType;
				++tmp;
				_boulderType = (BoulderType)tmp;
				if (_boulderType > BOULDER_TYPE_COUNT - 1) _boulderType = BOULDER_TYPE_WHITE;
				BitmapServer::changeBoulderBmp(_boulderType);
				renderBitmaps();
				break;

			case 2:
				tmp = _soilType;
				--tmp;
				_soilType = (SoilType)tmp;
				if (_soilType < 0) _soilType = (SoilType)(SOIL_TYPE_COUNT - 1);
				BitmapServer::changeSoilBmp(_soilType);
				renderBitmaps();
				break;
			case 3:
				tmp = _soilType;
				++tmp;
				_soilType = (SoilType)tmp;
				if (_soilType > SOIL_TYPE_COUNT - 1) _soilType = SOIL_TYPE_WHITE;
				BitmapServer::changeSoilBmp(_soilType);
				renderBitmaps();
				break;

			case 4:
				tmp = _wallType;
				--tmp;
				_wallType = (WallType)tmp;
				if (_wallType < 0) _wallType = (WallType)(WALL_TYPE_COUNT - 1);
				BitmapServer::changeWallBmp(_wallType);
				renderBitmaps();
				break;
			case 5:
				tmp = _wallType;
				++tmp;
				_wallType = (WallType)tmp;
				if (_wallType > WALL_TYPE_COUNT - 1) _wallType = WALL_TYPE_BRICK_WHITE;
				BitmapServer::changeWallBmp(_wallType);
				renderBitmaps();
				break;

			case 6:
				tmp = _doorType;
				--tmp;
				_doorType = (DoorType)tmp;
				if (_doorType < 0) _doorType = (DoorType)(DOOR_TYPE_COUNT - 1);
				BitmapServer::changeDoorBmp(_doorType);
				renderBitmaps();
				break;
			case 7:
				tmp = _doorType;
				++tmp;
				_doorType = (DoorType)tmp;
				if (_doorType > DOOR_TYPE_COUNT - 1) _doorType = DOOR_TYPE_WHITE;
				BitmapServer::changeDoorBmp(_doorType);
				renderBitmaps();
				break;	
				
			case 8:
				// Have to reset this manually as we'll miss the event
				source->release();
				
				_editor->testLevel();
				break;
			case 9:
				_editor->resetLevel();
				break;
			case 10:
				_isRunning = false;
				break;
		}
	};
	
	/**
	 * Check if the panel is still running.
	 * @return True if the panel is still running.
	 */
	bool isRunning() const {
		return _isRunning;
	};

	SoilType getSoilType() {
		return _soilType;
	};
	
	BoulderType getBoulderType() {
		return _boulderType;
	};
	
	WallType getWallType() {
		return _wallType;
	};
	
	DoorType getDoorType() {
		return _doorType;
	};
	
	void setSoilType(SoilType type) {
		_soilType = type;
	};
	
	void setBoulderType(BoulderType type) {
		_boulderType = type;
	};
	
	void setWallType(WallType type) {
		_wallType = type;
	};
	
	void setDoorType(DoorType type) {
		_doorType = type;
	};
	
private:
	ButtonBank* _buttons;			/**< Collection of buttons in the panel. */
	LeftArrowBmp _leftArrowBmp;
	RightArrowBmp _rightArrowBmp;
	
	LevelEditor* _editor;			/**< Pointer to the owning level editor. */
	bool _isRunning;				/**< True if the panel is still running. */

	BoulderType _boulderType;
	WallType _wallType;
	SoilType _soilType;
	DoorType _doorType;

	/**
	 * Renders the bitmaps for each block that can be recoloured.
	 */
	void renderBitmaps() {
		GameFont *font = new GameFont();
		
		WoopsiGfx::WoopsiString *paletteTitle = new WoopsiGfx::WoopsiString("Palette");
		WoopsiGfx::WoopsiString *levelTitle = new WoopsiGfx::WoopsiString("Level");
		
		_gfx->drawText(13, 10, font, *paletteTitle, 0, paletteTitle->getLength(), COLOUR_MAGENTA);
		_gfx->drawText(115, 10, font, *levelTitle, 0, levelTitle->getLength(), COLOUR_MAGENTA);
		
		WoopsiGfx::BitmapBase* bmp = BitmapServer::getBoulderBmp();
		_gfx->drawBitmap(32, 24, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);

		bmp = BitmapServer::getSoilBmp();
		_gfx->drawBitmap(32, 48, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);

		bmp = BitmapServer::getWallBmp();
		_gfx->drawBitmap(32, 72, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);

		bmp = BitmapServer::getDoorBmp();
		_gfx->drawBitmap(32, 96, bmp->getWidth(), bmp->getHeight(), bmp, 0, 0);
		
		delete font;
		delete paletteTitle;
		delete levelTitle;
	};
};

#endif
