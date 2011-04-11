#include <nds.h>
#include "framebuffer.h"
#include "graphics.h"
#include "game.h"
#include "constants.h"

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

int main(int argc, char* argv[]) {
	initGfxMode();

	WoopsiGfx::FrameBuffer topBuffer((u16*)BG_BMP_RAM(0), DISPLAY_WIDTH, DISPLAY_HEIGHT);
	WoopsiGfx::FrameBuffer bottomBuffer((u16*)BG_BMP_RAM_SUB(0), DISPLAY_WIDTH, DISPLAY_HEIGHT);

	WoopsiGfx::Graphics* topGfx = topBuffer.newGraphics();
	WoopsiGfx::Graphics* bottomGfx = bottomBuffer.newGraphics();

	Game* game = new Game(topGfx, bottomGfx);
	game->render();

	while(1) {
		scanKeys();
		game->setUpHeld((keysDown() & KEY_UP) || (keysHeld() & KEY_UP));
		game->setDownHeld((keysDown() & KEY_DOWN) || (keysHeld() & KEY_DOWN));
		game->setLeftHeld((keysDown() & KEY_LEFT) || (keysHeld() & KEY_LEFT));
		game->setRightHeld((keysDown() & KEY_RIGHT) || (keysHeld() & KEY_RIGHT));

		game->iterate();
		swiWaitForVBlank();
	}

	delete topGfx;
	delete bottomGfx;
	delete game;

	return 0;
}
