#include "bitmapserver.h"

WoopsiGfx::Bitmap* BitmapServer::_boulderBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp1 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp2 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp3 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp4 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp5 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp6 = NULL;
WoopsiGfx::Bitmap* BitmapServer::_boulderExplodeBmp7 = NULL;

WoopsiGfx::Bitmap* BitmapServer::_brainWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_brickWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_girderWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_heartWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_honeycombWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_iceWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_leafyWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_metalWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_nuclearWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_pipeWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_questionWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_rockWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_sandWallBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_squareWallBmp = NULL;

WoopsiGfx::Bitmap* BitmapServer::_blueDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_cyanDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_greenDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_magentaDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_redDoorBmp = NULL;
WoopsiGfx::Bitmap* BitmapServer::_yellowDoorBmp = NULL;

WoopsiGfx::Bitmap* BitmapServer::_soilBmp = NULL;

WoopsiGfx::Bitmap* BitmapServer::_honeycombSoilBmp = NULL;

SpectrumColour BitmapServer::_soilColour = COLOUR_WHITE;
SpectrumColour BitmapServer::_soilDarkColour = COLOUR_WHITE_DARK;
SpectrumColour BitmapServer::_boulderColour = COLOUR_WHITE;
SpectrumColour BitmapServer::_boulderDarkColour = COLOUR_WHITE_DARK;
SpectrumColour BitmapServer::_brickWallColour = COLOUR_WHITE;
SpectrumColour BitmapServer::_brickWallDarkColour = COLOUR_WHITE_DARK;

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

	BrainWallBmp brainWallBmp;
	BrickWallBmp brickWallBmp;
	GirderWallBmp girderWallBmp;
	HeartWallBmp heartWallBmp;
	HoneycombWallBmp honeycombWallBmp;
	IceWallBmp iceWallBmp;
	LeafyWallBmp leafyWallBmp;
	MetalWallBmp metalWallBmp;
	NuclearWallBmp nuclearWallBmp;
	PipeWallBmp pipeWallBmp;
	QuestionWallBmp questionWallBmp;
	RockWallBmp rockWallBmp;
	SandWallBmp sandWallBmp;
	SquareWallBmp squareWallBmp;

	DoorBmp doorBmp;

	HoneycombSoilBmp honeycombSoilBmp;
	SoilBmp soilBmp;

	_boulderBmp = createMutableBitmap(&boulderBmp);
	_boulderExplodeBmp1 = createMutableBitmap(&boulderExplodeBmp1);
	_boulderExplodeBmp2 = createMutableBitmap(&boulderExplodeBmp2);
	_boulderExplodeBmp3 = createMutableBitmap(&boulderExplodeBmp3);
	_boulderExplodeBmp4 = createMutableBitmap(&boulderExplodeBmp4);
	_boulderExplodeBmp5 = createMutableBitmap(&boulderExplodeBmp5);
	_boulderExplodeBmp6 = createMutableBitmap(&boulderExplodeBmp6);
	_boulderExplodeBmp7 = createMutableBitmap(&boulderExplodeBmp7);

	_brainWallBmp = createMutableBitmap(&brainWallBmp);
	_brickWallBmp = createMutableBitmap(&brickWallBmp);
	_girderWallBmp = createMutableBitmap(&girderWallBmp);
	_heartWallBmp = createMutableBitmap(&heartWallBmp);
	_honeycombWallBmp = createMutableBitmap(&honeycombWallBmp);
	_iceWallBmp = createMutableBitmap(&iceWallBmp);
	_leafyWallBmp = createMutableBitmap(&leafyWallBmp);
	_metalWallBmp = createMutableBitmap(&metalWallBmp);
	_nuclearWallBmp = createMutableBitmap(&nuclearWallBmp);
	_pipeWallBmp = createMutableBitmap(&pipeWallBmp);
	_questionWallBmp = createMutableBitmap(&questionWallBmp);
	_rockWallBmp = createMutableBitmap(&rockWallBmp);
	_sandWallBmp = createMutableBitmap(&sandWallBmp);
	_squareWallBmp = createMutableBitmap(&squareWallBmp);

	_soilBmp = createMutableBitmap(&soilBmp);

	_honeycombSoilBmp = createMutableBitmap(&honeycombSoilBmp);

	_blueDoorBmp = createMutableBitmap(&doorBmp);
	_cyanDoorBmp = createMutableBitmap(&doorBmp);
	_greenDoorBmp = createMutableBitmap(&doorBmp);
	_magentaDoorBmp = createMutableBitmap(&doorBmp);
	_redDoorBmp = createMutableBitmap(&doorBmp);
	_yellowDoorBmp = createMutableBitmap(&doorBmp);

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

void BitmapServer::makeBrickWallBlue() {
	swapColours(_brickWallColour, COLOUR_BLUE, _brickWallBmp);
	swapColours(_brickWallDarkColour, COLOUR_BLUE_DARK, _brickWallBmp);

	_brickWallColour = COLOUR_BLUE;
	_brickWallDarkColour = COLOUR_BLUE_DARK;
}

void BitmapServer::makeBrickWallRed() {
	swapColours(_brickWallColour, COLOUR_RED, _brickWallBmp);
	swapColours(_brickWallDarkColour, COLOUR_RED_DARK, _brickWallBmp);

	_brickWallColour = COLOUR_RED;
	_brickWallDarkColour = COLOUR_RED_DARK;
}

