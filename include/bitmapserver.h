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

	/**
	 * Changes the soil bitmap to the specified type.
	 * @param type The type to change to.
	 */
	static void changeSoilBmp(SoilType type);

	/**
	 * Changes the boulder bitmap to the specified type.
	 * @param type The type to change to.
	 */
	static void changeBoulderBmp(BoulderType type);

	/**
	 * Changes the door bitmap to the specified type.
	 * @param type The type to change to.
	 */
	static void changeDoorBmp(DoorType type);

	/**
	 * Changes the wall bitmap to the specified type.
	 * @param type The type to change to.
	 */
	static void changeWallBmp(WallType type);

	/**
	 * Gets the wall bitmap.
	 * @return The wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getWallBmp() {
		return _wallBmp;
	};

	/**
	 * Gets the door bitmap.
	 * @return The door bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getDoorBmp() {
		return _doorBmp;
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
