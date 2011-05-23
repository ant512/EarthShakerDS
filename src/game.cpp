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
	_isOddIteration = true;
	_level = NULL;
	_state = GAME_STATE_TITLE_SCREEN;

	_hud = new GameHUD();

	_topGfx = Hardware::getTopGfx();
	_bottomGfx = Hardware::getBottomGfx();

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

	delete _hud;
}

s32 Game::getScore() const {
	return _score;
}

s32 Game::getRemainingTime() const {
	return _remainingTime;
}

s32 Game::getRemainingDiamonds() const {
	return _level->getDiamondCount() - _collectedDiamonds;
}

Level* Game::getLevel() const {
	return _level;
}

bool Game::isRunning() const {
	return (_state != GAME_STATE_NOT_RUNNING);
}

bool Game::isOddIteration() const {
	return _isOddIteration;
}

void Game::addScore(s32 score) {
	_score += score;
	_hud->drawScore(_score);
}

PlayerBlock* Game::getPlayerBlock() const {
	return _level->getPlayerBlock();
}

void Game::render() {

	_level->animate();

	// Get the size of the display measured in blocks
	s32 displayWidth = GAME_WIDTH / BlockBase::BLOCK_SIZE;
	s32 displayHeight = GAME_HEIGHT / BlockBase::BLOCK_SIZE;

	// The centre of the display should be the player, unless the player is too
	// close to an edge for the display to scroll.  In that situation, we keep
	// the edge of the map at the edge of the display and move the player
	// around instead.  Assume for the moment that the player is at the centre
	// of the screen
	s32 centreX = getPlayerBlock()->getX();
	s32 centreY = getPlayerBlock()->getY();

	// Get the top-left corner based on the assumption that the player is at the
	// centre of the screen
	s32 x = centreX - (displayWidth / 2);
	s32 y = centreY - (displayHeight / 2);

	// Prevent scrolling past the end of the level.  This accounts for the
	// situation in which the player is not the centre of the screen
	if (x + displayWidth > _level->getWidth()) x = _level->getWidth() - displayWidth;
	if (x < 0) x = 0;

	if (y + displayHeight > _level->getHeight()) y = _level->getHeight() - displayHeight;
	if (y < 0) y = 0;

	_level->render(x, y, displayWidth, displayHeight, _topGfx);
}

void Game::showMap() {
	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 16, COLOUR_BLACK);
	
	// Top border
	_topGfx->drawLine(5, 4, 250, 4, COLOUR_MAGENTA);
	_topGfx->drawLine(4, 5, 251, 5, COLOUR_MAGENTA);

	// Left border
	_topGfx->drawLine(4, 5, 4, 170, COLOUR_MAGENTA);
	_topGfx->drawLine(5, 5, 5, 170, COLOUR_MAGENTA);

	// Right border
	_topGfx->drawLine(250, 5, 250, 170, COLOUR_MAGENTA);
	_topGfx->drawLine(251, 5, 251, 170, COLOUR_MAGENTA);

	// Bottom border
	_topGfx->drawLine(5, 171, 250, 171, COLOUR_MAGENTA);
	_topGfx->drawLine(4, 170, 250, 170, COLOUR_MAGENTA);

	_level->renderMap(_topGfx);

	// Abuse movement timer to work as map timer
	_movementTimer = 0;

	// Map is only visible once per level per life
	_isMapAvailable = false;

	SoundPlayer::stopAll();
	SoundPlayer::playMapTheme();

	const PadState& pad = Hardware::getPadState();

	bool xHeld = pad.x;

	// Show the map until the timer expires or X is pressed
	while (_movementTimer < MAP_TIME) {
		++_movementTimer;
		Hardware::waitForVBlank();

		if (!pad.x && xHeld) {

			// X has been released; we can now listen for X as a way of exiting
			// the map early
			xHeld = false;

		} else if (pad.x && !xHeld) {

			// X has been pressed again; we can exit the map early
			break;
		}
	}

	_movementTimer = 0;

	SoundPlayer::stopMapTheme();

	render();
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

	_score = 0;
	_lives = STARTING_LIVES;

	startLevel(chosenLevel);
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
	GameOverScreen* gameOverScreen = new GameOverScreen(_topGfx, _bottomGfx, _score, _level->getNumber());

	delete _level;
	_level = NULL;

	while (gameOverScreen->isRunning()) {
		gameOverScreen->iterate();
		Hardware::waitForVBlank();
	}

	delete gameOverScreen;

	_state = GAME_STATE_TITLE_SCREEN;
}

