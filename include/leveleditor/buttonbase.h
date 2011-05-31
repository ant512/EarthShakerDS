#ifndef _BUTTON_BASE_H_
#define _BUTTON_BASE_H_

#include <graphics.h>

#include "soundplayer.h"

class ButtonBase {
public:
	ButtonBase(s32 x, s32 y, s32 width, s32 height, s32 id) {
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		_id = id;
		_clicked = false;
	};

	virtual ~ButtonBase() { };

	virtual void render(WoopsiGfx::Graphics* gfx) = 0;

	bool checkCollision(s32 x, s32 y) {
		return ((x >= _x) &&
				(y >= _y) &&
				(x < _x + _width) &&
				(y < _y + _height));
	};

	s32 getId() const { return _id; };

	void click() {
		SoundPlayer::playSoilDig();
		_clicked = true;
	};

	void release() {
		_clicked = false;
	};

protected:
	s32 _x;
	s32 _y;
	s32 _width;
	s32 _height;
	s32 _id;
	bool _clicked;
};

#endif