void BitmapServer::makeBrickWallGreen() {
	swapColours(_brickWallColour, COLOUR_GREEN, _brickWallBmp);
	swapColours(_brickWallDarkColour, COLOUR_GREEN_DARK, _brickWallBmp);

	_brickWallColour = COLOUR_GREEN;
	_brickWallDarkColour = COLOUR_GREEN_DARK;
}

void BitmapServer::makeBrickWallCyan() {
	swapColours(_brickWallColour, COLOUR_CYAN, _brickWallBmp);
	swapColours(_brickWallDarkColour, COLOUR_CYAN_DARK, _brickWallBmp);

	_brickWallColour = COLOUR_CYAN;
	_brickWallDarkColour = COLOUR_CYAN_DARK;
}

void BitmapServer::makeBrickWallMagenta() {
	swapColours(_brickWallColour, COLOUR_MAGENTA, _brickWallBmp);
	swapColours(_brickWallDarkColour, COLOUR_MAGENTA_DARK, _brickWallBmp);

	_brickWallColour = COLOUR_MAGENTA;
	_brickWallDarkColour = COLOUR_MAGENTA_DARK;
}

void BitmapServer::makeSoilBlue() {
	swapColours(_soilColour, COLOUR_BLUE, _soilBmp);
	swapColours(_soilDarkColour, COLOUR_BLUE_DARK, _soilBmp);

	_soilColour = COLOUR_BLUE;
	_soilDarkColour = COLOUR_BLUE_DARK;
}

void BitmapServer::makeSoilCyan() {
	swapColours(_soilColour, COLOUR_CYAN, _soilBmp);
	swapColours(_soilDarkColour, COLOUR_CYAN_DARK, _soilBmp);

	_soilColour = COLOUR_CYAN;
	_soilDarkColour = COLOUR_CYAN_DARK;
}

void BitmapServer::makeSoilRed() {
	swapColours(_soilColour, COLOUR_RED, _soilBmp);
	swapColours(_soilDarkColour, COLOUR_RED_DARK, _soilBmp);

	_soilColour = COLOUR_RED;
	_soilDarkColour = COLOUR_RED_DARK;
}

void BitmapServer::makeSoilGreen() {
	swapColours(_soilColour, COLOUR_GREEN, _soilBmp);
	swapColours(_soilDarkColour, COLOUR_GREEN_DARK, _soilBmp);

	_soilColour = COLOUR_GREEN;
	_soilDarkColour = COLOUR_GREEN_DARK;
}

void BitmapServer::makSoilCyan() {
	swapColours(_soilColour, COLOUR_CYAN, _soilBmp);
	swapColours(_soilDarkColour, COLOUR_CYAN_DARK, _soilBmp);

	_soilColour = COLOUR_CYAN;
	_soilDarkColour = COLOUR_CYAN_DARK;
}

void BitmapServer::makeSoilMagenta() {
	swapColours(_soilColour, COLOUR_MAGENTA, _soilBmp);
	swapColours(_soilDarkColour, COLOUR_MAGENTA_DARK, _soilBmp);

	_soilColour = COLOUR_MAGENTA;
	_soilDarkColour = COLOUR_MAGENTA_DARK;
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

void BitmapServer::shutdown() {
	if (_boulderBmp != NULL) delete _boulderBmp;
	if (_boulderExplodeBmp1 != NULL) delete _boulderExplodeBmp1;
	if (_boulderExplodeBmp2 != NULL) delete _boulderExplodeBmp2;
	if (_boulderExplodeBmp3 != NULL) delete _boulderExplodeBmp3;
	if (_boulderExplodeBmp4 != NULL) delete _boulderExplodeBmp4;
	if (_boulderExplodeBmp5 != NULL) delete _boulderExplodeBmp5;
	if (_boulderExplodeBmp6 != NULL) delete _boulderExplodeBmp6;
	if (_boulderExplodeBmp7 != NULL) delete _boulderExplodeBmp7;

	if (_brainWallBmp != NULL) delete _brainWallBmp;
	if (_brickWallBmp != NULL) delete _brickWallBmp;
	if (_girderWallBmp != NULL) delete _girderWallBmp;
	if (_heartWallBmp != NULL) delete _heartWallBmp;
	if (_honeycombWallBmp != NULL) delete _honeycombWallBmp;
	if (_iceWallBmp != NULL) delete _iceWallBmp;
	if (_leafyWallBmp != NULL) delete _leafyWallBmp;
	if (_metalWallBmp != NULL) delete _metalWallBmp;
	if (_nuclearWallBmp != NULL) delete _nuclearWallBmp;
	if (_pipeWallBmp != NULL) delete _pipeWallBmp;
	if (_questionWallBmp != NULL) delete _questionWallBmp;
	if (_rockWallBmp != NULL) delete _rockWallBmp;
	if (_sandWallBmp != NULL) delete _sandWallBmp;
	if (_squareWallBmp != NULL) delete _squareWallBmp;

	if (_redDoorBmp != NULL) delete _redDoorBmp;
	if (_greenDoorBmp != NULL) delete _greenDoorBmp;
	if (_blueDoorBmp != NULL) delete _blueDoorBmp;
	if (_cyanDoorBmp != NULL) delete _cyanDoorBmp;
	if (_magentaDoorBmp != NULL) delete _magentaDoorBmp;
	if (_yellowDoorBmp != NULL) delete _yellowDoorBmp;

	if (_soilBmp != NULL) delete _soilBmp;

	if (_honeycombSoilBmp != NULL) delete _honeycombSoilBmp;
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
};
