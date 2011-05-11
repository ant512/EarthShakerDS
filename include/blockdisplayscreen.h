#ifndef _BLOCK_DISPLAY_SCREEN_H_
#define _BLOCK_DISPLAY_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "blockbase.h"
#include "gamefont.h"
#include "screenbase.h"
#include "spectrumcolours.h"


const s32 BLOCK_DISPLAY_TIME = 200;

class BlockDisplayScreen : public ScreenBase {
public:
	BlockDisplayScreen(WoopsiGfx::Graphics* bottomGfx);

	~BlockDisplayScreen();

	void iterate(PadState pad);

	bool isRunning() const;

private:

	enum ScreenState {
		SCREEN_STATE_TELEPORT = 0,
		SCREEN_STATE_TELEPORT_ERASE = 1,
		SCREEN_STATE_BEAN = 2,
		SCREEN_STATE_BEAN_ERASE = 3,
		SCREEN_STATE_EXTRA_LIFE = 4,
		SCREEN_STATE_EXTRA_LIFE_ERASE = 5,
		SCREEN_STATE_DIAMOND = 6,
		SCREEN_STATE_DIAMOND_ERASE = 7,
		SCREEN_STATE_BUBBLE = 8,
		SCREEN_STATE_BUBBLE_ERASE = 9,
		SCREEN_STATE_FIRE = 10,
		SCREEN_STATE_FIRE_ERASE = 11,
		SCREEN_STATE_GRAVITY = 12,
		SCREEN_STATE_GRAVITY_ERASE = 13,
		SCREEN_STATE_BARRIER = 14,
		SCREEN_STATE_BARRIER_ERASE = 15,
		SCREEN_STATE_BARRIER_CONTROLLER = 16,
		SCREEN_STATE_BARRIER_CONTROLLER_ERASE = 17,
		SCREEN_STATE_BOULDER = 18,
		SCREEN_STATE_BOULDER_ERASE = 19,
		SCREEN_STATE_DOOR = 20,
		SCREEN_STATE_DOOR_ERASE = 21,
	};

	s32 _timer;
	s32 _blockX;
	s32 _blockY;
	GameFont _font;
	BlockBase* _block;
	ScreenState _state;
	WoopsiGfx::WoopsiString _blockName;
	WoopsiGfx::WoopsiString _blockDescription;

	void getNextBlock();
	void moveToNextState();

};

#endif