void Game::runGameComplete() {
	
	runTransition();

	// Game is complete; set up a new game complete screen and kill the level
	GameCompleteScreen* gameCompleteScreen = new GameCompleteScreen(_topGfx, _bottomGfx, _score);

	delete _level;
	_level = NULL;

	while (gameCompleteScreen->isRunning()) {
		gameCompleteScreen->iterate();
		Hardware::waitForVBlank();
	}

	delete gameCompleteScreen;

	_state = GAME_STATE_TITLE_SCREEN;
}

void Game::pause() {

	const PadState& pad = Hardware::getPadState();

	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 16, COLOUR_BLACK);
	_topGfx->drawText(104, 84, &_font, "Paused", 0, 6, COLOUR_YELLOW);
	_topGfx->drawText(48, 100, &_font, "Press X to exit game", 0, 20, COLOUR_YELLOW);

	SoundPlayer::stopAll();
	SoundPlayer::playPause();

	while (pad.start) {
		Hardware::waitForVBlank();
	}

	while (!pad.start && !pad.x) {
		Hardware::waitForVBlank();
	}

	if (pad.start) {

		while (pad.start) {
			Hardware::waitForVBlank();
		}

		render();
	} else if (pad.x) {
		_state = GAME_STATE_TITLE_SCREEN;

		delete _level;
		_level = NULL;
	}
}

void Game::runLevelComplete() {

	while (_remainingTime > 0) {
		_remainingTime -= _remainingTime >= 4 ? 4 : _remainingTime;
		addScore(_remainingTime >= 4 ? 4 : _remainingTime);		// One point per second

		_hud->drawTimerBar(_remainingTime);

		Hardware::waitForVBlank();
	}

	runTransition();

	if (_level->getNumber() < _levelDefinitions.size() - 1) {
		startLevel(_levelDefinitions[_level->getNumber()]);
	} else {
		_state = GAME_STATE_GAME_COMPLETE;
	}
}

void Game::runGame() {

	const PadState& pad = Hardware::getPadState();

	animate();
	timer();
	move();

	if (pad.start) {
		pause();
	} else if (pad.x && _isMapAvailable) {
		showMap();
	} else if (pad.r && pad.l) {
		commitSuicide();
	}
}

void Game::main() {

	while (isRunning()) {
		switch (_state) {

			case GAME_STATE_NOT_RUNNING:
				return;

			case GAME_STATE_TITLE_SCREEN:
				runTitleScreen();
				break;

			case GAME_STATE_GAMEPLAY:
				runGame();
				break;

			case GAME_STATE_LEVEL_COMPLETE:
				runLevelComplete();
				break;

			case GAME_STATE_GAME_OVER:
				runGameOver();
				break;

			case GAME_STATE_GAME_COMPLETE:
				runGameComplete();
				break;
		}

		Hardware::waitForVBlank();
	}
}

void Game::timer() {
	_levelTimer++;

	if (_levelTimer == TIMER_TIME) {
		_levelTimer = 0;

		decreaseTime();

		SoundPlayer::playTime();
	}
}

void Game::animate() {
	_animationTimer++;

	if (_animationTimer == ANIMATION_TIME) {
		_animationTimer = 0;

		render();
	}
}

void Game::commitSuicide() {
	SoundPlayer::playSuicide();

	while (_remainingTime > 0) {
		_remainingTime -= 4;
		_hud->drawTimerBar(_remainingTime);
		Hardware::waitForVBlank();
	}

	decreaseLives();

	if (_lives > 0) {
		resetLevel();
	} else {
		_state = GAME_STATE_GAME_OVER;
	}
}

void Game::move() {

	_movementTimer++;

	if (_movementTimer == MOVEMENT_TIME) {
		_movementTimer = 0;

		movePlayer();

		_level->iterate(isGravityInverted());
		_isOddIteration = !_isOddIteration;

		if (_remainingGravityTime > 0) {
			--_remainingGravityTime;
			_hud->drawGravityCounter(_remainingGravityTime);

			if (_remainingGravityTime == 0) {
				_hud->drawGravityIndicator(false);
			}
		}

		// If the last iteration of the game caused the player to die, we either
		// need to reset the level to its default state or end the game
		if (_level->getPlayerBlock()->isDestroyed()) {
			if (_lives > 0) {
				resetLevel();
			} else {
				_state = GAME_STATE_GAME_OVER;
			}
		}
	}
}

