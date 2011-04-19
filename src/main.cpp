#include <nds.h>
#include "framebuffer.h"
#include "graphics.h"
#include "game.h"
#include "constants.h"
#include "bitmapserver.h"
#include "titlescreen.h"
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

void showTitle(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) {
	TitleScreen title(topGfx, bottomGfx);

	while (title.isRunning()) {
		title.iterate();
		swiWaitForVBlank();
	}
}

int main(int argc, char* argv[]) {
	initGfxMode();

	WoopsiGfx::FrameBuffer topBuffer((u16*)BG_BMP_RAM(0), SCREEN_WIDTH, SCREEN_HEIGHT);
	WoopsiGfx::FrameBuffer bottomBuffer((u16*)BG_BMP_RAM_SUB(0), SCREEN_WIDTH, SCREEN_HEIGHT);

	WoopsiGfx::Graphics* topGfx = topBuffer.newGraphics();
	WoopsiGfx::Graphics* bottomGfx = bottomBuffer.newGraphics();

	while (1) {

		s32 level = 0;
		s32 score = 0;

		showTitle(topGfx, bottomGfx);
		runGame(topGfx, bottomGfx, score, level);
		showGameOver(topGfx, bottomGfx, score, level);
	}

	BitmapServer::shutdown();

	delete topGfx;
	delete bottomGfx;

	return 0;
}
