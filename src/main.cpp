#include <nds.h>
#include "framebuffer.h"
#include "graphics.h"
#include "game.h"
#include "constants.h"
#include "bitmapserver.h"
#include "soundplayer.h"

#include "hardware.h"

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

	SoundPlayer::init();
	BitmapServer::init();

	WoopsiGfx::FrameBuffer topBuffer((u16*)BG_BMP_RAM(0), SCREEN_WIDTH, SCREEN_HEIGHT);
	WoopsiGfx::FrameBuffer bottomBuffer((u16*)BG_BMP_RAM_SUB(0), SCREEN_WIDTH, SCREEN_HEIGHT);

	WoopsiGfx::Graphics* topGfx = topBuffer.newGraphics();
	WoopsiGfx::Graphics* bottomGfx = bottomBuffer.newGraphics();

	PadState pad;

	Game* game = new Game(topGfx, bottomGfx);

	while(game->isRunning()) {
		Hardware::updateState();

		pad = Hardware::getPadState();

		game->iterate(pad);
		Hardware::waitForVBlank();
	}

	delete game;
	delete topGfx;
	delete bottomGfx;

	BitmapServer::shutdown();
	SoundPlayer::shutdown();

	return 0;
}
