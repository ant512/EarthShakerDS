#include "bitmapserver.h"

WoopsiGfx::Bitmap* BitmapServer::_boulderBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp1 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp2 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp3 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp4 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp5 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp6 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp7 = NULL;

WoopsiGfx::Bitmap* BitmapServer::_blueDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_cyanDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_greenDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_magentaDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_redDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_whiteDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_yellowDoorBmp = NULL;

WoopsiGfx::Bitmap* BitmapServer::_soilBmp = NULL;

WoopsiGfx::Bitmap* BitmapServer::_honeycombSoilBmp = NULL;

WoopsiGfx::Bitmap* BitmapServer::_doorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_wallBmp = NULL;

SpectrumColour BitmapServer::_boulderColour = COLOUR_WHITE;
SpectrumColour BitmapServer::_boulderDarkColour = COLOUR_WHITE_DARK;

void BitmapServer::init() {

	// Clean up in case we're called more than once
	shutdown();

	BoulderBmp boulderBmp;
	BoulderExplodeBmp1 boulderExplodeBmp1;
	BoulderExplodeBmp2 boulderExplodeBmp2;
	BoulderExplodeBmp3 boulderExplodeBmp3;
	BoulderExplodeBmp4 boulderExplodeBmp4;
	BoulderExplodeBmp5 boulderExplodeBmp5;
	BoulderExplodeBmp6 boulderExplodeBmp6;
	BoulderExplodeBmp7 boulderExplodeBmp7;

	DoorBmp doorBmp;

	HoneycombSoilBmp honeycombSoilBmp;
	SoilBmp soilBmp;

	BrickWallBmp brickWallBmp;

	_boulderBmp = createMutableBitmap(&boulderBmp);
	_boulderExplodeBmp1 = createMutableBitmap(&boulderExplodeBmp1);
	_boulderExplodeBmp2 = createMutableBitmap(&boulderExplodeBmp2);
	_boulderExplodeBmp3 = createMutableBitmap(&boulderExplodeBmp3);
	_boulderExplodeBmp4 = createMutableBitmap(&boulderExplodeBmp4);
	_boulderExplodeBmp5 = createMutableBitmap(&boulderExplodeBmp5);
	_boulderExplodeBmp6 = createMutableBitmap(&boulderExplodeBmp6);
	_boulderExplodeBmp7 = createMutableBitmap(&boulderExplodeBmp7);

	_soilBmp = createMutableBitmap(&soilBmp);

	_honeycombSoilBmp = createMutableBitmap(&honeycombSoilBmp);

	_doorBmp = createMutableBitmap(&doorBmp);
	_blueDoorBmp = createMutableBitmap(&doorBmp);
	_cyanDoorBmp = createMutableBitmap(&doorBmp);
	_greenDoorBmp = createMutableBitmap(&doorBmp);
	_magentaDoorBmp = createMutableBitmap(&doorBmp);
	_redDoorBmp = createMutableBitmap(&doorBmp);
	_whiteDoorBmp = createMutableBitmap(&doorBmp);
	_yellowDoorBmp = createMutableBitmap(&doorBmp);

	_wallBmp = createMutableBitmap(&brickWallBmp);

	// Recolour door bitmaps
	swapColours(COLOUR_WHITE, COLOUR_RED, _redDoorBmp);
	swapColours(COLOUR_WHITE_DARK, COLOUR_RED_DARK, _redDoorBmp);

	swapColours(COLOUR_WHITE, COLOUR_BLUE, _blueDoorBmp);
	swapColours(COLOUR_WHITE_DARK, COLOUR_BLUE_DARK, _blueDoorBmp);

	swapColours(COLOUR_WHITE, COLOUR_GREEN, _greenDoorBmp);
	swapColours(COLOUR_WHITE_DARK, COLOUR_GREEN_DARK, _greenDoorBmp);

	swapColours(COLOUR_WHITE, COLOUR_CYAN, _cyanDoorBmp);
	swapColours(COLOUR_WHITE_DARK, COLOUR_CYAN_DARK, _cyanDoorBmp);

	swapColours(COLOUR_WHITE, COLOUR_MAGENTA, _magentaDoorBmp);
	swapColours(COLOUR_WHITE_DARK, COLOUR_MAGENTA_DARK, _magentaDoorBmp);

	swapColours(COLOUR_WHITE, COLOUR_YELLOW, _yellowDoorBmp);
	swapColours(COLOUR_WHITE_DARK, COLOUR_YELLOW_DARK, _yellowDoorBmp);
}

void BitmapServer::makeBouldersYellow() {
	changeBoulderColours(COLOUR_YELLOW, COLOUR_YELLOW_DARK);
}

