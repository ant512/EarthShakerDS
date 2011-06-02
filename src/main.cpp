#include <nds.h>
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

	Game* game = new Game();
	game->main();

	delete game;

	BitmapServer::shutdown();
	SoundPlayer::shutdown();
	Hardware::shutdown();

	return 0;
}
