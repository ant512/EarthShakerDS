#ifndef _BUTTON_BANK_H_
#define _BUTTON_BANK_H_

#include <graphics.h>
#include <woopsiarray.h>

#include "buttonbase.h"
#include "buttonlistener.h"

class ButtonBank {
public:
	ButtonBank(ButtonListener* listener) {
		_listener = listener;
	};

	~ButtonBank() {
		for (s32 i = 0; i < _buttons.size(); ++i) {
			delete _buttons[i];
		}
	};

	void render(WoopsiGfx::Graphics* gfx) {
		for (s32 i = 0; i < _buttons.size(); ++i) {
			_buttons[i]->render(gfx);
		}
	};

	void addButton(ButtonBase* button) {
		_buttons.push_back(button);
	};

	void click(s32 x, s32 y) {
		for (s32 i = 0; i < _buttons.size(); ++i) {
			if (_buttons[i]->checkCollision(x, y)) {
				_listener->handleButtonAction(_buttons[i]);
			}
		}
	};

private:
	ButtonListener* _listener;
	WoopsiArray<ButtonBase*> _buttons;
};

#endif
