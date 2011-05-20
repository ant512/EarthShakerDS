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

	_blockSlideshowScreen = new BlockSlideshowScreen(bottomGfx);

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
							 "for other projects .... Earth Shaker DS was written "
							 "using WoopsiGfx, a 2D graphics library that includes "
							 "features such as DMA acceleration, a set of 2D "
							 "drawing routines, animation, UTF-8 strings and "
							 "fonts for rendering text .... "
							 );

	// Set up the menu system
	_menuSystem = new MenuSystem(this, _topGfx, "Menu", MENU_MAIN);
	
	// Set up root menu
	Menu* rootMenu = _menuSystem->getRootMenu();
	rootMenu->addOption("Start");

	// Set up level select
	Menu* levelSelect = new Menu("Level Select", MENU_LEVEL_SELECT);
	rootMenu->addSubMenu(levelSelect);

	for (s32 i = 0; i < _levelDefinitions->size(); ++i) {
		levelSelect->addOption(_levelDefinitions->at(i)->getName());
	}

	// Set up sound test

	Menu* soundTest = new Menu("Sound Test", MENU_SOUND_TEST);
	rootMenu->addSubMenu(soundTest);

	soundTest->addOption("Barrier Explode");
	soundTest->addOption("Barrier Push");
	soundTest->addOption("Bean Collect");
	soundTest->addOption("Block Fall");
	soundTest->addOption("Block Land");
	soundTest->addOption("Boulder Explode");
	soundTest->addOption("Bubble Explode");
	soundTest->addOption("Diamond Collect");
	soundTest->addOption("Door Open");
	soundTest->addOption("Extra Life Collect");
	soundTest->addOption("Gravity Inversion");
	soundTest->addOption("Level Complete");
	soundTest->addOption("Pause");
	soundTest->addOption("Player Explode");
	soundTest->addOption("Soil Dig");
	soundTest->addOption("Suicide");
	soundTest->addOption("Teleport Collect");
	soundTest->addOption("Time");

	_menuSystem->render();

	SoundPlayer::playTitleTheme();
}

TitleScreen::~TitleScreen() {
	delete _scroller;
	delete _blockSlideshowScreen;
	delete _menuSystem;
}

void TitleScreen::iterate() {
	_scroller->render(184, _topGfx);
	_blockSlideshowScreen->iterate();
	_menuSystem->iterate();
}

void TitleScreen::handleMenuAction(Menu* source) {
	switch (source->getId()) {
		case MENU_MAIN:

			// Start at beginning of game
			_chosenLevel = _levelDefinitions->at(0);
			SoundPlayer::stopTitleTheme();
			SoundPlayer::playBubbleExplode();
			break;

		case MENU_LEVEL_SELECT:
			_chosenLevel = _levelDefinitions->at(source->getSelectedIndex());
			SoundPlayer::stopTitleTheme();
			SoundPlayer::playBubbleExplode();
			break;

		case MENU_SOUND_TEST:
			soundTest(source->getSelectedIndex());
	}
}

void TitleScreen::soundTest(s32 sound) {
	switch (sound) {
		case 0:
			SoundPlayer::playBarrierExplode();
			break;
		case 1:
			SoundPlayer::playBarrierPush();
			break;
		case 2:
			SoundPlayer::playBeanCollect();
			break;
		case 3:
			SoundPlayer::playBlockFall();
			break;
		case 4:
			SoundPlayer::playBlockLand();
			break;
		case 5:
			SoundPlayer::playBoulderExplode();
			break;
		case 6:
			SoundPlayer::playBubbleExplode();
			break;
		case 7:
			SoundPlayer::playDiamondCollect();
			break;
		case 8:
			SoundPlayer::playDoorOpen();
			break;
		case 9:
			SoundPlayer::playExtraLifeCollect();
			break;
		case 10:
			SoundPlayer::playGravityInversion();
			break;
		case 11:
			SoundPlayer::playLevelComplete();
			break;
		case 12:
			SoundPlayer::playPause();
			break;
		case 13:
			SoundPlayer::playPlayerExplode();
			break;
		case 14:
			SoundPlayer::playSoilDig();
			break;
		case 15:
			SoundPlayer::playSuicide();
			break;
		case 16:
			SoundPlayer::playTeleportCollect();
			break;
		case 17:
			SoundPlayer::playTime();
			break;
	}
}

bool TitleScreen::isRunning() const {
	return _chosenLevel == NULL;
}

LevelDefinition* TitleScreen::getChosenLevel() const {
	return _chosenLevel;
}
