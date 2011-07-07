#include <woopsistring.h>

#include "gamesession.h"
#include "constants.h"
#include "bitmapserver.h"
#include "soundplayer.h"

#include "leveldefinitionbase.h"
#include "levelfactory.h"

GameSession::GameSession(WoopsiArray<LevelDefinitionBase*>* levelDefinitions) {
	
	_level = NULL;
	
	reset();

	_topGfx = Hardware::getTopGfx();
	_bottomGfx = Hardware::getBottomGfx();

	_levelDefinitions = levelDefinitions;
}

GameSession::~GameSession() {
	if (_level != NULL) {
		delete _level;
		_level = NULL;
	}
}

void GameSession::reset() {
	_isOddIteration = true;

	if (_level != NULL) delete _level;

	_level = NULL;
	_isRunning = true;

	_score = 0;
	_lives = STARTING_LIVES;

	_isGameComplete = false;
	_isGameOver = false;
}

s32 GameSession::getScore() const {
	return _score;
}

s32 GameSession::getRemainingTime() const {
	return _remainingTime;
}

s32 GameSession::getRemainingDiamonds() const {
	return _level->getDiamondCount() - _collectedDiamonds;
}

Level* GameSession::getLevel() const {
	return _level;
}

bool GameSession::isRunning() const {
	return _isRunning;
}

bool GameSession::isGameOver() const {
	return _isGameOver;
}

bool GameSession::isGameComplete() const {
	return _isGameComplete;
}

bool GameSession::isOddIteration() const {
	return _isOddIteration;
}

void GameSession::addScore(s32 score) {
	_score += score;
	_hud.drawScore(_score);
}

PlayerBlock* GameSession::getPlayerBlock() const {
	return _level->getPlayerBlock();
}

void GameSession::render() {

	_level->animate();

	// The centre of the display should be the player, unless the player is too
	// close to an edge for the display to scroll.
	s32 centreX = getPlayerBlock()->getX();
	s32 centreY = getPlayerBlock()->getY();

	_level->render(centreX, centreY, _topGfx);
}

void GameSession::drawMapBorder() {
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
}

void GameSession::showMap() {
	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 16, COLOUR_BLACK);
	
	drawMapBorder();

	_level->renderMap(_topGfx);

	s32 timer = 0;

	// Map is only visible once per level per life
	_isMapAvailable = false;

	SoundPlayer::stopAll();
	SoundPlayer::playMapTheme();

	const Pad& pad = Hardware::getPad();

	// Show the map until the timer expires or Select is pressed
	while (timer < MAP_TIME) {
		++timer;
		Hardware::waitForVBlank();

		if (!pad.isSelectNewPress()) {
			break;
		}
	}

	SoundPlayer::stopMapTheme();

	render();
}

void GameSession::runTransition() {

	GateTransition transition(_topGfx, _bottomGfx);

	while (transition.isRunning()) {
		transition.iterate();
		Hardware::waitForVBlank();
	}
}

void GameSession::pause() {

	const Pad& pad = Hardware::getPad();

	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 16, COLOUR_BLACK);
	_topGfx->drawText(104, 84, &_font, "Paused", 0, 6, COLOUR_YELLOW);
	_topGfx->drawText(48, 100, &_font, "Press X to exit game", 0, 20, COLOUR_YELLOW);

	SoundPlayer::stopAll();
	SoundPlayer::playPause();

	Hardware::waitForVBlank();

	// Wait for Start or X
	while (!pad.isStartNewPress() && !pad.isXNewPress()) {
		Hardware::waitForVBlank();
	}

	if (pad.isStartNewPress()) {
		render();
	} else if (pad.isXNewPress()) {

		// End the session
		_isRunning = false;
	}

	Hardware::waitForVBlank();
}

void GameSession::run(LevelDefinitionBase* level) {

	startLevel(level);

	const Pad& pad = Hardware::getPad();

	while (isRunning()) {
		
		checkLevelComplete();
		animate();
		timer();
		move();

		if (pad.isStartNewPress()) {
			pause();
		} else if (pad.isSelectNewPress() && _isMapAvailable) {
			showMap();
		} else if (pad.isLHeld() && pad.isLHeld()) {
			commitSuicide();
		}

		Hardware::waitForVBlank();
	}
}

void GameSession::checkLevelComplete() {
	
	if (_isLevelComplete) {
		
		SoundPlayer::stopAll();
		SoundPlayer::playLevelComplete();
		
		while (_remainingTime > 0) {
			_remainingTime -= _remainingTime >= 4 ? 4 : _remainingTime;
			addScore(_remainingTime >= 4 ? 4 : _remainingTime);		// One point per second
			
			_hud.drawTimerBar(_remainingTime);
			
			Hardware::waitForVBlank();
		}
		
		runTransition();
		
		if (_level->getNumber() < _levelDefinitions->size() - 1) {
			startLevel(_levelDefinitions->at(_level->getNumber()));
		} else {
			_isRunning = false;
			_isGameComplete = true;
		}
	}
}

void GameSession::timer() {
	_levelTimer++;

	if (_levelTimer == TIMER_TIME) {
		_levelTimer = 0;

		decreaseTime();

		SoundPlayer::playTime();
	}
}

void GameSession::animate() {
	_animationTimer++;

	if (_animationTimer == ANIMATION_TIME) {
		_animationTimer = 0;

		render();
	}
}

void GameSession::commitSuicide() {
	SoundPlayer::playSuicide();

	while (_remainingTime > 0) {
		_remainingTime -= 4;
		_hud.drawTimerBar(_remainingTime);
		Hardware::waitForVBlank();
	}

	decreaseLives();

	if (_lives > 0) {
		resetLevel();
		render();
	} else {
		_isRunning = false;
		_isGameOver = true;
	}
}

