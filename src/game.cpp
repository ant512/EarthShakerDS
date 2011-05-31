#include <woopsistring.h>

#include "game.h"
#include "constants.h"
#include "bitmapserver.h"
#include "soundplayer.h"

#include "levelfactory.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "level6.h"
#include "level7.h"
#include "level8.h"
#include "level9.h"
#include "level10.h"
#include "level11.h"
#include "level12.h"
#include "level13.h"
#include "level14.h"
#include "level15.h"
#include "level16.h"
#include "level17.h"
#include "level18.h"
#include "level19.h"
#include "level20.h"
#include "level21.h"
#include "level22.h"
#include "level23.h"
#include "level24.h"
#include "level25.h"
#include "level26.h"
#include "level27.h"
#include "level28.h"
#include "level29.h"
#include "level30.h"
#include "level31.h"
#include "level32.h"

Game::Game() {
	_topGfx = Hardware::getTopGfx();
	_bottomGfx = Hardware::getBottomGfx();

	_session = NULL;

	_levelDefinitions.push_back(new Level1());
	_levelDefinitions.push_back(new Level2());
	_levelDefinitions.push_back(new Level3());
	_levelDefinitions.push_back(new Level4());
	_levelDefinitions.push_back(new Level5());
	_levelDefinitions.push_back(new Level6());
	_levelDefinitions.push_back(new Level7());
	_levelDefinitions.push_back(new Level8());
	_levelDefinitions.push_back(new Level9());
	_levelDefinitions.push_back(new Level10());
	_levelDefinitions.push_back(new Level11());
	_levelDefinitions.push_back(new Level12());
	_levelDefinitions.push_back(new Level13());
	_levelDefinitions.push_back(new Level14());
	_levelDefinitions.push_back(new Level15());
	_levelDefinitions.push_back(new Level16());
	_levelDefinitions.push_back(new Level17());
	_levelDefinitions.push_back(new Level18());
	_levelDefinitions.push_back(new Level19());
	_levelDefinitions.push_back(new Level20());
	_levelDefinitions.push_back(new Level21());
	_levelDefinitions.push_back(new Level22());
	_levelDefinitions.push_back(new Level23());
	_levelDefinitions.push_back(new Level24());
	_levelDefinitions.push_back(new Level25());
	_levelDefinitions.push_back(new Level26());
	_levelDefinitions.push_back(new Level27());
	_levelDefinitions.push_back(new Level28());
	_levelDefinitions.push_back(new Level29());
	_levelDefinitions.push_back(new Level30());
	_levelDefinitions.push_back(new Level31());
	_levelDefinitions.push_back(new Level32());
}

Game::~Game() {
	for (s32 i = 0; i < _levelDefinitions.size(); ++i) {
		delete _levelDefinitions[i];
	}
}


bool Game::isRunning() const {
	return true;
}

void Game::runTitleScreen() {
	SoundPlayer::stopAll();
	TitleScreen* titleScreen = new TitleScreen(_topGfx, _bottomGfx, &_levelDefinitions);

	while (titleScreen->isRunning()) {
		titleScreen->iterate();
		Hardware::waitForVBlank();
	}

	runTransition();

	LevelDefinition* chosenLevel = titleScreen->getChosenLevel();

	delete titleScreen;

	_session = new GameSession(&_levelDefinitions, chosenLevel);
}

void Game::runTransition() {

	GateTransition transition(_topGfx, _bottomGfx);

	while (transition.isRunning()) {
		transition.iterate();
		Hardware::waitForVBlank();
	}
}

void Game::runGameOver() {

	runTransition();

	// Game has ended; set up a new game over screen and kill the level
	GameOverScreen* gameOverScreen = new GameOverScreen(_topGfx, _bottomGfx, _session->getScore(), _session->getLevel()->getNumber());

	while (gameOverScreen->isRunning()) {
		gameOverScreen->iterate();
		Hardware::waitForVBlank();
	}

	delete gameOverScreen;

	delete _session;
	_session = NULL;
}

void Game::runGameComplete() {
	
	runTransition();

	// Game is complete; set up a new game complete screen and kill the level
	GameCompleteScreen* gameCompleteScreen = new GameCompleteScreen(_topGfx, _bottomGfx, _session->getScore());

	while (gameCompleteScreen->isRunning()) {
		gameCompleteScreen->iterate();
		Hardware::waitForVBlank();
	}

	delete gameCompleteScreen;

	delete _session;
	_session = NULL;
}

void Game::main() {

	while (isRunning()) {
		runTitleScreen();

		_session->main();

		if (_session->isGameOver()) {
			runGameOver();
		} else if (_session->isGameComplete()) {
			runGameComplete();
		}
	}
}
