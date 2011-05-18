#ifndef _BLOCK_SLIDESHOW_SCREEN_H_
#define _BLOCK_SLIDESHOW_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "blockbase.h"
#include "gamefont.h"
#include "hardware.h"
#include "screenbase.h"
#include "spectrumcolours.h"

const s32 BLOCK_DISPLAY_TIME = 200;		/**< Length of time each block is on screen. */
const s32 BLOCK_DISPLAY_X = 120;		/**< X co-ord that blocks are displayed at. */
const s32 BLOCK_DISPLAY_Y = 88;			/**< Y co-ord that blocks are displayed at. */

/**
 * Slideshow of different block types.
 */
class BlockSlideshowScreen : public ScreenBase {
public:

	/**
	 * Constructor.
	 * @param gfx Graphics object to draw to.
	 */
	BlockSlideshowScreen(WoopsiGfx::Graphics* gfx);

	/**
	 * Destructor.
	 */
	~BlockSlideshowScreen();

	/**
	 * Runs the screen.
	 */
	void iterate();

	/**
	 * Indicates whether or not the screen is running.  If not, calling its
	 * iterate() method should be futile.  The program should move on to the
	 * next section and give up on this screen.
	 * @return True if the screen is running; false if not.
	 */
	bool isRunning() const;

private:

	/**
	 * List of all states the screen can be in.  There are two states for each
	 * block - standard (block is visible) and erasing (block is wiped in
	 * preparation for the next).
	 */
	enum ScreenState {
		SCREEN_STATE_TELEPORT = 0,						/**< Teleport visible. */
		SCREEN_STATE_TELEPORT_ERASE = 1,				/**< Teleport being erased. */
		SCREEN_STATE_BEAN = 2,							/**< Bean visible. */
		SCREEN_STATE_BEAN_ERASE = 3,					/**< Bean being erased. */
		SCREEN_STATE_EXTRA_LIFE = 4,					/**< Extra life visible. */
		SCREEN_STATE_EXTRA_LIFE_ERASE = 5,				/**< Extra life being erased. */
		SCREEN_STATE_DIAMOND = 6,						/**< Diamond visible. */
		SCREEN_STATE_DIAMOND_ERASE = 7,					/**< Diamond being erased. */
		SCREEN_STATE_BUBBLE = 8,						/**< Bubble visible. */
		SCREEN_STATE_BUBBLE_ERASE = 9,					/**< Bubble being erased. */
		SCREEN_STATE_FIRE = 10,							/**< Fire visible. */
		SCREEN_STATE_FIRE_ERASE = 11,					/**< Fire being erased. */
		SCREEN_STATE_GRAVITY = 12,						/**< Gravity visible. */
		SCREEN_STATE_GRAVITY_ERASE = 13,				/**< Gravity being erased. */
		SCREEN_STATE_BARRIER = 14,						/**< Barrier visible. */
		SCREEN_STATE_BARRIER_ERASE = 15,				/**< Barrier being erased. */
		SCREEN_STATE_BARRIER_CONTROLLER = 16,			/**< Barrier controller visible. */
		SCREEN_STATE_BARRIER_CONTROLLER_ERASE = 17,		/**< Barrier controller being erased. */
		SCREEN_STATE_BOULDER = 18,						/**< Boulder visible. */
		SCREEN_STATE_BOULDER_ERASE = 19,				/**< Boulder being erased. */
		SCREEN_STATE_DOOR = 20,							/**< Door visible. */
		SCREEN_STATE_DOOR_ERASE = 21,					/**< Door being erased. */
		SCREEN_STATE_WET_SOIL = 22,						/**< Wet soil visible. */
		SCREEN_STATE_WET_SOIL_ERASE = 23,				/**< Wet soil being erased. */
	};

	s32 _timer;									/**< Length of time current block has been visible. */
	GameFont _font;								/**< Font used to render text. */
	BlockBase* _block;							/**< Current block. */
	ScreenState _state;							/**< State of the slideshow. */
	WoopsiGfx::WoopsiString _blockName;			/**< Name of the current block. */
	WoopsiGfx::WoopsiString _blockDescription;	/**< Description of the current block. */

	/**
	 * Chooses the next block based on the current state.  Updates the block
	 * pointer and name/description members.
	 */
	void getNextBlock();

	/**
	 * Switches to the next state.
	 */
	void moveToNextState();

};

#endif
