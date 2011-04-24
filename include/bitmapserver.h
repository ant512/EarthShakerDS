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
	 * Turns the brick wall bitmap blue.
	 */
	static void makeBrickWallBlue();

	/**
	 * Turns the brick wall bitmap red.
	 */
	static void makeBrickWallRed();

	/**
	 * Turns the brick wall bitmap green.
	 */
	static void makeBrickWallGreen();

	/**
	 * Turns the brick wall bitmap cyan.
	 */
	static void makeBrickWallCyan();

	/**
	 * Turns the brick wall bitmap magenta.
	 */
	static void makeBrickWallMagenta();

	/**
	 * Turns the soil bitmap blue.
	 */
	static void makeSoilBlue();

	/**
	 * Turns the soil bitmap cyan.
	 */
	static void makeSoilCyan();

	/**
	 * Turns the soil bitmap red.
	 */
	static void makeSoilRed();

	/**
	 * Turns the soil bitmap green.
	 */
	static void makeSoilGreen();

	/**
	 * Turns the soil bitmap cyan.
	 */
	static void makSoilCyan();

	/**
	 * Turns the soil bitmap magenta.
	 */
	static void makeSoilMagenta();

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
	 * Deletes any bitmaps that have been created.  Should only be called when
	 * no pointers to the bitmaps are being used externally of rhis class.
	 */
	static void shutdown();

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
	 * Gets a pointer to the pipe wall bitmap.
	 * @return A pointer to the pipe wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getPipeWallBmp() {
		return _pipeWallBmp;
	};

	/**
	 * Gets a pointer to the question wall bitmap.
	 * @return A pointer to the question wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getQuestionWallBmp() {
		return _questionWallBmp;
	};

	/**
	 * Gets a pointer to the rock wall bitmap.
	 * @return A pointer to the rock wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getRockWallBmp() {
		return _rockWallBmp;
	};

	/**
	 * Gets a pointer to the sand wall bitmap.
	 * @return A pointer to the sand wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getSandWallBmp() {
		return _sandWallBmp;
	};

	/**
	 * Gets a pointer to the square wall bitmap.
	 * @return A pointer to the square wall bitmap.
	 */
	inline static WoopsiGfx::Bitmap* getSquareWallBmp() {
		return _squareWallBmp;
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

	static WoopsiGfx::Bitmap* _brainWallBmp;
	static WoopsiGfx::Bitmap* _brickWallBmp;
	static WoopsiGfx::Bitmap* _girderWallBmp;
	static WoopsiGfx::Bitmap* _heartWallBmp;
	static WoopsiGfx::Bitmap* _honeycombWallBmp;
	static WoopsiGfx::Bitmap* _iceWallBmp;
	static WoopsiGfx::Bitmap* _leafyWallBmp;
	static WoopsiGfx::Bitmap* _metalWallBmp;
	static WoopsiGfx::Bitmap* _nuclearWallBmp;
	static WoopsiGfx::Bitmap* _pipeWallBmp;
	static WoopsiGfx::Bitmap* _questionWallBmp;
	static WoopsiGfx::Bitmap* _rockWallBmp;
	static WoopsiGfx::Bitmap* _sandWallBmp;
	static WoopsiGfx::Bitmap* _squareWallBmp;

	static WoopsiGfx::Bitmap* _redDoorBmp;
	static WoopsiGfx::Bitmap* _blueDoorBmp;
	static WoopsiGfx::Bitmap* _greenDoorBmp;
	static WoopsiGfx::Bitmap* _cyanDoorBmp;
	static WoopsiGfx::Bitmap* _magentaDoorBmp;
	static WoopsiGfx::Bitmap* _yellowDoorBmp;

	static WoopsiGfx::Bitmap* _soilBmp;

	static WoopsiGfx::Bitmap* _honeycombSoilBmp;

	static SpectrumColour _soilColour;
	static SpectrumColour _soilDarkColour;
	static SpectrumColour _boulderColour;
	static SpectrumColour _boulderDarkColour;
	static SpectrumColour _brickWallColour;
	static SpectrumColour _brickWallDarkColour;

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