void Game::movePlayer() {
	bool moved = false;

	const PadState& pad = Hardware::getPadState();
	PlayerBlock* player = _level->getPlayerBlock();

	if (Hardware::isMostRecentDirectionVertical()) {

		// Attempt to move vertically before horizontally, as the most
		// recent button pushed was a vertical direction
		if (pad.up) {
			moved = player->pushUp();
		} else if (pad.down) {
			moved = player->pushDown();
		}

		// Allow horizontal movement even if a vertical button is also
		// pressed, but only if the player hasn't already moved.  This
		// should reduce the frustration of needing super-speedy fingers to
		// let go of one direction and then press the next within a couple
		// of VBLs.
		if (!moved) {
			if (pad.left) {
				player->pushLeft();
			} else if (pad.right) {
				player->pushRight();
			}
		}
	} else {

		// Attempt to move horizontally before vertically, as the most
		// recent button pushed was a horizontal direction
		if (pad.left) {
			moved = player->pushLeft();
		} else if (pad.right) {
			moved = player->pushRight();
		}

		// Allow horizontal movement even if a vertical button is also
		// pressed, but only if the player hasn't already moved.  This
		// should reduce the frustration of needing super-speedy fingers to
		// let go of one direction and then press the next within a couple
		// of VBLs.
		if (!moved) {
			if (pad.up) {
				player->pushUp();
			} else if (pad.down) {
				player->pushDown();
			}
		}
	}
}

bool Game::isGravityInverted() const {
	return _remainingGravityTime > 0;
}

void Game::increaseTime(s32 time) {
	_remainingTime += time;

	if (_remainingTime > STARTING_TIME) _remainingTime = STARTING_TIME;

	// We have to redraw the background and then redraw the black overlay to
	// correctly show the state of the timer bar
	_hud->drawTimerBarBackground();
	_hud->drawTimerBar(_remainingTime);
}

void Game::increaseCollectedDiamonds() {
	++_collectedDiamonds;
	_hud->drawDiamondCounters(_level->getDiamondCount(), _collectedDiamonds);
}

void Game::increaseLives() {
	++_lives;
	_hud->drawLifeCounter(_lives);
}

void Game::decreaseLives() {
	--_lives;
	_hud->drawLifeCounter(_lives);
}

void Game::decreaseTime() {
	--_remainingTime;

	_hud->drawTimerBar(_remainingTime);

	if (_remainingTime == 0) {
		getPlayerBlock()->explode();
	}
}

void Game::invertGravity() {
	_remainingGravityTime = GRAVITY_INVERSION_TIME;

	SoundPlayer::playGravityInversion();

	_hud->drawGravityCounter(_remainingGravityTime);
	_hud->drawGravityIndicator(true);
}

void Game::resetLevelVariables() {
	_state = GAME_STATE_GAMEPLAY;
	_collectedDiamonds = 0;
	_remainingTime = STARTING_TIME;
	_remainingGravityTime = 0;
	_isMapAvailable = true;

	_animationTimer = 0;
	_movementTimer = 0;
	_levelTimer = 0;
}

void Game::resetLevel() {
	resetLevelVariables();

	SoundPlayer::stopAll();

	s32 levelNumber = 0;

	if (_level != NULL) {
		levelNumber = _level->getNumber();
		delete _level;
	}

	_level = LevelFactory::createLevel(_levelDefinitions[levelNumber - 1], this);

	_hud->drawBackground(_level->getDiamondCount(),
						 _collectedDiamonds,
						 _remainingGravityTime,
						 isGravityInverted(),
						 _lives,
						 _score,
						 _level->getName(),
						 _level->getNumber());
}

void Game::startLevel(LevelDefinition* levelDefinition) {
	resetLevelVariables();

	SoundPlayer::stopAll();

	if (_level != NULL) {
		delete _level;
	}

	_level = LevelFactory::createLevel(levelDefinition, this);
	levelDefinition->recolourBitmaps();

	_hud->drawBackground(_level->getDiamondCount(),
						 _collectedDiamonds,
						 _remainingGravityTime,
						 isGravityInverted(),
						 _lives,
						 _score,
						 _level->getName(),
						 _level->getNumber());
}

void Game::endLevel() {
	_state = GAME_STATE_LEVEL_COMPLETE;
	SoundPlayer::stopAll();
	SoundPlayer::playLevelComplete();
}
