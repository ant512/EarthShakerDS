#include "hardware.h"

PadState Hardware::_pad;

WoopsiGfx::FrameBuffer* Hardware::_topBuffer = NULL;
WoopsiGfx::FrameBuffer* Hardware::_bottomBuffer = NULL;

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

	_topBuffer = new WoopsiGfx::FrameBuffer((u16*)BG_BMP_RAM(0), SCREEN_WIDTH, SCREEN_HEIGHT);
	_bottomBuffer = new WoopsiGfx::FrameBuffer((u16*)BG_BMP_RAM_SUB(0), SCREEN_WIDTH, SCREEN_HEIGHT);

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

	if ((_pad.up && !oldPad.up) || (_pad.down && !oldPad.down)) {
		_isMostRecentDirectionVertical = true;
	} else if ((_pad.left && !oldPad.left) || (_pad.right && !oldPad.right)) {
		_isMostRecentDirectionVertical = false;
	}
}

bool Hardware::isMostRecentDirectionVertical() {
	return _isMostRecentDirectionVertical;
}

void Hardware::waitForVBlank() {
	swiWaitForVBlank();
	updatePadState();
}
