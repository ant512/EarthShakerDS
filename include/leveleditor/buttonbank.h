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

	/**
	 * Constructor.
	 * @param listener Object that will react to button presses.
	 * @param gfx Graphics object to draw to.
	 */
	ButtonBank(ButtonListener* listener, WoopsiGfx::Graphics* gfx) {
		_listener = listener;
		_gfx = gfx;
		_clickedButton = NULL;
	};

	/**
	 * Destructor.
	 */
	~ButtonBank() {
		for (s32 i = 0; i < _buttons.size(); ++i) {
			delete _buttons[i];
		}
	};

	/**
	 * Draws the button bank.
	 */
	void render() {
		for (s32 i = 0; i < _buttons.size(); ++i) {
			_buttons[i]->render(_gfx);
		}
	};

	/**
	 * Add a button to the bank.
	 * @param button The button to add.
	 */
	void addButton(ButtonBase* button) {
		_buttons.push_back(button);
	};

	/**
	 * Runs all button bank logic.  Reacts to stylus presses.
	 */
	void iterate() {
		const StylusState& stylus = Hardware::getStylusState();

		if (stylus.newPress) {
			click(stylus.x, stylus.y);
		} else if (stylus.released) {
			release();
		}
	};

	/**
	 * Click the lowest button in the button stack at the specified
	 * co-ordinates.
	 * @param x X co-ordinate to click.
	 * @param y Y co-ordinate to click.
	 */
	void click(s32 x, s32 y) {
		for (s32 i = 0; i < _buttons.size(); ++i) {
			if (_buttons[i]->checkCollision(x, y)) {
				_clickedButton = _buttons[i];
				_clickedButton->click();
				_clickedButton->render(_gfx);
				_listener->handleButtonAction(_buttons[i]);
				return;
			}
		}
	};

	/**
	 * Release the clicked button.
	 */
	void release() {
		if(_clickedButton != NULL) {
			_clickedButton->release();
			_clickedButton->render(_gfx);
		}

		_clickedButton = NULL;
	};

private:
	ButtonListener* _listener;			/**< Object that listens for button clicks. */
	WoopsiArray<ButtonBase*> _buttons;	/**< List of buttons. */
	ButtonBase* _clickedButton;			/**< Pointer to the clicked button. */
	WoopsiGfx::Graphics* _gfx;			/**< Graphics object to draw to. */
};

#endif
