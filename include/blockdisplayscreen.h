#ifndef _BLOCK_DISPLAY_SCREEN_H_
#define _BLOCK_DISPLAY_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "blockbase.h"
#include "gamefont.h"
#include "screenbase.h"
#include "spectrumcolours.h"

class BlockDisplayScreen : public ScreenBase {
public:
	BlockDisplayScreen(WoopsiGfx::Graphics* bottomGfx);

	~BlockDisplayScreen();

	void iterate(PadState pad);

	bool isRunning() const;

private:
	s32 _timer;
	s32 _blockX;
	s32 _blockY;
	GameFont _font;
	BlockBase* _block;
};

#endif
