#ifndef _LEVEL_EDITOR_BLOCK_PANEL_H_
#define _LEVEL_EDITOR_BLOCK_PANEL_H_

#include <graphics.h>
#include <woopsiarray.h>

#include "barrierbmp1.h"
#include "barriercontrolbmp.h"
#include "beanbmp1.h"
#include "bubblebmp1.h"
#include "constants.h"
#include "diamondbmp1.h"
#include "doorbmp.h"
#include "extralifebmp1.h"
#include "firebmp1.h"
#include "gravityinversionbmp1.h"
#include "playerbmp1.h"
#include "soilbmp.h"
#include "teleportbmp1.h"
#include "brainwallbmp.h"
#include "wetsoilbmp1.h"

#include "bitmapbutton.h"
#include "bitmapserver.h"
#include "blocktype.h"
#include "buttonbank.h"
#include "buttonlistener.h"
#include "leveleditorpanelbase.h"
#include "leveleditor.h"

#include "playerbmp1.h"

class LevelEditorBlockPanel : public LevelEditorPanelBase, public ButtonListener {
public:
	LevelEditorBlockPanel(WoopsiGfx::Graphics* gfx, LevelEditor* levelEditor) : LevelEditorPanelBase(gfx) {
		_levelEditor = levelEditor;
		_selectedBlock = BLOCK_TYPE_PLAYER;

		_buttons = new ButtonBank(this, gfx);

		_buttons->addButton(new BitmapButton(8, 8, 20, 20, BLOCK_TYPE_PLAYER, &_playerBmp));
		_buttons->addButton(new BitmapButton(32, 8, 20, 20, BLOCK_TYPE_BARRIER, &_barrierBmp));
		_buttons->addButton(new BitmapButton(56, 8, 20, 20, BLOCK_TYPE_BARRIER_CONTROL, &_barrierControlBmp));
		_buttons->addButton(new BitmapButton(80, 8, 20, 20, BLOCK_TYPE_BEAN, &_beanBmp));
		_buttons->addButton(new BitmapButton(104, 8, 20, 20, BLOCK_TYPE_BOULDER, BitmapServer::getBoulderBmp()));
		_buttons->addButton(new BitmapButton(128, 8, 20, 20, BLOCK_TYPE_FIRE, &_fireBmp));
		_buttons->addButton(new BitmapButton(152, 8, 20, 20, BLOCK_TYPE_BUBBLE, &_bubbleBmp));
		_buttons->addButton(new BitmapButton(176, 8, 20, 20, BLOCK_TYPE_DIAMOND, &_diamondBmp));
		_buttons->addButton(new BitmapButton(200, 8, 20, 20, BLOCK_TYPE_DOOR_BLUE, BitmapServer::getBlueDoorBmp()));
		_buttons->addButton(new BitmapButton(224, 8, 20, 20, BLOCK_TYPE_DOOR_CYAN, BitmapServer::getCyanDoorBmp()));

		_buttons->addButton(new BitmapButton(8, 32, 20, 20, BLOCK_TYPE_DOOR_GREEN, BitmapServer::getGreenDoorBmp()));
		_buttons->addButton(new BitmapButton(32, 32, 20, 20, BLOCK_TYPE_DOOR_MAGENTA, BitmapServer::getMagentaDoorBmp()));
		_buttons->addButton(new BitmapButton(56, 32, 20, 20, BLOCK_TYPE_DOOR_RED, BitmapServer::getRedDoorBmp()));
		_buttons->addButton(new BitmapButton(80, 32, 20, 20, BLOCK_TYPE_DOOR_YELLOW, BitmapServer::getYellowDoorBmp()));
		_buttons->addButton(new BitmapButton(104, 32, 20, 20, BLOCK_TYPE_DOOR_WHITE, BitmapServer::getWhiteDoorBmp()));
		_buttons->addButton(new BitmapButton(128, 32, 20, 20, BLOCK_TYPE_EXTRA_LIFE, &_extraLifeBmp));
		_buttons->addButton(new BitmapButton(152, 32, 20, 20, BLOCK_TYPE_WALL_BRICK, BitmapServer::getBrickWallBmp()));
		_buttons->addButton(new BitmapButton(176, 32, 20, 20, BLOCK_TYPE_WALL_ICE, BitmapServer::getIceWallBmp()));
		_buttons->addButton(new BitmapButton(200, 32, 20, 20, BLOCK_TYPE_WALL_METAL, BitmapServer::getMetalWallBmp()));
		_buttons->addButton(new BitmapButton(224, 32, 20, 20, BLOCK_TYPE_WALL_BRAIN, BitmapServer::getBrainWallBmp()));

		_buttons->addButton(new BitmapButton(8, 56, 20, 20, BLOCK_TYPE_WALL_GIRDER, BitmapServer::getGirderWallBmp()));
		_buttons->addButton(new BitmapButton(32, 56, 20, 20, BLOCK_TYPE_WALL_HEART, BitmapServer::getHeartWallBmp()));
		_buttons->addButton(new BitmapButton(56, 56, 20, 20, BLOCK_TYPE_WALL_HONEYCOMB, BitmapServer::getHoneycombWallBmp()));
		_buttons->addButton(new BitmapButton(80, 56, 20, 20, BLOCK_TYPE_WALL_LEAFY, BitmapServer::getLeafyWallBmp()));
		_buttons->addButton(new BitmapButton(104, 56, 20, 20, BLOCK_TYPE_WALL_NUCLEAR, BitmapServer::getNuclearWallBmp()));
		_buttons->addButton(new BitmapButton(128, 56, 20, 20, BLOCK_TYPE_WALL_PIPE, BitmapServer::getPipeWallBmp()));
		_buttons->addButton(new BitmapButton(152, 56, 20, 20, BLOCK_TYPE_WALL_QUESTION, BitmapServer::getQuestionWallBmp()));
		_buttons->addButton(new BitmapButton(176, 56, 20, 20, BLOCK_TYPE_WALL_SAND, BitmapServer::getSandWallBmp()));
		_buttons->addButton(new BitmapButton(200, 56, 20, 20, BLOCK_TYPE_WALL_SQUARE, BitmapServer::getSquareWallBmp()));
		_buttons->addButton(new BitmapButton(224, 56, 20, 20, BLOCK_TYPE_SOIL, BitmapServer::getSoilBmp()));

		_buttons->addButton(new BitmapButton(8, 80, 20, 20, BLOCK_TYPE_SOIL_HONEYCOMB, BitmapServer::getHoneycombSoilBmp()));
		_buttons->addButton(new BitmapButton(32, 80, 20, 20, BLOCK_TYPE_SOIL_QUESTION, BitmapServer::getQuestionWallBmp()));
		_buttons->addButton(new BitmapButton(56, 80, 20, 20, BLOCK_TYPE_SOIL_WET, &_wetSoilBmp));
		_buttons->addButton(new BitmapButton(80, 80, 20, 20, BLOCK_TYPE_SOIL_BOULDER, BitmapServer::getBoulderBmp()));
		_buttons->addButton(new BitmapButton(104, 80, 20, 20, BLOCK_TYPE_TELEPORT, &_teleportBmp));
	};

	~LevelEditorBlockPanel() {
		delete _buttons;
	};

	void iterate() {
		_buttons->iterate();
	};

	void render() {
		_buttons->render();
	};

	/**
	 * Handles any button selections.
	 * @param source The button that raised the event.
	 */
	void handleButtonAction(ButtonBase* source) {
		_selectedBlock = (BlockType)source->getId();
	};

	BlockType getSelectedBlockType() const {
		return _selectedBlock;
	};

private:
	LevelEditor* _levelEditor;
	ButtonBank* _buttons;

	BlockType _selectedBlock;

	BarrierBmp1 _barrierBmp;
	BarrierControlBmp _barrierControlBmp;
	BeanBmp1 _beanBmp;
	BubbleBmp1 _bubbleBmp;
	PlayerBmp1 _playerBmp;
	FireBmp1 _fireBmp;
	DiamondBmp1 _diamondBmp;
	TeleportBmp1 _teleportBmp;
	ExtraLifeBmp1 _extraLifeBmp;
	WetSoilBmp1 _wetSoilBmp;
};

#endif
