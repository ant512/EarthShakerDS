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

Game::Game(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) : ScreenBase(topGfx, bottomGfx) {
	_score = 0;
	_lives = STARTING_LIVES;
	_isOddIteration = true;
	_level = NULL;
	_gameOverScreen = NULL;
	_gameCompleteScreen = NULL;
	_titleScreen = NULL;
	_state = GAME_STATE_STARTUP;
	_transition = new GateTransition(topGfx, bottomGfx);

	_levelDefinitions.push_back(new Level1());
	_levelDefinitions.push_back(new Level2());
	_levelDefinitions.push_back(new Level3());
	_levelDefinitions.push_back(new Level4());
	_levelDefinitions.push_back(new Level5());
	_levelDefinitions.push_back(new Level6());
	_levelDefinitions.push_back(new Level7());
	_levelDefinitions.push_back(new Level8());
}

Game::~Game() {
	delete _transition;

	for (s32 i = 0; i < _levelDefinitions.size(); ++i) {
		delete _levelDefinitions[i];
	}
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

LevelBase* Game::getLevel() const {
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
	drawScore();
}

void Game::drawScore() {
	WoopsiGfx::WoopsiString str;
	str.format("%06d", _score);

	s32 scoreWidth = _font.getStringWidth(str);
	s32 scoreHeight = _font.getHeight();
	s32 scoreX = SCREEN_WIDTH - scoreWidth;
	s32 scoreY = SCREEN_HEIGHT - scoreHeight - 1;

	_topGfx->drawFilledRect(scoreX, scoreY, scoreWidth, scoreHeight, COLOUR_BLACK);
	_topGfx->drawText(scoreX, scoreY, &_font, str, 0, str.getLength(), woopsiRGB(31, 31, 31));
}

void Game::drawLifeCounter() {

	// Prevent lives less than 0 being printed
	s32 lives = _lives > -1 ? _lives : 0;

	WoopsiGfx::WoopsiString str;
	str.format("%01d", lives);

	s32 width = _font.getStringWidth(str);
	s32 height = _font.getHeight();
	s32 x = 96;
	s32 y = SCREEN_HEIGHT - height - 1;

	_topGfx->drawFilledRect(x, y, width, height, COLOUR_BLACK);
	_topGfx->drawText(x, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void Game::drawGravityCounter() {
	WoopsiGfx::WoopsiString str;
	str.format("%02d", _remainingGravityTime);

	s32 width = _font.getStringWidth(str);
	s32 height = _font.getHeight();
	s32 x = 136;
	s32 y = SCREEN_HEIGHT - height - 1;

	_topGfx->drawFilledRect(x, y, width, height, COLOUR_BLACK);
	_topGfx->drawText(x, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void Game::drawGravityIndicator() {
	WoopsiGfx::WoopsiString str;
	str.setText(isGravityInverted() ? "%%" : "&");

	s32 width = _font.getStringWidth(str);
	s32 height = _font.getHeight();
	s32 x = 120;
	s32 y = SCREEN_HEIGHT - height - 1;

	_topGfx->drawFilledRect(x, y, width, height, COLOUR_BLACK);
	_topGfx->drawText(x, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
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

void Game::iterate(PadState pad) {

	switch (_state) {

		case GAME_STATE_NOT_RUNNING:
			return;

		case GAME_STATE_STARTUP:
			_titleScreen = new TitleScreen(_topGfx, _bottomGfx, &_levelDefinitions);
			_state = GAME_STATE_TITLE_SCREEN;

		case GAME_STATE_TITLE_SCREEN:

			_titleScreen->iterate(pad);

			if (!_titleScreen->isRunning()) {
				_transition->reset();
				_state = GAME_STATE_TITLE_SCREEN_TRANSITION;
			}

			break;

		case GAME_STATE_TITLE_SCREEN_TRANSITION:

			_transition->iterate();

			if (!_transition->isRunning()) {
				LevelDefinition* chosenLevel = _titleScreen->getChosenLevel();

				delete _titleScreen;
				_titleScreen = NULL;

				startLevel(chosenLevel);
			}

			break;

		case GAME_STATE_GAMEPLAY:
			animate();
			timer();
			move(pad);

			if (pad.start) {
				_state = GAME_STATE_GAME_PAUSING;
			}

			break;

		case GAME_STATE_PLAYER_DEAD:

			// Handle the situation in which the player has been killed
			decreaseLives();

			if (_lives > 0) {
				resetLevel();
			} else {
				_state = GAME_STATE_GAME_OVER;
			}

			break;

		case GAME_STATE_PLAYER_SUICIDE:

			// Handle the situation in which the player has committed suicide

			_remainingTime -= 2;

			drawTimerBar();

			if (_remainingTime < 1) {
				killPlayer();
			}

			break;

		case GAME_STATE_LEVEL_COMPLETE:

			// Handle the situation in which the player has finished the level
			_remainingTime -= 2;
			addScore(2);		// One point per second

			drawTimerBar();

			if (_remainingTime < 1) {
				_transition->reset();
				_state = GAME_STATE_LEVEL_TRANSITION;
			}

			break;

		case GAME_STATE_LEVEL_TRANSITION:
			
			_transition->iterate();

			if (!_transition->isRunning()) {

				if (_level->getNumber() < _levelDefinitions.size() - 1) {
					startLevel(_levelDefinitions[_level->getNumber()]);
				} else {
					_state = GAME_STATE_GAME_COMPLETE;
				}
			}

			break;

		case GAME_STATE_GAME_OVER:

			_transition->reset();
			_state = GAME_STATE_GAME_OVER_TRANSITION;

		case GAME_STATE_GAME_OVER_TRANSITION:

			_transition->iterate();

			if (!_transition->isRunning()) {

				// Game has ended; set up a new game over screen and kill the level
				_gameOverScreen = new GameOverScreen(_topGfx, _bottomGfx, _score, _level->getNumber());
				_state = GAME_STATE_GAME_OVER_SCREEN;

				delete _level;
				_level = NULL;
			}

			break;
		
		case GAME_STATE_GAME_OVER_SCREEN:

			// Run the game over screen
			_gameOverScreen->iterate(pad);

			if (!_gameOverScreen->isRunning()) {
				delete _gameOverScreen;
				_gameOverScreen = NULL;

				_state = GAME_STATE_STARTUP;
			}

			break;

		case GAME_STATE_GAME_COMPLETE:

			_transition->reset();
			_state = GAME_STATE_GAME_COMPLETE_TRANSITION;

		case GAME_STATE_GAME_COMPLETE_TRANSITION:

			_transition->iterate();

			if (!_transition->isRunning()) {

				// Game is complete; set up a new game complete screen and kill the level
				_gameCompleteScreen = new GameCompleteScreen(_topGfx, _bottomGfx, _score);
				_state = GAME_STATE_GAME_COMPLETE_SCREEN;

				delete _level;
				_level = NULL;
			}

			break;

		case GAME_STATE_GAME_COMPLETE_SCREEN:

			// Run the game complete screen
			_gameCompleteScreen->iterate(pad);

			if (!_gameCompleteScreen->isRunning()) {
				delete _gameCompleteScreen;
				_gameCompleteScreen = NULL;

				_state = GAME_STATE_STARTUP;
			}

			break;

		case GAME_STATE_GAME_PAUSING:
			_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 16, COLOUR_BLACK);
			_topGfx->drawText(104, 84, &_font, "Paused", 0, 6, COLOUR_YELLOW);

			if (!pad.start) {
				_state = GAME_STATE_GAME_PAUSED;
				SoundPlayer::playPause();
			}

			break;

		case GAME_STATE_GAME_PAUSED:
			
			if (pad.start) {
				_state = GAME_STATE_GAME_UNPAUSING;
			}

			break;
		
		case GAME_STATE_GAME_UNPAUSING:

			if (!pad.start) {
				_state = GAME_STATE_GAMEPLAY;
				render();
			}

			break;
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

void Game::move(PadState pad) {
	_movementTimer++;

	if (_movementTimer == MOVEMENT_TIME) {
		_movementTimer = 0;

		// Suicide check
		if (pad.r && pad.l) {
			_state = GAME_STATE_PLAYER_SUICIDE;
			return;
		}

		if (pad.up) {
			getPlayerBlock()->pushUp();
		} else if (pad.down) {
			getPlayerBlock()->pushDown();
		} else if (pad.left) {
			getPlayerBlock()->pushLeft();
		} else if (pad.right) {
			getPlayerBlock()->pushRight();
		}

		_level->iterate(_remainingGravityTime > 0);
		_isOddIteration = !_isOddIteration;

		if (_remainingGravityTime > 0) {
			--_remainingGravityTime;
			drawGravityCounter();

			if (_remainingGravityTime == 0) {
				drawGravityIndicator();
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
	drawTimerBarBackground();
	drawTimerBar();
}

void Game::increaseCollectedDiamonds() {
	++_collectedDiamonds;

	drawDiamondCounters();
}

void Game::increaseLives() {
	++_lives;

	drawLifeCounter();
}

void Game::decreaseLives() {
	--_lives;

	drawLifeCounter();
}

void Game::killPlayer() {
	_state = GAME_STATE_PLAYER_DEAD;
}

void Game::drawDiamondCounters() {
	WoopsiGfx::WoopsiString str;

	// Erase region for counters
	s32 height = _font.getHeight();
	s32 y = SCREEN_HEIGHT - height - 1;

	str.format("%02d", _level->getDiamondCount());
	_topGfx->drawFilledRect(40, y, 16, height, COLOUR_BLACK);
	_topGfx->drawText(40, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.format("%02d", _collectedDiamonds);
	_topGfx->drawFilledRect(64, y, 16, height, COLOUR_BLACK);
	_topGfx->drawText(64, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void Game::decreaseTime() {
	--_remainingTime;

	drawTimerBar();

	if (_remainingTime == 0) {
		killPlayer();
	}
}

void Game::drawTimerBarBackground() {
	s32 barY = 178;
	s32 barWidth = SCREEN_WIDTH / 8;
	s32 barHeight = 4;

	_topGfx->drawFilledRect(0, barY, SCREEN_WIDTH, barHeight, COLOUR_BLUE_DARK);
	_topGfx->drawFilledRect(barWidth, barY, SCREEN_WIDTH, barHeight, COLOUR_BLUE);
	_topGfx->drawFilledRect(barWidth * 2, barY, SCREEN_WIDTH, barHeight, COLOUR_RED);
	_topGfx->drawFilledRect(barWidth * 3, barY, SCREEN_WIDTH, barHeight, COLOUR_MAGENTA);
	_topGfx->drawFilledRect(barWidth * 4, barY, SCREEN_WIDTH, barHeight, COLOUR_GREEN);
	_topGfx->drawFilledRect(barWidth * 5, barY, SCREEN_WIDTH, barHeight, COLOUR_CYAN);
	_topGfx->drawFilledRect(barWidth * 6, barY, SCREEN_WIDTH, barHeight, COLOUR_YELLOW);
	_topGfx->drawFilledRect(barWidth * 7, barY, SCREEN_WIDTH, barHeight, COLOUR_WHITE);
}

void Game::drawLevelName() {
	s32 nameWidth = _font.getStringWidth(_level->getName());
	s32 nameHeight = _font.getHeight();
	s32 nameX = (SCREEN_WIDTH - nameWidth) / 2;
	s32 nameY = (SCREEN_HEIGHT - nameHeight) / 2;

	// Erase region under name
	_bottomGfx->drawFilledRect(0, nameY, SCREEN_WIDTH, nameHeight, COLOUR_BLACK);

	// Draw name
	_bottomGfx->drawText(nameX, nameY, &_font, _level->getName(), 0, _level->getName().getLength(), COLOUR_WHITE);
}

void Game::drawHUD() {

	// Wipe everything
	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	_bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	drawTimerBarBackground();
	drawLevelName();

	// Logo
	_bottomGfx->drawBitmap(0, 0, 256, 64, &_logoBmp, 0, 0);

	// Copyrights
	WoopsiGfx::WoopsiString	str = "ZX (c) 1990 Michael Batty";
	_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 160, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.setText("DS (c) 2011 Antony Dzeryn");
	_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 168, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	// Erase region for counters
	s32 counterHeight = _font.getHeight();
	s32 counterY = SCREEN_HEIGHT - counterHeight - 1;

	_topGfx->drawFilledRect(0, counterY, SCREEN_WIDTH, counterHeight, COLOUR_BLACK);

	// Level display
	str.setText("L");

	// Here we abandon calculated text co-ordinates and hard-code everything
	// with magic numbers, because it's quicker for both the computer and the
	// programmer to execute
	_topGfx->drawText(0, counterY, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	str.format("%02d", _level->getNumber());
	_topGfx->drawText(8, counterY, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	// Diamond
	str.setText("*");
	_topGfx->drawText(32, counterY, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	// Diamonds
	str.setText(":");
	_topGfx->drawText(56, counterY, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	// Heart
	str.setText("+");
	_topGfx->drawText(88, counterY, &_font, str, 0, str.getLength(), COLOUR_RED);

	// Gravity
	str.setText("$");
	_topGfx->drawText(112, counterY, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	// "SCORE:"
	str.setText("S");
	_topGfx->drawText(160, counterY, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.setText("C");
	_topGfx->drawText(168, counterY, &_font, str, 0, str.getLength(), COLOUR_YELLOW);

	str.setText("O");
	_topGfx->drawText(176, counterY, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	str.setText("R");
	_topGfx->drawText(184, counterY, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	str.setText("E");
	_topGfx->drawText(192, counterY, &_font, str, 0, str.getLength(), COLOUR_MAGENTA);

	str.setText(":");
	_topGfx->drawText(200, counterY, &_font, str, 0, str.getLength(), COLOUR_RED);
}

void Game::drawTimerBar() {

	// Rather than draw a bar representing the amount of time left to elapse,
	// we overwrite the existing graphics from right to left with a black rect.
	// This gives the illusion of shortening the remaining time bar with much
	// less effort.

	s32 barY = 178;
	s32 width = STARTING_TIME - _remainingTime;
	s32 barX = SCREEN_WIDTH - width;

	// Draw new bar graphic
	_topGfx->drawFilledRect(barX, barY, width, 4, COLOUR_BLACK);
}

void Game::invertGravity() {
	_remainingGravityTime = GRAVITY_INVERSION_TIME;

	drawGravityCounter();
	drawGravityIndicator();
}

void Game::resetLevel() {
	_state = GAME_STATE_GAMEPLAY;
	_collectedDiamonds = 0;
	_remainingTime = STARTING_TIME;
	_remainingGravityTime = 0;

	_animationTimer = 0;
	_movementTimer = 0;
	_levelTimer = 0;

	s32 levelNumber = 0;

	if (_level != NULL) {
		levelNumber = _level->getNumber();
		delete _level;
	}

	_level = LevelFactory::createLevel(_levelDefinitions[levelNumber - 1], this);

	drawHUD();
	drawDiamondCounters();
	drawScore();
	drawLifeCounter();
	drawGravityCounter();
	drawGravityIndicator();
}


void Game::startLevel(LevelDefinition* levelDefinition) {
	_state = GAME_STATE_GAMEPLAY;
	_collectedDiamonds = 0;
	_remainingTime = STARTING_TIME;
	_remainingGravityTime = 0;

	_animationTimer = 0;
	_movementTimer = 0;
	_levelTimer = 0;

	if (_level != NULL) {
		delete _level;
	}

	_level = LevelFactory::createLevel(levelDefinition, this);

	drawHUD();
	drawDiamondCounters();
	drawScore();
	drawLifeCounter();
	drawGravityCounter();
	drawGravityIndicator();
}

void Game::endLevel() {
	_state = GAME_STATE_LEVEL_COMPLETE;
}
