#ifndef _BUTTON_BANK_H_
#define _BUTTON_BANK_H_

#include <graphics.h>
#include <woopsiarray.h>

#include "buttonbase.h"
#include "buttonlistener.h"
#include "hardware.h"
#include "padstate.h"

/**
 * Contains a list of buttons and raises events when one is clicked.
 */
class ButtonBank {
public:
	ButtonBank(ButtonListener* listener, WoopsiGfx::Graphics* gfx) {
		_listener = listener;
		_gfx = gfx;
		_clickedButton = NULL;
	};

	~ButtonBank() {
		for (s32 i = 0; i < _buttons.size(); ++i) {
			delete _buttons[i];
		}
	};

	void render() {
		for (s32 i = 0; i < _buttons.size(); ++i) {
			_buttons[i]->render(_gfx);
		}
	};

	void addButton(ButtonBase* button) {
		_buttons.push_back(button);
	};

	void iterate() {
		const StylusState& stylus = Hardware::getStylusState();

		if (stylus.newPress) {
			click(stylus.x, stylus.y);
		} else if (stylus.released) {
			release();
		}
	};

	void click(s32 x, s32 y) {
		for (s32 i = 0; i < _buttons.size(); ++i) {
			if (_buttons[i]->checkCollision(x, y)) {
				_clickedButton = _buttons[i];
				_clickedButton->click();
				_clickedButton->render(_gfx);
				_listener->handleButtonAction(_buttons[i]);
			}
		}
	};

	void release() {
		if(_clickedButton != NULL) {
			_clickedButton->release();
			_clickedButton->render(_gfx);
		}

		_clickedButton = NULL;
	};

private:
	ButtonListener* _listener;
	WoopsiArray<ButtonBase*> _buttons;
	ButtonBase* _clickedButton;
	WoopsiGfx::Graphics* _gfx;
};

#endif
