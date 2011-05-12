#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "blockdisplayscreen.h"
#include "gamefont.h"
#include "leveldefinition.h"
#include "logobmp.h"
#include "screenbase.h"
#include "scroller.h"
#include "spectrumcolours.h"

class TitleScreen : public ScreenBase {
public:
	TitleScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, WoopsiArray<LevelDefinition*>* levelDefinitions);

	~TitleScreen();

	void iterate(PadState pad);

	bool isRunning() const;

	LevelDefinition* getChosenLevel() const;

private:
	s32 _timer;
	GameFont _font;
	Scroller* _scroller;
	LogoBmp _logoBmp;
	WoopsiArray<LevelDefinition*>* _levelDefinitions;
	s32 _selectedLevelIndex;
	LevelDefinition* _chosenLevel;
	BlockDisplayScreen* _blockDisplayScreen;

	void drawLevelNames();

};

#endif
