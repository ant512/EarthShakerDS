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

/**
 * Displays a horizontal list of blocks.  A XORed rect is drawn over the current
 * block selection.  The cursor can be moved using the L and R buttons.
 */
class LevelEditorBlockSelector {
public:

	/**
	 * Constructor.
	 * @param gfx Graphics object to draw with.
	 */
	LevelEditorBlockSelector(WoopsiGfx::Graphics* gfx) {
		_selectedIndex = 0;

		_gfx = gfx;

		_bitmaps = new WoopsiGfx::BitmapBase*[BLOCK_TYPE_COUNT - 1];

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

	/**
	 * Destructor.
	 */
	~LevelEditorBlockSelector() {
		delete[] _bitmaps;
	};

	/**
	 * Runs the selector's logic.  Watches the L and R buttons and responds
	 * appropriately.
	 */
	void iterate() {
		const Pad& pad = Hardware::getPad();

		if (pad.isLHeld()) {
			drawCursor();
			--_selectedIndex;

			if (_selectedIndex < 0) _selectedIndex = BLOCK_TYPE_COUNT - 2;

			SoundPlayer::playBlockFall();
			drawCursor();
		}

		if (pad.isRHeld()) {
			drawCursor();
			++_selectedIndex;

			if (_selectedIndex > BLOCK_TYPE_COUNT - 2) _selectedIndex = 0;

			SoundPlayer::playBlockFall();
			drawCursor();
		}
	};

	/**
	 * Draws the cursor at the current co-ordinates.  As the cursor is a XOR
	 * rect, it can be drawn over itself to erase itself.
	 */
	void drawCursor() {
		s32 y = SCREEN_HEIGHT - BlockBase::BLOCK_SIZE;
		s32 x = (SCREEN_WIDTH - (BlockBase::BLOCK_SIZE * (BLOCK_TYPE_COUNT - 1))) / 2;
		_gfx->drawFilledXORRect(x + (_selectedIndex * BlockBase::BLOCK_SIZE), y, _bitmaps[_selectedIndex]->getWidth(), _bitmaps[_selectedIndex]->getHeight());
	};

	/**
	 * Draw the entire selector.
	 */
	void render() {
		s32 y = SCREEN_HEIGHT - BlockBase::BLOCK_SIZE;
		s32 x = (SCREEN_WIDTH - (BlockBase::BLOCK_SIZE * (BLOCK_TYPE_COUNT - 1))) / 2;

		_gfx->drawFilledRect(0, y, SCREEN_WIDTH, BlockBase::BLOCK_SIZE, COLOUR_BLACK);

		for (s32 i = 0; i < BLOCK_TYPE_COUNT - 1; ++i) {
			_gfx->drawBitmap(x, y, _bitmaps[i]->getWidth(), _bitmaps[i]->getHeight(), _bitmaps[i], 0, 0);
			x += BlockBase::BLOCK_SIZE;
		}

		drawCursor();
	};

	/**
	 * Get the selected block type.
	 * @return The selected block type.
	 */
	BlockType getSelectedBlockType() const {
		return (BlockType)(_selectedIndex + 1);
	};

private:
	s32 _selectedIndex;						/**< Index within the block list of the selected block. */
	WoopsiGfx::Graphics* _gfx;				/**< Graphics object to draw with. */

	BarrierBmp3 _barrierBmp;				/**< Barrier block bitmap. */
	BarrierControlBmp _barrierControlBmp;	/**< Barrier control block bitmap. */
	BeanBmp2 _beanBmp;						/**< Bean block bitmap. */
	BubbleBmp1 _bubbleBmp;					/**< Bubble block bitmap. */
	PlayerBmp1 _playerBmp;					/**< Player block bitmap. */
	FireBmp1 _fireBmp;						/**< Fire block bitmap. */
	DiamondBmp1 _diamondBmp;				/**< Diamond block bitmap. */
	TeleportBmp3 _teleportBmp;				/**< Teleport block bitmap. */
	ExtraLifeBmp1 _extraLifeBmp;			/**< Extra life block bitmap. */
	WetSoilBmp1 _wetSoilBmp;				/**< Wet soil block bitmap. */
	GravityInversionBmp2 _gravityBmp;		/**< Gravity block bitmap. */

	WoopsiGfx::BitmapBase** _bitmaps;		/**< List of block bitmaps. */
};

#endif