void BitmapServer::makeBouldersBlue() {
	changeBoulderColours(COLOUR_BLUE, COLOUR_BLUE_DARK);
}

void BitmapServer::makeBouldersCyan() {
	changeBoulderColours(COLOUR_CYAN, COLOUR_CYAN_DARK);
}

void BitmapServer::makeBouldersRed() {
	changeBoulderColours(COLOUR_RED, COLOUR_RED_DARK);
}

void BitmapServer::makeBouldersMagenta() {
	changeBoulderColours(COLOUR_MAGENTA, COLOUR_MAGENTA_DARK);
}

void BitmapServer::makeBouldersGreen() {
	changeBoulderColours(COLOUR_GREEN, COLOUR_GREEN_DARK);
}

void BitmapServer::makeBouldersWhite() {
	changeBoulderColours(COLOUR_WHITE, COLOUR_WHITE_DARK);
}

void BitmapServer::shutdown() {
	if (_boulderBmp != NULL) delete _boulderBmp;
	if (_boulderExplodeBmp1 != NULL) delete _boulderExplodeBmp1;
	if (_boulderExplodeBmp2 != NULL) delete _boulderExplodeBmp2;
	if (_boulderExplodeBmp3 != NULL) delete _boulderExplodeBmp3;
	if (_boulderExplodeBmp4 != NULL) delete _boulderExplodeBmp4;
	if (_boulderExplodeBmp5 != NULL) delete _boulderExplodeBmp5;
	if (_boulderExplodeBmp6 != NULL) delete _boulderExplodeBmp6;
	if (_boulderExplodeBmp7 != NULL) delete _boulderExplodeBmp7;

	if (_redDoorBmp != NULL) delete _redDoorBmp;
	if (_greenDoorBmp != NULL) delete _greenDoorBmp;
	if (_blueDoorBmp != NULL) delete _blueDoorBmp;
	if (_cyanDoorBmp != NULL) delete _cyanDoorBmp;
	if (_magentaDoorBmp != NULL) delete _magentaDoorBmp;
	if (_yellowDoorBmp != NULL) delete _yellowDoorBmp;

	if (_soilBmp != NULL) delete _soilBmp;

	if (_honeycombSoilBmp != NULL) delete _honeycombSoilBmp;

	if (_doorBmp != NULL) delete _doorBmp;
	if (_wallBmp != NULL) delete _wallBmp;
}

void BitmapServer::changeBoulderColours(SpectrumColour light, SpectrumColour dark) {
	swapColours(_boulderColour, light, _boulderBmp);
	swapColours(_boulderDarkColour, dark, _boulderBmp);

	swapColours(_boulderColour, light, _boulderExplodeBmp1);
	swapColours(_boulderDarkColour, dark, _boulderExplodeBmp1);

	swapColours(_boulderColour, light, _boulderExplodeBmp2);
	swapColours(_boulderDarkColour, dark, _boulderExplodeBmp2);

	swapColours(_boulderColour, light, _boulderExplodeBmp3);
	swapColours(_boulderDarkColour, dark, _boulderExplodeBmp3);

	swapColours(_boulderColour, light, _boulderExplodeBmp4);
	swapColours(_boulderDarkColour, dark, _boulderExplodeBmp4);

	swapColours(_boulderColour, light, _boulderExplodeBmp5);
	swapColours(_boulderDarkColour, dark, _boulderExplodeBmp5);

	swapColours(_boulderColour, light, _boulderExplodeBmp6);
	swapColours(_boulderDarkColour, dark, _boulderExplodeBmp6);

	swapColours(_boulderColour, light, _boulderExplodeBmp7);
	swapColours(_boulderDarkColour, dark, _boulderExplodeBmp7);

	_boulderColour = light;
	_boulderDarkColour = dark;
}

void BitmapServer::swapColours(SpectrumColour source, SpectrumColour dest, WoopsiGfx::Bitmap* bitmap) {
	for (s32 x = 0; x < bitmap->getWidth(); ++x) {
		for (s32 y = 0; y < bitmap->getHeight(); ++y) {
			if (bitmap->getPixel(x, y) == (u16)source) bitmap->setPixel(x, y, (u16)dest);
		}
	}
}

WoopsiGfx::Bitmap* BitmapServer::createMutableBitmap(WoopsiGfx::BitmapBase* source) {
	WoopsiGfx::Bitmap* dest = new WoopsiGfx::Bitmap(source->getWidth(), source->getHeight());

	WoopsiGfx::Graphics* gfx = dest->newGraphics();
	gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
	delete gfx;

	return dest;
}
