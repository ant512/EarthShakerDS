#ifndef _LEVEL_EDITOR_BLOCK_SELECTOR_H_
#define _LEVEL_EDITOR_BLOCK_SELECTOR_H_

#include <graphics.h>
#include <woopsiarray.h>

#include "bitmapbase.h"
#include "barrierbmp3.h"
#include "barriercontrolbmp.h"
#include "beanbmp2.h"
#include "bubblebmp1.h"
#include "constants.h"
#include "diamondbmp1.h"
#include "doorbmp.h"
#include "extralifebmp1.h"
#include "firebmp1.h"
#include "gravityinversionbmp2.h"
#include "playerbmp1.h"
#include "soilbmp.h"
#include "teleportbmp3.h"
#include "brainwallbmp.h"
#include "wetsoilbmp1.h"

#include "bitmapbutton.h"
#include "bitmapserver.h"
#include "blocktype.h"
#include "leveleditor.h"

#include "playerbmp1.h"

#include "hardware.h"

class LevelEditorBlockSelector {
public:
	static const s32 BLOCK_TYPE_COUNT = 14;

	LevelEditorBlockSelector(WoopsiGfx::Graphics* gfx) {
		_selectedIndex = 0;

		_gfx = gfx;

		_bitmaps = new WoopsiGfx::BitmapBase*[BLOCK_TYPE_COUNT];

		_bitmaps[0] = &_playerBmp;
		_bitmaps[1] = &_diamondBmp;
		_bitmaps[2] = &_bubbleBmp;
		_bitmaps[3] = &_fireBmp;
		_bitmaps[4] = &_beanBmp;
		_bitmaps[5] = &_gravityBmp;
		_bitmaps[6] = &_extraLifeBmp;
		_bitmaps[7] = &_barrierBmp;
		_bitmaps[8] = &_barrierControlBmp;
		_bitmaps[9] = &_teleportBmp;
		_bitmaps[10] = BitmapServer::getDoorBmp();
		_bitmaps[11] = BitmapServer::getBoulderBmp();
		_bitmaps[12] = BitmapServer::getWallBmp();
		_bitmaps[13] = BitmapServer::getSoilBmp();
		_bitmaps[14] = &_wetSoilBmp;
		
	};

	~LevelEditorBlockSelector() {
		delete[] _bitmaps;
	};

	void iterate() {
		const PadState& pad = Hardware::getPadState();


		if (pad.l && _selectedIndex > 0) {
			drawCursor();
			--_selectedIndex;
			SoundPlayer::playBlockFall();
			drawCursor();
		}

		if (pad.r && _selectedIndex < BLOCK_TYPE_COUNT - 1) {
			drawCursor();
			++_selectedIndex;
			SoundPlayer::playBlockFall();
			drawCursor();
		}
	};

	void drawCursor() {
		s32 y = SCREEN_HEIGHT - BlockBase::BLOCK_SIZE;
		s32 x = (SCREEN_WIDTH - (BlockBase::BLOCK_SIZE * BLOCK_TYPE_COUNT)) / 2;
		_gfx->drawFilledXORRect(x + (_selectedIndex * BlockBase::BLOCK_SIZE), y, _bitmaps[_selectedIndex]->getWidth(), _bitmaps[_selectedIndex]->getHeight());
	};

	void render() {
		s32 y = SCREEN_HEIGHT - BlockBase::BLOCK_SIZE;
		s32 x = (SCREEN_WIDTH - (BlockBase::BLOCK_SIZE * BLOCK_TYPE_COUNT)) / 2;

		_gfx->drawFilledRect(0, y, SCREEN_WIDTH, BlockBase::BLOCK_SIZE, COLOUR_BLACK);

		for (s32 i = 0; i < BLOCK_TYPE_COUNT; ++i) {
			_gfx->drawBitmap(x, y, _bitmaps[i]->getWidth(), _bitmaps[i]->getHeight(), _bitmaps[i], 0, 0);
			x += BlockBase::BLOCK_SIZE;
		}

		drawCursor();
	};

	BlockType getSelectedBlockType() const {
		return (BlockType)(_selectedIndex + 1);
	};

private:
	s32 _selectedIndex;
	WoopsiGfx::Graphics* _gfx;

	BarrierBmp3 _barrierBmp;
	BarrierControlBmp _barrierControlBmp;
	BeanBmp2 _beanBmp;
	BubbleBmp1 _bubbleBmp;
	PlayerBmp1 _playerBmp;
	FireBmp1 _fireBmp;
	DiamondBmp1 _diamondBmp;
	TeleportBmp3 _teleportBmp;
	ExtraLifeBmp1 _extraLifeBmp;
	WetSoilBmp1 _wetSoilBmp;
	GravityInversionBmp2 _gravityBmp;

	WoopsiGfx::BitmapBase** _bitmaps;
};

#endif
