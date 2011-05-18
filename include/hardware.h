#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <nds.h>

#include "framebuffer.h"
#include "graphics.h"
#include "padstate.h"

class Hardware {
public:

	static void init();

	static void shutdown();

	static inline WoopsiGfx::Graphics* getTopGfx() {
		return _topGfx;
	};

	static inline WoopsiGfx::Graphics* getBottomGfx() {
		return _bottomGfx;
	};

	static inline const PadState& getPadState() {
		return _pad;
	};

	static void updateState();

	static void waitForVBlank();

private:
	static PadState _pad;
	static WoopsiGfx::FrameBuffer* _topBuffer;
	static WoopsiGfx::FrameBuffer* _bottomBuffer;
	static WoopsiGfx::Graphics* _topGfx;
	static WoopsiGfx::Graphics* _bottomGfx;

	Hardware() { };
	~Hardware() { };
};

#endif
