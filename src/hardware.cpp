#include "hardware.h"

PadState Hardware::_pad;
StylusState Hardware::_stylus;

SDLFrameBuffer* Hardware::_topBuffer = NULL;
SDLFrameBuffer* Hardware::_bottomBuffer = NULL;

WoopsiGfx::Graphics* Hardware::_topGfx = NULL;
WoopsiGfx::Graphics* Hardware::_bottomGfx = NULL;

bool Hardware::_isMostRecentDirectionVertical = false;

void Hardware::init() {
	powerOn(POWER_ALL_2D);

	videoSetMode( MODE_5_2D | DISPLAY_BG3_ACTIVE );
	videoSetModeSub( MODE_5_2D | DISPLAY_BG3_ACTIVE );

	vramSetBankA( VRAM_A_MAIN_BG );
	vramSetBankC( VRAM_C_SUB_BG );

	// Initialise backgrounds
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

	_topBuffer = new SDLFrameBuffer((u16*)BG_BMP_RAM(0), SCREEN_WIDTH, SCREEN_HEIGHT);
	_bottomBuffer = new SDLFrameBuffer((u16*)BG_BMP_RAM_SUB(0), SCREEN_WIDTH, SCREEN_HEIGHT);

	_topGfx = _topBuffer->newGraphics();
	_bottomGfx = _bottomBuffer->newGraphics();

	updatePadState();
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

	s32 pressed = keysDown();	// buttons pressed this loop
	s32 held = keysHeld();		// buttons currently held
	s32 allKeys = pressed | held;

	_pad.up = allKeys & KEY_UP;
	_pad.down = allKeys & KEY_DOWN;
	_pad.left = allKeys & KEY_LEFT;
	_pad.right = allKeys & KEY_RIGHT;
	_pad.l = allKeys & KEY_L;
	_pad.r = allKeys & KEY_R;
	_pad.a = allKeys & KEY_A;
	_pad.b = allKeys & KEY_B;
	_pad.x = allKeys & KEY_X;
	_pad.y = allKeys & KEY_Y;
	_pad.start = allKeys & KEY_START;
	_pad.select = allKeys & KEY_SELECT;

	if ((_pad.up && !oldPad.up) || (_pad.down && !oldPad.down)) {
		_isMostRecentDirectionVertical = true;
	} else if ((_pad.left && !oldPad.left) || (_pad.right && !oldPad.right)) {
		_isMostRecentDirectionVertical = false;
	}

	touchPosition touch;
	touchRead(&touch);

	if (_stylus.newPress) {
		_stylus.held = true;
		_stylus.newPress = false;
	}

	_stylus.released = false;

	if ((allKeys & KEY_TOUCH) && (!_stylus.held)) {
		
		// New click
		_stylus.newPress = true;
		_stylus.released = false;

	} else if ((!(allKeys & KEY_TOUCH)) && (_stylus.held)) {
		
		// Release
		_stylus.released = true;
		_stylus.newPress = false;
		_stylus.held = false;
	}

	_stylus.x = touch.px;
	_stylus.y = touch.py;
}

bool Hardware::isMostRecentDirectionVertical() {
	return _isMostRecentDirectionVertical;
}

void Hardware::waitForVBlank() {
	swiWaitForVBlank();
	updatePadState();
}
