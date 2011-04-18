#include <nds.h>
#include "framebuffer.h"
#include "graphics.h"
#include "game.h"
#include "constants.h"
#include "bitmapserver.h"
#include "logobmp.h"
#include "gameoverscreen.h"

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

void runGame(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, s32& score, s32& level) {
	Game* game = new Game(topGfx, bottomGfx);

	bool upHeld;
	bool downHeld;
	bool rightHeld;
	bool leftHeld;

	while(game->isRunning()) {
		scanKeys();
		upHeld = (keysDown() & KEY_UP) || (keysHeld() & KEY_UP);
		downHeld = (keysDown() & KEY_DOWN) || (keysHeld() & KEY_DOWN);
		leftHeld = (keysDown() & KEY_LEFT) || (keysHeld() & KEY_LEFT);
		rightHeld = (keysDown() & KEY_RIGHT) || (keysHeld() & KEY_RIGHT);

		while (((keysDown() & KEY_R) || (keysHeld() & KEY_R)) && ((keysDown() & KEY_L) || (keysHeld() & KEY_L))) {
			scanKeys();
			game->killPlayer();
		}

		game->iterate(upHeld, downHeld, leftHeld, rightHeld);
		swiWaitForVBlank();
	}

	score = game->getScore();
	level = game->getLevel()->getNumber();

	delete game;
}

void showGameOver(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, s32 score, s32 level) {
	GameOverScreen screen(topGfx, bottomGfx, score, level);
	
	while (screen.isRunning()) {
		screen.iterate();
		swiWaitForVBlank();
	}
}

int main(int argc, char* argv[]) {
	initGfxMode();

	WoopsiGfx::FrameBuffer topBuffer((u16*)BG_BMP_RAM(0), SCREEN_WIDTH, SCREEN_HEIGHT);
	WoopsiGfx::FrameBuffer bottomBuffer((u16*)BG_BMP_RAM_SUB(0), SCREEN_WIDTH, SCREEN_HEIGHT);

	WoopsiGfx::Graphics* topGfx = topBuffer.newGraphics();
	WoopsiGfx::Graphics* bottomGfx = bottomBuffer.newGraphics();

	LogoBmp logoBmp;
	GameFont font;

	bottomGfx->drawBitmap(0, 0, 256, 64, &logoBmp, 0, 0);

	// Copyrights
	WoopsiGfx::WoopsiString	str = "ZX (c) 1990 Michael Batty";
	bottomGfx->drawText((SCREEN_WIDTH - font.getStringWidth(str)) / 2, 176, &font, str, 0, str.getLength(), COLOUR_WHITE);

	str.setText("DS (c) 2011 Antony Dzeryn");
	bottomGfx->drawText((SCREEN_WIDTH - font.getStringWidth(str)) / 2, 184, &font, str, 0, str.getLength(), COLOUR_WHITE);

	while (1) {


		// TODO: Menu screen here
		s32 level = 0;
		s32 score = 0;

		runGame(topGfx, bottomGfx, score, level);
		showGameOver(topGfx, bottomGfx, score, level);
	}

	BitmapServer::shutdown();

	delete topGfx;
	delete bottomGfx;

	return 0;
}
