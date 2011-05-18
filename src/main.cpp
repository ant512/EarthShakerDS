#include <nds.h>
#include "framebuffer.h"
#include "graphics.h"
#include "game.h"
#include "constants.h"
#include "bitmapserver.h"
#include "soundplayer.h"

#include "hardware.h"

int main(int argc, char* argv[]) {

	SoundPlayer::init();
	BitmapServer::init();
	Hardware::init();

	Game* game = new Game(Hardware::getTopGfx(), Hardware::getBottomGfx());

	while(game->isRunning()) {
		game->iterate();
		Hardware::waitForVBlank();
	}

	delete game;

	BitmapServer::shutdown();
	SoundPlayer::shutdown();
	Hardware::shutdown();

	return 0;
}
