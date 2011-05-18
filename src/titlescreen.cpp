#include "constants.h"
#include "hardware.h"
#include "soundplayer.h"
#include "titlescreen.h"

TitleScreen::TitleScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, WoopsiArray<LevelDefinition*>* levelDefinitions) : ScreenBase(topGfx, bottomGfx) {
	_timer = 0;
	_chosenLevel = NULL;

	_levelDefinitions = levelDefinitions;

	topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	topGfx->drawBitmap(0, 0, 256, 64, &_logoBmp, 0, 0);

	// Copyrights
	WoopsiGfx::WoopsiString str = "ZX (c) 1990 Michael Batty";
	topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 160, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.setText("DS (c) 2011 Antony Dzeryn");
	topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 168, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	_blockDisplayScreen = new BlockDisplayScreen(bottomGfx);

	_scroller = new Scroller(".... Earth Shaker DS - Featuring anti-gravity, "
							 "4D teleport, forcefields, bubbles, elixirs, "
							 "jumping jelly beans and much much more .... Can "
							 "you survive 32 deadly diamond mines ? .... Well "
							 "- it depends if you are sly enough. But watch out "
							 "you don't bang your head, burn yourself or take "
							 "too long .... Coding (c) 2011 Antony Dzeryn .... "
							 "Original game (c) 1990 Michael Batty .... Written "
							 "for the 2011 GBATemp Homebrew Bounty competition "
							 ".... Many thanks to Michael Batty for permission "
							 "to distribute his original graphics and other "
							 "assets with this remake .... See ant.simianzombie.com "
							 "for other projects ... "
							 );

	// Set up the menu system
	_menu.push_back(new Menu(_topGfx, "Menu"));

	_menu[0]->addOption("Start");
	_menu[0]->addOption("Level Select");

	_menu.push_back(new Menu(_topGfx, "Select Level"));

	for (s32 i = 0; i < _levelDefinitions->size(); ++i) {
		_menu[1]->addOption(_levelDefinitions->at(i)->getName());
	}

	_activeMenuIndex = 0;

	_menu[_activeMenuIndex]->render();
}

TitleScreen::~TitleScreen() {
	delete _scroller;
	delete _blockDisplayScreen;

	for (s32 i = 0; i < _menu.size(); ++i) {
		delete _menu[i];
	}
}

void TitleScreen::iterate() {

	const PadState& pad = Hardware::getPadState();

	_scroller->render(184, _topGfx);
	_blockDisplayScreen->iterate();

	++_timer;

	if (_timer < MOVEMENT_TIME) return;

	_timer = 0;

	_menu[_activeMenuIndex]->iterate();

	if (pad.a || pad.start) {
		switch (_activeMenuIndex) {
			case 0:

				// Main menu
				switch (_menu[0]->getSelectedIndex()) {
					case 0:

						// Start at beginning of game
						_chosenLevel = _levelDefinitions->at(0);
						break;

					case 1:

						// Switch to level select menu
						_activeMenuIndex = 1;
						_menu[1]->setSelectedIndex(0);
						_menu[1]->render();

						// Wait until the button is released before continuing
						// so that we don't select the top item in the next
						// menu automatically
						while (pad.a || pad.start) {
							Hardware::waitForVBlank();
						}

						break;
				}

				break;
			case 1:

				// Level select
				_chosenLevel = _levelDefinitions->at(_menu[1]->getSelectedIndex());
				SoundPlayer::stopTitleTheme();
				SoundPlayer::playBubbleExplode();
				break;
		}
	} else if (pad.b) {
		switch (_activeMenuIndex) {
			case 0:
				break;
			case 1:
				// Switch to main menu
				_activeMenuIndex = 0;
				_menu[0]->setSelectedIndex(0);
				_menu[0]->render();

				// Wait until the button is released before continuing
				// so that we don't select the top item in the next
				// menu automatically
				while (pad.b) {
					Hardware::waitForVBlank();
				}

				break;
		}
	}
}

bool TitleScreen::isRunning() const {
	return _chosenLevel == NULL;
}

LevelDefinition* TitleScreen::getChosenLevel() const {
	return _chosenLevel;
}
