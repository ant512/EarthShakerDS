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

#include "brainwallbmp.h"
#include "brickwallbmp.h"
#include "girderwallbmp.h"
#include "heartwallbmp.h"
#include "honeycombwallbmp.h"
#include "icewallbmp.h"
#include "leafywallbmp.h"
#include "metalwallbmp.h"
#include "nuclearwallbmp.h"
#include "rockwallbmp.h"

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
	static void init() {

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
		RockWallBmp rockWallBmp;

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
		_rockWallBmp = createMutableBitmap(&rockWallBmp);

		_redSoilBmp = createMutableBitmap(&soilBmp);
		_blueSoilBmp = createMutableBitmap(&soilBmp);
		_greenSoilBmp = createMutableBitmap(&soilBmp);
		_cyanSoilBmp = createMutableBitmap(&soilBmp);
		_magentaSoilBmp = createMutableBitmap(&soilBmp);
		_whiteSoilBmp = createMutableBitmap(&soilBmp);

		_honeycombSoilBmp = createMutableBitmap(&honeycombSoilBmp);

		_redDoorBmp = createMutableBitmap(&doorBmp);
		_blueDoorBmp = createMutableBitmap(&doorBmp);
		_greenDoorBmp = createMutableBitmap(&doorBmp);
		_cyanDoorBmp = createMutableBitmap(&doorBmp);
		_magentaDoorBmp = createMutableBitmap(&doorBmp);

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
	
		// Recolour soil bitmaps
		swapColours(COLOUR_WHITE, COLOUR_RED, _redSoilBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_RED_DARK, _redSoilBmp);

		swapColours(COLOUR_WHITE, COLOUR_BLUE, _blueSoilBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_BLUE_DARK, _blueSoilBmp);

		swapColours(COLOUR_WHITE, COLOUR_GREEN, _greenSoilBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_GREEN_DARK, _greenSoilBmp);

		swapColours(COLOUR_WHITE, COLOUR_CYAN, _cyanDoorBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_CYAN_DARK, _cyanSoilBmp);

		swapColours(COLOUR_WHITE, COLOUR_MAGENTA, _magentaDoorBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_MAGENTA_DARK, _magentaSoilBmp);
	};

	/**
	 * Turns the brick wall bitmap blue.
	 */
	static void makeBrickWallBlue() {
		swapColours(COLOUR_WHITE, COLOUR_BLUE, _brickWallBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_BLUE_DARK, _brickWallBmp);
	};

	/**
	 * Turns the brick wall bitmap red.
	 */
	static void makeBrickWallRed() {
		swapColours(COLOUR_WHITE, COLOUR_RED, _brickWallBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_RED_DARK, _brickWallBmp);
	};

	/**
	 * Turns the brick wall bitmap green.
	 */
	static void makeBrickWallGreen() {
		swapColours(COLOUR_WHITE, COLOUR_GREEN, _brickWallBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_GREEN_DARK, _brickWallBmp);
	};

	/**
	 * Turns the brick wall bitmap cyan.
	 */
	static void makeBrickWallCyan() {
		swapColours(COLOUR_WHITE, COLOUR_CYAN, _brickWallBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_CYAN_DARK, _brickWallBmp);
	};

	/**
	 * Turns the brick wall bitmap magenta.
	 */
	static void makeBrickWallMagenta() {
		swapColours(COLOUR_WHITE, COLOUR_MAGENTA, _brickWallBmp);
		swapColours(COLOUR_WHITE_DARK, COLOUR_MAGENTA_DARK, _brickWallBmp);
	};

	/**
	 * Turns the boulder bitmaps yellow.
	 */
	static void makeBouldersYellow() {
		changeBoulderColours(COLOUR_YELLOW, COLOUR_YELLOW_DARK);
	};

	/**
	 * Turns the boulder bitmaps blue.
	 */
	static void makeBouldersBlue() {
		changeBoulderColours(COLOUR_BLUE, COLOUR_BLUE_DARK);
	};

	/**
	 * Turns the boulder bitmaps cyan.
	 */
	static void makeBouldersCyan() {
		changeBoulderColours(COLOUR_CYAN, COLOUR_CYAN_DARK);
	};

	/**
	 * Turns the boulder bitmaps red.
	 */
	static void makeBouldersRed() {
		changeBoulderColours(COLOUR_RED, COLOUR_RED_DARK);
	};

	/**
	 * Turns the boulder bitmaps magenta.
	 */
	static void makeBouldersMaganta() {
		changeBoulderColours(COLOUR_MAGENTA, COLOUR_MAGENTA_DARK);
	};

	/**
	 * Turns the boulder bitmaps green.
	 */
	static void makeBouldersGreen() {
		changeBoulderColours(COLOUR_GREEN, COLOUR_GREEN_DARK);
	};

	/**
	 * Deletes any bitmaps that have been created.  Should only be called when
	 * no pointers to the bitmaps are being used externally of rhis class.
	 */
	static void shutdown() {
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
		if (_rockWallBmp != NULL) delete _rockWallBmp;

		if (_redDoorBmp != NULL) delete _redDoorBmp;
		if (_greenDoorBmp != NULL) delete _greenDoorBmp;
		if (_blueDoorBmp != NULL) delete _blueDoorBmp;
		if (_cyanDoorBmp != NULL) delete _cyanDoorBmp;
		if (_magentaDoorBmp != NULL) delete _magentaDoorBmp;

		if (_redSoilBmp != NULL) delete _redSoilBmp;
		if (_greenSoilBmp != NULL) delete _greenSoilBmp;
		if (_blueSoilBmp != NULL) delete _blueSoilBmp;
		if (_cyanSoilBmp != NULL) delete _cyanSoilBmp;
		if (_magentaSoilBmp != NULL) delete _magentaSoilBmp;
		if (_whiteSoilBmp != NULL) delete _whiteSoilBmp;

		if (_honeycombSoilBmp != NULL) delete _honeycombSoilBmp;
	};

	/**
	 * Gets a pointer to the brain wall bitmap.
	 * @return A pointer to the brain wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBrainWallBmp() {
		return _brainWallBmp;
	};

	/**
	 * Gets a pointer to the brick wall bitmap.
	 * @return A pointer to the brick wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBrickWallBmp() {
		return _brickWallBmp;
	};

	/**
	 * Gets a pointer to the girder wall bitmap.
	 * @return A pointer to the girder wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getGirderWallBmp() {
		return _girderWallBmp;
	};

	/**
	 * Gets a pointer to the heart wall bitmap.
	 * @return A pointer to the heart wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getHeartWallBmp() {
		return _heartWallBmp;
	};

	/**
	 * Gets a pointer to the honeycomb wall bitmap.
	 * @return A pointer to the honeycomb wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getHoneycombWallBmp() {
		return _honeycombWallBmp;
	};

	/**
	 * Gets a pointer to the ice wall bitmap.
	 * @return A pointer to the ice wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getIceWallBmp() {
		return _iceWallBmp;
	};

	/**
	 * Gets a pointer to the leafy wall bitmap.
	 * @return A pointer to the leafy wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getLeafyWallBmp() {
		return _leafyWallBmp;
	};

	/**
	 * Gets a pointer to the metal wall bitmap.
	 * @return A pointer to the metal wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getMetalWallBmp() {
		return _metalWallBmp;
	};

	/**
	 * Gets a pointer to the nuclear wall bitmap.
	 * @return A pointer to the nuclear wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getNuclearWallBmp() {
		return _nuclearWallBmp;
	};

	/**
	 * Gets a pointer to the rock wall bitmap.
	 * @return A pointer to the rock wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getRockWallBmp() {
		return _rockWallBmp;
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
	 * Gets a pointer to the red soil bitmap.
	 * @return A pointer to the red soil bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getRedSoilBmp() {
		return _redSoilBmp;
	};

	/**
	 * Gets a pointer to the green soil bitmap.
	 * @return A pointer to the green soil bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getGreenSoilBmp() {
		return _greenSoilBmp;
	};

	/**
	 * Gets a pointer to the blue door bitmap.
	 * @return A pointer to the blue soil bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getBlueSoilBmp() {
		return _blueSoilBmp;
	};

	/**
	 * Gets a pointer to the cyan soil bitmap.
	 * @return A pointer to the cyan soil bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getCyanSoilBmp() {
		return _cyanSoilBmp;
	};

	/**
	 * Gets a pointer to the magenta soil bitmap.
	 * @return A pointer to the magenta soil bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getMagentaSoilBmp() {
		return _magentaSoilBmp;
	};

	/**
	 * Gets a pointer to the white soil bitmap.
	 * @return A pointer to the white soil bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getWhiteSoilBmp() {
		return _whiteSoilBmp;
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

	static WoopsiGfx::Bitmap* _brainWallBmp;
	static WoopsiGfx::Bitmap* _brickWallBmp;
	static WoopsiGfx::Bitmap* _girderWallBmp;
	static WoopsiGfx::Bitmap* _heartWallBmp;
	static WoopsiGfx::Bitmap* _honeycombWallBmp;
	static WoopsiGfx::Bitmap* _iceWallBmp;
	static WoopsiGfx::Bitmap* _leafyWallBmp;
	static WoopsiGfx::Bitmap* _metalWallBmp;
	static WoopsiGfx::Bitmap* _nuclearWallBmp;
	static WoopsiGfx::Bitmap* _rockWallBmp;

	static WoopsiGfx::Bitmap* _redDoorBmp;
	static WoopsiGfx::Bitmap* _blueDoorBmp;
	static WoopsiGfx::Bitmap* _greenDoorBmp;
	static WoopsiGfx::Bitmap* _cyanDoorBmp;
	static WoopsiGfx::Bitmap* _magentaDoorBmp;

	static WoopsiGfx::Bitmap* _redSoilBmp;
	static WoopsiGfx::Bitmap* _blueSoilBmp;
	static WoopsiGfx::Bitmap* _greenSoilBmp;
	static WoopsiGfx::Bitmap* _cyanSoilBmp;
	static WoopsiGfx::Bitmap* _magentaSoilBmp;
	static WoopsiGfx::Bitmap* _whiteSoilBmp;

	static WoopsiGfx::Bitmap* _honeycombSoilBmp;

	/**
	 * Constructor is private to prevent creation.
	 */
	BitmapServer();

	/**
	 * Destructor.
	 */
	~BitmapServer();

	/**
	 * Changes all boulder bitmaps to use the specified colours.
	 * @param light New light colour.
	 * @param dark New dark colour.
	 */
	static void changeBoulderColours(SpectrumColour light, SpectrumColour dark) {
		swapColours(COLOUR_WHITE, light, _boulderBmp);
		swapColours(COLOUR_WHITE_DARK, dark, _boulderBmp);

		swapColours(COLOUR_WHITE, light, _boulderExplodeBmp1);
		swapColours(COLOUR_WHITE_DARK, dark, _boulderExplodeBmp1);

		swapColours(COLOUR_WHITE, light, _boulderExplodeBmp2);
		swapColours(COLOUR_WHITE_DARK, dark, _boulderExplodeBmp2);

		swapColours(COLOUR_WHITE, light, _boulderExplodeBmp3);
		swapColours(COLOUR_YELLOW_DARK, dark, _boulderExplodeBmp3);

		swapColours(COLOUR_WHITE, light, _boulderExplodeBmp4);
		swapColours(COLOUR_WHITE_DARK, dark, _boulderExplodeBmp4);

		swapColours(COLOUR_WHITE, light, _boulderExplodeBmp5);
		swapColours(COLOUR_WHITE_DARK, dark, _boulderExplodeBmp5);

		swapColours(COLOUR_WHITE, light, _boulderExplodeBmp6);
		swapColours(COLOUR_WHITE_DARK, dark, _boulderExplodeBmp6);

		swapColours(COLOUR_WHITE, light, _boulderExplodeBmp7);
		swapColours(COLOUR_WHITE_DARK, dark, _boulderExplodeBmp7);
	};

	/**
	 * Swap two colours on the supplied bitmap.
	 * @param source Colour to swap from.
	 * @param dest Colour to swap to.
	 * @param bitmap The bitmap on which to exchange the colours.
	 */
	static void swapColours(SpectrumColour source, SpectrumColour dest, WoopsiGfx::Bitmap* bitmap) {
		for (s32 x = 0; x < bitmap->getWidth(); ++x) {
			for (s32 y = 0; y < bitmap->getHeight(); ++y) {
				if (bitmap->getPixel(x, y) == (u16)source) bitmap->setPixel(x, y, (u16)dest);
			}
		}
	};

	/**
	 * Creates a mutable copy of the supplied immutable bitmap.  Must be deleted
	 * when it is no longer needed.
	 * @param source The bitmap to copy.
	 * @return A pointer to a mutable copy of the supplied immutable bitmap.
	 */
	static WoopsiGfx::Bitmap* createMutableBitmap(WoopsiGfx::BitmapBase* source) {
		WoopsiGfx::Bitmap* dest = new WoopsiGfx::Bitmap(source->getWidth(), source->getHeight());

		WoopsiGfx::Graphics* gfx = dest->newGraphics();
		gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
		delete gfx;

		return dest;
	};
};

#endif
