#include "constants.h"
#include "hardware.h"
#include "leveleditor.h"
#include "soundplayer.h"
#include "titlescreen.h"
#include "leveldefinitions.h"

TitleScreen::TitleScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) : ScreenBase(topGfx, bottomGfx) {

	_timer = 0;
	_chosenLevel = NULL;
	_menuSystem = NULL;

	renderBackground();

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
							 "assets with this remake .... Thanks to another "
							 "world and polomint for their testing and feedback "
							 ".... See simianzombie.com for other projects "
							 ".... Earth Shaker DS was written using WoopsiGfx, "
							 "a 2D graphics library that includes features such "
							 "as DMA acceleration, a set of 2D drawing routines, "
							 "animation, UTF-8 strings and fonts for rendering "
							 "text .... "
							 );

	prepareMenu();

	SoundPlayer::playTitleTheme();
}

TitleScreen::~TitleScreen() {
	delete _scroller;
	delete _blockSlideshowScreen;
	delete _menuSystem;
}

void TitleScreen::prepareMenu() {
	
	if (_menuSystem != NULL) {
		delete _menuSystem;
	}
	
	// Set up the menu system
	_menuSystem = new MenuSystem(this, _topGfx, "Menu", MENU_MAIN, 72, SCREEN_WIDTH, 16);
	
	// Set up root menu
	Menu* rootMenu = _menuSystem->getRootMenu();
	rootMenu->addOption("Start Game", 0);
	
	// Set up level select
	Menu* levelSelect = new Menu("Level Select", MENU_LEVEL_SELECT);
	rootMenu->addSubMenu(levelSelect);
	
	for (s32 i = 0; i < STANDARD_LEVEL_COUNT; ++i) {
		levelSelect->addOption(LevelDefinitions::getDefinitions().at(i)->getName(), i);
	}
	
	// Set up custom level select
	Menu *customLevelSelect = new Menu("Custom Level", MENU_CUSTOM_LEVEL);
	rootMenu->addSubMenu(customLevelSelect);
	
	for (s32 i = STANDARD_LEVEL_COUNT; i < LevelDefinitions::getDefinitions().size(); ++i) {
		customLevelSelect->addOption(LevelDefinitions::getDefinitions().at(i)->getName(), i);
	}
	
	// Set up sound test
	
	Menu* soundTest = new Menu("Sound Test", MENU_SOUND_TEST);
	rootMenu->addSubMenu(soundTest);
	
	soundTest->addOption("Barrier Explode", 0);
	soundTest->addOption("Barrier Push", 1);
	soundTest->addOption("Bean Collect", 2);
	soundTest->addOption("Block Fall", 3);
	soundTest->addOption("Block Land", 4);
	soundTest->addOption("Boulder Explode", 5);
	soundTest->addOption("Bubble Explode", 6);
	soundTest->addOption("Diamond Collect", 7);
	soundTest->addOption("Door Open", 8);
	soundTest->addOption("Extra Life Collect", 9);
	soundTest->addOption("Gravity Inversion", 10);
	soundTest->addOption("Level Complete", 11);
	soundTest->addOption("Pause", 12);
	soundTest->addOption("Player Explode", 13);
	soundTest->addOption("Soil Dig", 14);
	soundTest->addOption("Soil Poke", 15);
	soundTest->addOption("Suicide", 16);
	soundTest->addOption("Teleport Collect", 17);
	soundTest->addOption("Time", 18);
	
	rootMenu->addOption("Level Editor", 1);
	
	_menuSystem->render();
}

void TitleScreen::renderBackground() {
	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	_bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	_topGfx->drawBitmap(0, 0, 256, 64, &_logoBmp, 0, 0);

	// Copyrights
	WoopsiGfx::WoopsiString str = "ZX (c) 1990 Michael Batty";
	_topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 160, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.setText("DS (c) 2011 Antony Dzeryn");
	_topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 168, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void TitleScreen::iterate() {
	_scroller->render(184, _topGfx);
	_blockSlideshowScreen->iterate();
	_menuSystem->iterate();
}

void TitleScreen::handleMenuAction(Menu* source) {
	switch (source->getId()) {
		case MENU_MAIN:
			mainMenu(source->getSelectedValue());
			break;

		case MENU_LEVEL_SELECT:
			_chosenLevel = LevelDefinitions::getDefinitions().at(source->getSelectedValue());
			SoundPlayer::stopTitleTheme();
			SoundPlayer::playBubbleExplode();
			break;

		case MENU_CUSTOM_LEVEL:
			_chosenLevel = LevelIO::load(source->getSelectedText());
			SoundPlayer::stopTitleTheme();
			SoundPlayer::playBubbleExplode();
			break;
			
		case MENU_SOUND_TEST:
			soundTest(source->getSelectedValue());
	}
}

void TitleScreen::mainMenu(s32 option) {
	switch (option) {
		case 0:
			// Start at beginning of game
			_chosenLevel = LevelDefinitions::getDefinitions().at(0);
			SoundPlayer::stopTitleTheme();
			SoundPlayer::playBubbleExplode();
			break;

		case 1:
			// Level editor
			SoundPlayer::stopTitleTheme();

			LevelEditor* editor = new LevelEditor();
			editor->main();
			delete editor;

			renderBackground();
			prepareMenu();

			SoundPlayer::playTitleTheme();
			break;
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
			SoundPlayer::playSoilPoke();
			break;
		case 16:
			SoundPlayer::playSuicide();
			break;
		case 17:
			SoundPlayer::playTeleportCollect();
			break;
		case 18:
			SoundPlayer::playTime();
			break;
	}
}

bool TitleScreen::isRunning() const {
	return _chosenLevel == NULL;
}

LevelDefinitionBase* TitleScreen::getChosenLevel() const {
	return _chosenLevel;
}
