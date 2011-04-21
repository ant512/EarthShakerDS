#include "titlescreen.h"
#include "constants.h"

TitleScreen::TitleScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, WoopsiArray<LevelDefinition*>* levelDefinitions) : ScreenBase(topGfx, bottomGfx) {
	_timer = 0;
	_selectedLevelIndex = 0;
	_chosenLevel = NULL;

	_levelDefinitions = levelDefinitions;

	topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	topGfx->drawBitmap(0, 0, 256, 64, &_logoBmp, 0, 0);

	// Level select
	WoopsiGfx::WoopsiString	str = "Select Level";
	topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 72, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	// Copyrights
	str.setText("ZX (c) 1990 Michael Batty");
	topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 160, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.setText("DS (c) 2011 Antony Dzeryn");
	topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 168, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	// High scores
	str.setText("High Scores");
	bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 16, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.setText("020000  M. Batty");
	bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 32, &_font, str, 0, str.getLength(), COLOUR_YELLOW);

	str.setText("016000  M. Batty");
	bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 48, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	str.setText("012000  M. Batty");
	bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 64, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	str.setText("008000  M. Batty");
	bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 80, &_font, str, 0, str.getLength(), COLOUR_MAGENTA);

	str.setText("004000  M. Batty");
	bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 96, &_font, str, 0, str.getLength(), COLOUR_RED);

	_scroller = new Scroller(".... Earth Shaker DS - Featuring anti-gravity, "
							 "4D teleport, forcefields, bubbles, elixirs, "
							 "jumping jelly beans and much much more .... Can "
							 "you survive 32 deadly diamond mines ? .... Well "
							 "- it depends if you are sly enough. But watch out "
							 "you don't bang your head, burn yourself or take "
							 "too long .... Coding (c) 2011 Antony Dzeryn .... "
							 "Artwork (c) 1990 Michael Batty ....");

	drawLevelNames();
}

TitleScreen::~TitleScreen() {
	delete _scroller;
}

void TitleScreen::iterate(PadState pad) {
	++_timer;

	_scroller->render(184, _topGfx);

	if (_timer < MOVEMENT_TIME) return;

	_timer = 0;

	if (pad.up) {
		if (_selectedLevelIndex > 0) {
			--_selectedLevelIndex;
			drawLevelNames();
		}
	} else if (pad.down) {
		if (_selectedLevelIndex < _levelDefinitions->size() - 1) {
			++_selectedLevelIndex;
			drawLevelNames();
		}
	} else if (pad.a) {
		_chosenLevel = _levelDefinitions->at(_selectedLevelIndex);
	}
}

bool TitleScreen::isRunning() const {
	return _chosenLevel == NULL;
}

LevelDefinition* TitleScreen::getChosenLevel() const {
	return _chosenLevel;
}

void TitleScreen::drawLevelNames() {

	WoopsiGfx::WoopsiString str;
	s32 y = 88;
	SpectrumColour colour = COLOUR_WHITE;

	s32 firstOption = _selectedLevelIndex - 3;
	s32 lastOption = _selectedLevelIndex + 3;

	_topGfx->drawFilledRect(0, y, SCREEN_WIDTH, _font.getHeight() * 7, COLOUR_BLACK);

	for (s32 i = firstOption; i <= lastOption; ++i) {
		if ((i >= 0) && (i < _levelDefinitions->size())) {
			if (i == _selectedLevelIndex) {
				colour = COLOUR_YELLOW;
			} else {
				colour = COLOUR_CYAN;
			}

			str = _levelDefinitions->at(i)->getName();
			_topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, y, &_font, str, 0, str.getLength(), colour);
		}

		y += _font.getHeight();
	}
}