void GameSession::move() {

	_movementTimer++;

	if (_movementTimer != MOVEMENT_TIME) return;

	_movementTimer = 0;

	movePlayer();

	_level->iterate(isGravityInverted());
	_isOddIteration = !_isOddIteration;

	decreaseGravityTime();

	// If the last iteration of the game caused the player to die, we either
	// need to reset the level to its default state or end the game
	if (_level->getPlayerBlock()->isDestroyed()) {
		if (_lives > 0) {
			resetLevel();
		} else {
			_isRunning = false;
			_isGameOver = true;
		}
	}
}

void GameSession::movePlayer() {
	bool moved = false;

	const Pad& pad = Hardware::getPad();
	PlayerBlock* player = _level->getPlayerBlock();

	if (pad.isMostRecentDirectionVertical()) {

		// Attempt to move vertically before horizontally, as the most
		// recent button pushed was a vertical direction
		if (pad.isUpHeld()) {
			moved = player->pushUp();
		} else if (pad.isDownHeld()) {
			moved = player->pushDown();
		}

		// Allow horizontal movement even if a vertical button is also
		// pressed, but only if the player hasn't already moved.  This
		// should reduce the frustration of needing super-speedy fingers to
		// let go of one direction and then press the next within a couple
		// of VBLs.
		if (!moved) {
			if (pad.isLeftHeld()) {
				moved = player->pushLeft();
			} else if (pad.isRightHeld()) {
				moved = player->pushRight();
			}
		}
	} else {

		// Attempt to move horizontally before vertically, as the most
		// recent button pushed was a horizontal direction
		if (pad.isLeftHeld()) {
			moved = player->pushLeft();
		} else if (pad.isRightHeld()) {
			moved = player->pushRight();
		}

		// Allow horizontal movement even if a vertical button is also
		// pressed, but only if the player hasn't already moved.  This
		// should reduce the frustration of needing super-speedy fingers to
		// let go of one direction and then press the next within a couple
		// of VBLs.
		if (!moved) {
			if (pad.isUpHeld()) {
				moved = player->pushUp();
			} else if (pad.isDownHeld()) {
				moved = player->pushDown();
			}
		}
	}

	if (!moved) {
		if (pad.isBHeld()) {
			player->pokeDown();
		} else if (pad.isAHeld()) {
			player->pokeRight();
		} else if (pad.isXHeld()) {
			player->pokeUp();
		} else if (pad.isYHeld()) {
			player->pokeLeft();
		}
	}
}

bool GameSession::isGravityInverted() const {
	return _remainingGravityTime > 0;
}

void GameSession::decreaseGravityTime() {
	if (!isGravityInverted()) return;

	--_remainingGravityTime;
	_hud.drawGravityCounter(_remainingGravityTime);

	if (_remainingGravityTime == 0) {
		_hud.drawGravityIndicator(false);
	}
}

void GameSession::increaseTime(s32 time) {
	_remainingTime += time;

	if (_remainingTime > STARTING_TIME) _remainingTime = STARTING_TIME;

	// We have to redraw the background and then redraw the black overlay to
	// correctly show the state of the timer bar
	_hud.drawTimerBarBackground();
	_hud.drawTimerBar(_remainingTime);
}

void GameSession::increaseCollectedDiamonds() {
	++_collectedDiamonds;
	_hud.drawDiamondCounters(_level->getDiamondCount(), _collectedDiamonds);
}

void GameSession::increaseLives() {
	++_lives;
	_hud.drawLifeCounter(_lives);
}

void GameSession::decreaseLives() {
	--_lives;
	_hud.drawLifeCounter(_lives);
}

void GameSession::decreaseTime() {
	--_remainingTime;

	_hud.drawTimerBar(_remainingTime);

	if (_remainingTime == 0) {
		getPlayerBlock()->explode();
	}
}

void GameSession::invertGravity() {
	_remainingGravityTime = GRAVITY_INVERSION_TIME;

	SoundPlayer::playGravityInversion();

	_hud.drawGravityCounter(_remainingGravityTime);
	_hud.drawGravityIndicator(true);
}

void GameSession::resetLevelVariables() {
	_collectedDiamonds = 0;
	_remainingTime = STARTING_TIME;
	_remainingGravityTime = 0;
	_isMapAvailable = true;
	_isLevelComplete = false;

	_animationTimer = 0;
	_movementTimer = 0;
	_levelTimer = 0;
}

void GameSession::resetLevel() {
	s32 levelNumber = 1;

	if (_level != NULL) {
		levelNumber = _level->getNumber();
	}

	LevelDefinitionBase* levelDefinition = _levelDefinitions->at(levelNumber - 1);

	startLevel(levelDefinition);
}

void GameSession::startLevel(LevelDefinitionBase* levelDefinition) {
	resetLevelVariables();

	SoundPlayer::stopAll();

	if (_level != NULL) {
		delete _level;
		_level = NULL;
	}

	_level = LevelFactory::createLevel(levelDefinition, this);

	BitmapServer::changeBoulderBmp(levelDefinition->getBoulderType());
	BitmapServer::changeWallBmp(levelDefinition->getWallType());
	BitmapServer::changeSoilBmp(levelDefinition->getSoilType());
	BitmapServer::changeDoorBmp(levelDefinition->getDoorType());

	_hud.drawBackground(_level->getDiamondCount(),
						 _collectedDiamonds,
						 _remainingGravityTime,
						 isGravityInverted(),
						 _lives,
						 _score,
						 _level->getName(),
						 _level->getNumber());
}

void GameSession::endLevel() {
	_isLevelComplete = true;
}
