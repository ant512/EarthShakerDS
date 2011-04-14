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
#include "soilbmp.h"
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
		if (_boulderBmp != NULL) delete _boulderBmp;
		if (_boulderExplodeBmp1 != NULL) delete _boulderExplodeBmp1;
		if (_boulderExplodeBmp2 != NULL) delete _boulderExplodeBmp2;
		if (_boulderExplodeBmp3 != NULL) delete _boulderExplodeBmp3;
		if (_boulderExplodeBmp4 != NULL) delete _boulderExplodeBmp4;
		if (_boulderExplodeBmp5 != NULL) delete _boulderExplodeBmp5;
		if (_boulderExplodeBmp6 != NULL) delete _boulderExplodeBmp6;
		if (_boulderExplodeBmp7 != NULL) delete _boulderExplodeBmp7;
		if (_soilBmp != NULL) delete _soilBmp;

		BoulderBmp boulderBmp;
		BoulderExplodeBmp1 boulderExplodeBmp1;
		BoulderExplodeBmp2 boulderExplodeBmp2;
		BoulderExplodeBmp3 boulderExplodeBmp3;
		BoulderExplodeBmp4 boulderExplodeBmp4;
		BoulderExplodeBmp5 boulderExplodeBmp5;
		BoulderExplodeBmp6 boulderExplodeBmp6;
		BoulderExplodeBmp7 boulderExplodeBmp7;
		SoilBmp soilBmp;

		_boulderBmp = createMutableBitmap(&boulderBmp);
		_boulderExplodeBmp1 = createMutableBitmap(&boulderExplodeBmp1);
		_boulderExplodeBmp2 = createMutableBitmap(&boulderExplodeBmp2);
		_boulderExplodeBmp3 = createMutableBitmap(&boulderExplodeBmp3);
		_boulderExplodeBmp4 = createMutableBitmap(&boulderExplodeBmp4);
		_boulderExplodeBmp5 = createMutableBitmap(&boulderExplodeBmp5);
		_boulderExplodeBmp6 = createMutableBitmap(&boulderExplodeBmp6);
		_boulderExplodeBmp7 = createMutableBitmap(&boulderExplodeBmp7);
		_soilBmp = createMutableBitmap(&soilBmp);
	};

	static void makeSoilWhite() {
		swapColours(COLOUR_BLUE, COLOUR_WHITE, _soilBmp);
		swapColours(COLOUR_BLUE_DARK, COLOUR_WHITE_DARK, _soilBmp);
	};

	static void makeSoilRed() {
		swapColours(COLOUR_BLUE, COLOUR_RED, _soilBmp);
		swapColours(COLOUR_BLUE_DARK, COLOUR_RED_DARK, _soilBmp);
	};

	static void makeSoilGreen() {
		swapColours(COLOUR_BLUE, COLOUR_GREEN, _soilBmp);
		swapColours(COLOUR_BLUE_DARK, COLOUR_GREEN_DARK, _soilBmp);
	};

	static void makeSoilCyan() {
		swapColours(COLOUR_BLUE, COLOUR_CYAN, _soilBmp);
		swapColours(COLOUR_BLUE_DARK, COLOUR_CYAN_DARK, _soilBmp);
	};

	static void makeSoilMagenta() {
		swapColours(COLOUR_BLUE, COLOUR_MAGENTA, _soilBmp);
		swapColours(COLOUR_BLUE_DARK, COLOUR_MAGENTA_DARK, _soilBmp);
	};

	static void makeBouldersBlue() {
		changeBoulderColours(COLOUR_BLUE, COLOUR_BLUE_DARK);
	};

	static void makeBouldersCyan() {
		changeBoulderColours(COLOUR_CYAN, COLOUR_CYAN_DARK);
	};

	static void makeBouldersRed() {
		changeBoulderColours(COLOUR_RED, COLOUR_RED_DARK);
	};

	static void makeBouldersMaganta() {
		changeBoulderColours(COLOUR_MAGENTA, COLOUR_MAGENTA_DARK);
	};

	static void makeBouldersGreen() {
		changeBoulderColours(COLOUR_GREEN, COLOUR_GREEN_DARK);
	};

	static void shutdown() {
		delete _boulderBmp;
		delete _boulderExplodeBmp1;
		delete _boulderExplodeBmp2;
		delete _boulderExplodeBmp3;
		delete _boulderExplodeBmp4;
		delete _boulderExplodeBmp5;
		delete _boulderExplodeBmp6;
		delete _boulderExplodeBmp7;
	};

	inline static WoopsiGfx::Bitmap* getBoulderBmp() {
		return _boulderBmp;
	};

	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp1() {
		return _boulderExplodeBmp1;
	};

	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp2() {
		return _boulderExplodeBmp2;
	};

	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp3() {
		return _boulderExplodeBmp3;
	};

	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp4() {
		return _boulderExplodeBmp4;
	};

	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp5() {
		return _boulderExplodeBmp5;
	};

	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp6() {
		return _boulderExplodeBmp6;
	};

	inline static WoopsiGfx::Bitmap* getBoulderExplodeBmp7() {
		return _boulderExplodeBmp7;
	};

	inline static WoopsiGfx::Bitmap* getSoilBmp() {
		return _soilBmp;
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
	static WoopsiGfx::Bitmap* _soilBmp;

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
		swapColours(COLOUR_YELLOW, light, _boulderBmp);
		swapColours(COLOUR_YELLOW_DARK, dark, _boulderBmp);

		swapColours(COLOUR_YELLOW, light, _boulderExplodeBmp1);
		swapColours(COLOUR_YELLOW_DARK, dark, _boulderExplodeBmp1);

		swapColours(COLOUR_YELLOW, light, _boulderExplodeBmp2);
		swapColours(COLOUR_YELLOW_DARK, dark, _boulderExplodeBmp2);

		swapColours(COLOUR_YELLOW, light, _boulderExplodeBmp3);
		swapColours(COLOUR_YELLOW_DARK, dark, _boulderExplodeBmp3);

		swapColours(COLOUR_YELLOW, light, _boulderExplodeBmp4);
		swapColours(COLOUR_YELLOW_DARK, dark, _boulderExplodeBmp4);

		swapColours(COLOUR_YELLOW, light, _boulderExplodeBmp5);
		swapColours(COLOUR_YELLOW_DARK, dark, _boulderExplodeBmp5);

		swapColours(COLOUR_YELLOW, light, _boulderExplodeBmp6);
		swapColours(COLOUR_YELLOW_DARK, dark, _boulderExplodeBmp6);

		swapColours(COLOUR_YELLOW, light, _boulderExplodeBmp7);
		swapColours(COLOUR_YELLOW_DARK, dark, _boulderExplodeBmp7);
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
