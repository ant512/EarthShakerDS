#ifndef _BITMAP_SERVER_H_
#define _BITMAP_SERVER_H_

#include <bitmap.h>
#include <bitmapbase.h>
#include <graphics.h>
#include <mutablebitmapbase.h>

#include "boulderbmp.h"
#include "boulderexplodebmp1.h"
#include "boulderexplodebmp2.h"
#include "boulderexplodebmp3.h"
#include "boulderexplodebmp4.h"
#include "boulderexplodebmp5.h"
#include "boulderexplodebmp6.h"
#include "boulderexplodebmp7.h"

#include "blocktype.h"

#include "brainwallbmp.h"
#include "brickwallbmp.h"
#include "girderwallbmp.h"
#include "heartwallbmp.h"
#include "honeycombwallbmp.h"
#include "icewallbmp.h"
#include "leafywallbmp.h"
#include "metalwallbmp.h"
#include "nuclearwallbmp.h"
#include "pipewallbmp.h"
#include "questionwallbmp.h"
#include "rockwallbmp.h"
#include "sandwallbmp.h"
#include "squarewallbmp.h"

#include "honeycombsoilbmp.h"
#include "soilbmp.h"

#include "doorbmp.h"

#include "spectrumcolours.h"

/**
 * Supplies pre-instantiated mutable bitmap objects that can be recoloured.
 */
class BitmapServer {
public:

	/**
	 * Creates all mutable bitmaps ready for use.  If the bitmaps already exist,
	 * it resets them to their original state by deleting the existing bitmaps
	 * and recreating them.
	 */
	static void init();

	/**
	 * Deletes any bitmaps that have been created.  Should only be called when
	 * no pointers to the bitmaps are being used externally of rhis class.
	 */
	static void shutdown();

	inline static WoopsiGfx::Bitmap* getWallBmp() {
		return _wallBmp;
	};

	inline static WoopsiGfx::Bitmap* getDoorBmp() {
		return _doorBmp;
	};

