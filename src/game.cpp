#include <woopsistring.h>

#include "game.h"
#include "constants.h"
#include "bitmapserver.h"
#include "soundplayer.h"
#include "levelio.h"

#include "leveldefinitionbase.h"

#include "levelfactory.h"
#include "leveldefinitions.h"

Game::Game() {
	_topGfx = Hardware::getTopGfx();
	_bottomGfx = Hardware::getBottomGfx();
}

Game::~Game() {

}

bool Game::isRunning() const {
	return true;
}

LevelDefinitionBase* Game::runTitleScreen() {
	SoundPlayer::stopAll();

	TitleScreen* titleScreen = new TitleScreen(_topGfx, _bottomGfx);

	while (titleScreen->isRunning()) {
		titleScreen->iterate();
		Hardware::waitForVBlank();
	}

	runTransition();

	LevelDefinitionBase* chosenLevel = titleScreen->getChosenLevel();

	delete titleScreen;

	return chosenLevel;
}

void Game::runTransition() {

	GateTransition transition(_topGfx, _bottomGfx);

	while (transition.isRunning()) {
		transition.iterate();
		Hardware::waitForVBlank();
	}
}

void Game::runGameOver(s32 score, s32 levelNumber) {

	runTransition();

	// Game has ended; set up a new game over screen and kill the level
	GameOverScreen* gameOverScreen = new GameOverScreen(_topGfx, _bottomGfx, score, levelNumber);

	while (gameOverScreen->isRunning()) {
		gameOverScreen->iterate();
		Hardware::waitForVBlank();
	}

	delete gameOverScreen;
}

void Game::runGameComplete(s32 score) {

	// Game is complete; set up a new game complete screen and kill the level
	GameCompleteScreen* gameCompleteScreen = new GameCompleteScreen(_topGfx, _bottomGfx, score);

	while (gameCompleteScreen->isRunning()) {
		gameCompleteScreen->iterate();
		Hardware::waitForVBlank();
	}

	delete gameCompleteScreen;
}

void Game::main() {

	while (isRunning()) {

		GameSession* session = new GameSession();
		LevelDefinitionBase* startLevel = runTitleScreen();

		session->run(startLevel);

		if (session->isGameOver()) {
			runGameOver(session->getScore(), session->getLevel()->getNumber());
		} else if (session->isGameComplete()) {
			runGameComplete(session->getScore());
		}

		session->reset();
		delete session;
	}
}
