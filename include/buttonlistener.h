#ifndef _BUTTON_LISTENER_H_
#define _BUTTON_LISTENER_H_

#include <nds.h>

class ButtonBase;

class ButtonListener {
public:

	/**
	 * Constructor.
	 */
	ButtonListener() { };

	/**
	 * Destructor.
	 */
	virtual ~ButtonListener() { };

	/**
	 * Handles any button selections.
	 * @param source The button that raised the event.
	 */
	virtual void handleButtonAction(ButtonBase* source) = 0;
};

#endif
