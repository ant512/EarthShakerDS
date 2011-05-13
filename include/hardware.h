#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <nds.h>

#include "padstate.h"

class Hardware {
public:
	static const PadState& getPadState() {
		return _pad;
	};

	static void updateState() {
		scanKeys();
		_pad.up = (keysDown() & KEY_UP) || (keysHeld() & KEY_UP);
		_pad.down = (keysDown() & KEY_DOWN) || (keysHeld() & KEY_DOWN);
		_pad.left = (keysDown() & KEY_LEFT) || (keysHeld() & KEY_LEFT);
		_pad.right = (keysDown() & KEY_RIGHT) || (keysHeld() & KEY_RIGHT);
		_pad.l = ((keysDown() & KEY_L) || (keysHeld() & KEY_L));
		_pad.r = ((keysDown() & KEY_R) || (keysHeld() & KEY_R));
		_pad.a = ((keysDown() & KEY_A) || (keysHeld() & KEY_A));
		_pad.b = ((keysDown() & KEY_B) || (keysHeld() & KEY_B));
		_pad.x = ((keysDown() & KEY_X) || (keysHeld() & KEY_B));
		_pad.y = ((keysDown() & KEY_Y) || (keysHeld() & KEY_Y));
		_pad.start = ((keysDown() & KEY_START) || (keysHeld() & KEY_START));
		_pad.select = ((keysDown() & KEY_SELECT) || (keysHeld() & KEY_SELECT));
	};

	static void waitForVBlank() {
		swiWaitForVBlank();
	};

private:
	static PadState _pad;

	Hardware();
	~Hardware();
};

#endif
