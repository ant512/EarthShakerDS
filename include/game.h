#ifndef _GAME_H_
#define _GAME_H_

#include <graphics.h>

#include "levelbase.h"
#include "blockbase.h"
#include "playerblock.h"
#include "newtopaz.h"

class Game {
public:
	Game(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx);

	~Game();

	void render();

	LevelBase* getLevel() const;
	PlayerBlock* getPlayerBlock() const;

	void iterate();

	bool isGravityInverted() const;
	void flipGravity();

	s32 getScore() const;
	s32 getLevelTime() const;

	void addScore(s32 score);

	void setUpHeld(bool upHeld);
	void setDownHeld(bool downHeld);
	void setLeftHeld(bool leftHeld);
	void setRightHeld(bool rightHeld);

private:
	LevelBase* _level;
	PlayerBlock* _playerBlock;
	bool _isGravityInverted;
	s32 _score;
	s32 _levelTime;
	s32 _lives;
	WoopsiGfx::Graphics* _topGfx;
	WoopsiGfx::Graphics* _bottomGfx;
	NewTopaz _font;
	s32 _animationTimer;
	s32 _movementTimer;

	bool _upHeld;
	bool _downHeld;
	bool _leftHeld;
	bool _rightHeld;

	LevelBase* createLevel(u8* data, s32 width, s32 height, s32 number, const WoopsiGfx::WoopsiString& name);

	void decreaseTime();
	void drawTimerBar();
	void animate();
	void move();
};

#endif