	static void changeSoilBmp(SoilType type) {

		WoopsiGfx::Graphics* gfx = _soilBmp->newGraphics();
		WoopsiGfx::BitmapBase* source = NULL;

		switch (type) {
			case SOIL_TYPE_WHITE:
				source = new SoilBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case SOIL_TYPE_RED:
				source = new SoilBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_RED, _soilBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_RED_DARK, _soilBmp);
				break;
			case SOIL_TYPE_GREEN:
				source = new SoilBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_GREEN, _soilBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_GREEN_DARK, _soilBmp);
				break;
			case SOIL_TYPE_BLUE:
				source = new SoilBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_BLUE, _soilBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_BLUE_DARK, _soilBmp);
				break;
			case SOIL_TYPE_CYAN:
				source = new SoilBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_CYAN, _soilBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_CYAN_DARK, _soilBmp);
				break;
			case SOIL_TYPE_MAGENTA:
				source = new SoilBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_MAGENTA, _soilBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_MAGENTA_DARK, _soilBmp);
				break;
			case SOIL_TYPE_YELLOW:
				source = new SoilBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_YELLOW, _soilBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_YELLOW_DARK, _soilBmp);
				break;
			case SOIL_TYPE_HONEYCOMB:
				source = new HoneycombSoilBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case SOIL_TYPE_QUESTION:
				source = new QuestionWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case SOIL_TYPE_BOULDER:
				source = _boulderBmp;
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
		}
	};

	static void changeBoulderBmp(BoulderType type) {
		switch (type) {
			case BOULDER_TYPE_WHITE:
				makeBouldersWhite();
				break;
			case BOULDER_TYPE_RED:
				makeBouldersRed();
				break;
			case BOULDER_TYPE_GREEN:
				makeBouldersGreen();
				break;
			case BOULDER_TYPE_BLUE:
				makeBouldersBlue();
				break;
			case BOULDER_TYPE_CYAN:
				makeBouldersCyan();
				break;
			case BOULDER_TYPE_MAGENTA:
				makeBouldersMagenta();
				break;
			case BOULDER_TYPE_YELLOW:
				makeBouldersYellow();
				break;
		}
	};

	static void changeDoorBmp(DoorType type) {

		WoopsiGfx::Graphics* gfx = _doorBmp->newGraphics();
		WoopsiGfx::BitmapBase* source = NULL;

		switch (type) {
			case DOOR_TYPE_WHITE:
				source = _whiteDoorBmp;
				break;
			case DOOR_TYPE_RED:
				source = _redDoorBmp;
				break;
			case DOOR_TYPE_GREEN:
				source = _greenDoorBmp;
				break;
			case DOOR_TYPE_BLUE:
				source = _blueDoorBmp;
				break;
			case DOOR_TYPE_CYAN:
				source = _cyanDoorBmp;
				break;
			case DOOR_TYPE_MAGENTA:
				source = _magentaDoorBmp;
				break;
			case DOOR_TYPE_YELLOW:
				source = _yellowDoorBmp;
				break;
		}

		gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
		delete gfx;
	};

	static void changeWallBmp(WallType type) {

		WoopsiGfx::Graphics* gfx = _wallBmp->newGraphics();
		WoopsiGfx::BitmapBase* source = NULL;

		switch (type) {
			case WALL_TYPE_BRICK_WHITE:
				source = new BrickWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_BRICK_RED:
				source = new BrickWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_RED, _wallBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_RED_DARK, _wallBmp);
				break;
			case WALL_TYPE_BRICK_GREEN:
				source = new BrickWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_GREEN, _wallBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_GREEN_DARK, _wallBmp);
				break;
			case WALL_TYPE_BRICK_BLUE:
				source = new BrickWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_BLUE, _wallBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_BLUE_DARK, _wallBmp);
				break;
			case WALL_TYPE_BRICK_CYAN:
				source = new BrickWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_CYAN, _wallBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_CYAN_DARK, _wallBmp);
				break;
			case WALL_TYPE_BRICK_MAGENTA:
				source = new BrickWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_MAGENTA, _wallBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_MAGENTA_DARK, _wallBmp);
				break;
			case WALL_TYPE_BRICK_YELLOW:
				source = new BrickWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				swapColours(COLOUR_WHITE, COLOUR_YELLOW, _wallBmp);
				swapColours(COLOUR_WHITE_DARK, COLOUR_YELLOW_DARK, _wallBmp);
				break;
			case WALL_TYPE_ROCK:
				source = new RockWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_ICE:
				source = new IceWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_METAL:
				source = new MetalWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_BRAIN:
				source = new BrainWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_GIRDER:
				source = new GirderWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_HEART:
				source = new HeartWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_HONEYCOMB:
				source = new HoneycombWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_LEAFY:
				source = new LeafyWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_NUCLEAR:
				source = new NuclearWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_PIPE:
				source = new PipeWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_QUESTION:
				source = new QuestionWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_SAND:
				source = new SandWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
			case WALL_TYPE_SQUARE:
				source = new SquareWallBmp();
				gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
				break;
		}
		
		delete source;
		delete gfx;
	};

	/**
	 * Gets a pointer to the boulder bitmap.
	 * @return A pointer to the boulder bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBoulderBmp() {
		return _boulderBmp;
	};

	/**
	 * Gets a pointer to the first boulder explosion bitmap.
	 * @return A pointer to the first boulder explosion bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp1() {
		return _boulderExplodeBmp1;
	};

	/**
	 * Gets a pointer to the second boulder explosion bitmap.
	 * @return A pointer to the second boulder explosion bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp2() {
		return _boulderExplodeBmp2;
	};

	/**
	 * Gets a pointer to the third boulder explosion bitmap.
	 * @return A pointer to the third boulder explosion bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp3() {
		return _boulderExplodeBmp3;
	};

	/**
	 * Gets a pointer to the fourth boulder explosion bitmap.
	 * @return A pointer to the fourth boulder explosion bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp4() {
		return _boulderExplodeBmp4;
	};

	/**
	 * Gets a pointer to the fifth boulder explosion bitmap.
	 * @return A pointer to the fifth boulder explosion bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp5() {
		return _boulderExplodeBmp5;
	};

	/**
	 * Gets a pointer to the sixth boulder explosion bitmap.
	 * @return A pointer to the sixth boulder explosion bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp6() {
		return _boulderExplodeBmp6;
	};

	/**
	 * Gets a pointer to the seventh boulder explosion bitmap.
	 * @return A pointer to the seventh boulder explosion bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp7() {
		return _boulderExplodeBmp7;
	};

	/**
	 * Gets a pointer to the red door bitmap.
	 * @return A pointer to the red door bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getRedDoorBmp() {
		return _redDoorBmp;
	};

	/**
	 * Gets a pointer to the green door bitmap.
	 * @return A pointer to the green door bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getGreenDoorBmp() {
		return _greenDoorBmp;
	};

	/**
	 * Gets a pointer to the blue door bitmap.
	 * @return A pointer to the blue door bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBlueDoorBmp() {
		return _blueDoorBmp;
	};

	/**
	 * Gets a pointer to the cyan door bitmap.
	 * @return A pointer to the cyan door bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getCyanDoorBmp() {
		return _cyanDoorBmp;
	};

	/**
	 * Gets a pointer to the magenta door bitmap.
	 * @return A pointer to the magenta door bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getMagentaDoorBmp() {
		return _magentaDoorBmp;
	};

	/**
	 * Gets a pointer to the white door bitmap.
	 * @return A pointer to the white door bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getWhiteDoorBmp() {
		return _whiteDoorBmp;
	};

	/**
	 * Gets a pointer to the yellow door bitmap.
	 * @return A pointer to the yellow door bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getYellowDoorBmp() {
		return _yellowDoorBmp;
	};

	/**
	 * Gets a pointer to the soil bitmap.
	 * @return A pointer to the soil bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getSoilBmp() {
		return _soilBmp;
	};

	/**
	 * Gets a pointer to the honeycomb soil bitmap.
	 * @return A pointer to the honeycomb soil bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getHoneycombSoilBmp() {
		return _honeycombSoilBmp;
	};

private:
	static WoopsiGfx::Bitmap* _boulderBmp;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp1;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp2;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp3;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp4;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp5;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp6;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp7;

	static WoopsiGfx::Bitmap* _redDoorBmp;
	static WoopsiGfx::Bitmap* _blueDoorBmp;
	static WoopsiGfx::Bitmap* _greenDoorBmp;
	static WoopsiGfx::Bitmap* _cyanDoorBmp;
	static WoopsiGfx::Bitmap* _magentaDoorBmp;
	static WoopsiGfx::Bitmap* _whiteDoorBmp;
	static WoopsiGfx::Bitmap* _yellowDoorBmp;

	static WoopsiGfx::Bitmap* _soilBmp;

	static WoopsiGfx::Bitmap* _honeycombSoilBmp;

	static WoopsiGfx::Bitmap* _doorBmp;
	static WoopsiGfx::Bitmap* _wallBmp;

	static SpectrumColour _soilColour;
	static SpectrumColour _soilDarkColour;
	static SpectrumColour _boulderColour;
	static SpectrumColour _boulderDarkColour;
	static SpectrumColour _brickWallColour;
	static SpectrumColour _brickWallDarkColour;

	/**
	 * Constructor is private to prevent creation.
	 */
	BitmapServer() { };

	/**
	 * Destructor.
	 */
	~BitmapServer() { };

	/**
	 * Turns the boulder bitmaps yellow.
	 */
	static void makeBouldersYellow();

	/**
	 * Turns the boulder bitmaps blue.
	 */
	static void makeBouldersBlue();

	/**
	 * Turns the boulder bitmaps cyan.
	 */
	static void makeBouldersCyan();

	/**
	 * Turns the boulder bitmaps red.
	 */
	static void makeBouldersRed();

	/**
	 * Turns the boulder bitmaps magenta.
	 */
	static void makeBouldersMagenta();

	/**
	 * Turns the boulder bitmaps green.
	 */
	static void makeBouldersGreen();

	/**
	 * Turns the boulder bitmaps white.
	 */
	static void makeBouldersWhite();

	/**
	 * Changes all boulder bitmaps to use the specified colours.
	 * @param light New light colour.
	 * @param dark New dark colour.
	 */
	static void changeBoulderColours(SpectrumColour light, SpectrumColour dark);

	/**
	 * Swap two colours on the supplied bitmap.
	 * @param source Colour to swap from.
	 * @param dest Colour to swap to.
	 * @param bitmap The bitmap on which to exchange the colours.
	 */
	static void swapColours(SpectrumColour source, SpectrumColour dest, WoopsiGfx::Bitmap* bitmap);

	/**
	 * Creates a mutable copy of the supplied immutable bitmap.  Must be deleted
	 * when it is no longer needed.
	 * @param source The bitmap to copy.
	 * @return A pointer to a mutable copy of the supplied immutable bitmap.
	 */
	static WoopsiGfx::Bitmap* createMutableBitmap(WoopsiGfx::BitmapBase* source);
};

#endif
