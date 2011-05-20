#include "hardware.h"

PadState Hardware::_pad;

WoopsiGfx::FrameBuffer* Hardware::_topBuffer = NULL;
WoopsiGfx::FrameBuffer* Hardware::_bottomBuffer = NULL;

WoopsiGfx::Graphics* Hardware::_topGfx = NULL;
WoopsiGfx::Graphics* Hardware::_bottomGfx = NULL;

s32 Hardware::_padHistory[PAD_HISTORY_SIZE];

s32 Hardware::_upPriority = 0;
s32 Hardware::_downPriority = 0;
s32 Hardware::_leftPriority = 0;
s32 Hardware::_rightPriority = 0;

void Hardware::init() {
	powerOn(POWER_ALL_2D);

	videoSetMode( MODE_5_2D | DISPLAY_BG3_ACTIVE );
	videoSetModeSub( MODE_5_2D | DISPLAY_BG3_ACTIVE );

	vramSetBankA( VRAM_A_MAIN_BG );
	vramSetBankC( VRAM_C_SUB_BG );

	// Initialise backgrounds
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

	_topBuffer = new WoopsiGfx::FrameBuffer((u16*)BG_BMP_RAM(0), SCREEN_WIDTH, SCREEN_HEIGHT);
	_bottomBuffer = new WoopsiGfx::FrameBuffer((u16*)BG_BMP_RAM_SUB(0), SCREEN_WIDTH, SCREEN_HEIGHT);

	_topGfx = _topBuffer->newGraphics();
	_bottomGfx = _bottomBuffer->newGraphics();

	updatePadState();

	for (s32 i = 0; i < PAD_HISTORY_SIZE; ++i) {
		_padHistory[i] = 0;
	}
}

void Hardware::shutdown() {
	delete _topGfx;
	delete _bottomGfx;
	delete _topBuffer;
	delete _bottomBuffer;
}

void Hardware::updatePadState() {
	scanKeys();

	PadState oldPad = _pad;

	_pad.up = (keysDown() & KEY_UP) || (keysHeld() & KEY_UP);
	_pad.down = (keysDown() & KEY_DOWN) || (keysHeld() & KEY_DOWN);
	_pad.left = (keysDown() & KEY_LEFT) || (keysHeld() & KEY_LEFT);
	_pad.right = (keysDown() & KEY_RIGHT) || (keysHeld() & KEY_RIGHT);
	_pad.l = ((keysDown() & KEY_L) || (keysHeld() & KEY_L));
	_pad.r = ((keysDown() & KEY_R) || (keysHeld() & KEY_R));
	_pad.a = ((keysDown() & KEY_A) || (keysHeld() & KEY_A));
	_pad.b = ((keysDown() & KEY_B) || (keysHeld() & KEY_B));
	_pad.x = ((keysDown() & KEY_X) || (keysHeld() & KEY_X));
	_pad.y = ((keysDown() & KEY_Y) || (keysHeld() & KEY_Y));
	_pad.start = ((keysDown() & KEY_START) || (keysHeld() & KEY_START));
	_pad.select = ((keysDown() & KEY_SELECT) || (keysHeld() & KEY_SELECT));

	if (_pad.up != oldPad.up) {
		queuePadHistory(KEY_UP);
	} else if (_pad.down != oldPad.down) {
		queuePadHistory(KEY_DOWN);
	} else if (_pad.left != oldPad.left) {
		queuePadHistory(KEY_LEFT);
	} else if (_pad.right != oldPad.right) {
		queuePadHistory(KEY_RIGHT);
	} else if (_pad.l != oldPad.l) {
		queuePadHistory(KEY_L);
	} else if (_pad.r != oldPad.r) {
		queuePadHistory(KEY_R);
	} else if (_pad.a != oldPad.a) {
		queuePadHistory(KEY_A);
	} else if (_pad.b != oldPad.b) {
		queuePadHistory(KEY_B);
	} else if (_pad.x != oldPad.x) {
		queuePadHistory(KEY_X);
	} else if (_pad.y != oldPad.y) {
		queuePadHistory(KEY_Y);
	} else if (_pad.start != oldPad.start) {
		queuePadHistory(KEY_START);
	} else if (_pad.select != oldPad.select) {
		queuePadHistory(KEY_SELECT);
	}

	calculateDirectionPriorities();
}

void Hardware::calculateDirectionPriorities() {
	_upPriority = 0;
	_downPriority = 0;
	_leftPriority = 0;
	_rightPriority = 0;

	s32 currentPriority = 8;

	for (s32 i = 0; i < PAD_HISTORY_SIZE; ++i) {
		if ((_padHistory[i] == KEY_UP) && (_upPriority == 0)) {
			_upPriority = currentPriority;
			currentPriority >>= 1;
		} else if ((_padHistory[i] == KEY_DOWN) && (_upPriority == 0)) {
			_downPriority = currentPriority;
			currentPriority >>= 1;
		} else if ((_padHistory[i] == KEY_LEFT) && (_upPriority == 0)) {
			_leftPriority = currentPriority;
			currentPriority >>= 1;
		} else if ((_padHistory[i] == KEY_RIGHT) && (_upPriority == 0)) {
			_rightPriority = currentPriority;
			currentPriority >>= 1;
		}

		// Stop iterating if we've already assigned all priorities
		if (currentPriority == 0) break;
	}
}

bool Hardware::isMostRecentDirectionVertical() {
	return (_upPriority + _downPriority) > (_leftPriority + _rightPriority);
}

void Hardware::queuePadHistory(s32 key) {
	for (s32 i = PAD_HISTORY_SIZE - 1; i > 0; --i) {
		_padHistory[i] = _padHistory[i - 1];
	}

	_padHistory[0] = key;
}

void Hardware::waitForVBlank() {
	swiWaitForVBlank();
	updatePadState();
}
