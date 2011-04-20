#include <nds.h>
#include "framebuffer.h"
#include "graphics.h"
#include "game.h"
#include "constants.h"
#include "bitmapserver.h"
#include "titlescreen.h"

void initGfxMode() {
	powerOn(POWER_ALL_2D);

	videoSetMode( MODE_5_2D | DISPLAY_BG3_ACTIVE );
	videoSetModeSub( MODE_5_2D | DISPLAY_BG3_ACTIVE );

	vramSetBankA( VRAM_A_MAIN_BG );
	vramSetBankC( VRAM_C_SUB_BG );

	// Initialise backgrounds
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
}

PadState getPadState() {

	PadState pad;

	scanKeys();
	pad.up = (keysDown() & KEY_UP) || (keysHeld() & KEY_UP);
	pad.down = (keysDown() & KEY_DOWN) || (keysHeld() & KEY_DOWN);
	pad.left = (keysDown() & KEY_LEFT) || (keysHeld() & KEY_LEFT);
	pad.right = (keysDown() & KEY_RIGHT) || (keysHeld() & KEY_RIGHT);
	pad.l = ((keysDown() & KEY_L) || (keysHeld() & KEY_L));
	pad.r = ((keysDown() & KEY_R) || (keysHeld() & KEY_R));

	return pad;
}

void runGame(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) {
	Game* game = new Game(topGfx, bottomGfx);

	PadState pad;

	while(game->isRunning()) {

		pad = getPadState();

		game->iterate(pad);
		swiWaitForVBlank();
	}

	delete game;
}

void showTitle(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) {
	TitleScreen screen(topGfx, bottomGfx);
	PadState pad;

	while (screen.isRunning()) {
		pad = getPadState();
		screen.iterate(pad);
		swiWaitForVBlank();
	}
}

int main(int argc, char* argv[]) {
	initGfxMode();

	BitmapServer::init();

	WoopsiGfx::FrameBuffer topBuffer((u16*)BG_BMP_RAM(0), SCREEN_WIDTH, SCREEN_HEIGHT);
	WoopsiGfx::FrameBuffer bottomBuffer((u16*)BG_BMP_RAM_SUB(0), SCREEN_WIDTH, SCREEN_HEIGHT);

	WoopsiGfx::Graphics* topGfx = topBuffer.newGraphics();
	WoopsiGfx::Graphics* bottomGfx = bottomBuffer.newGraphics();

	while (1) {

		showTitle(topGfx, bottomGfx);
		runGame(topGfx, bottomGfx);
	}

	BitmapServer::shutdown();

	delete topGfx;
	delete bottomGfx;

	return 0;
}
