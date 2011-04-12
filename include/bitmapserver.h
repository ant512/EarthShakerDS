#ifndef _BITMAP_SERVER_H_
#define _BITMAP_SERVER_H_

#include <bitmap.h>
#include <graphics.h>
#include <bitmapbase.h>
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

enum SpectrumColour {
	COLOUR_YELLOW = 39935,
	COLOUR_YELLOW_DARK = 37722,
	COLOUR_CYAN = 65513,
	COLOUR_CYAN_DARK = 60229
};

class BitmapServer {
public:
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

		BoulderBmp boulderBmp;
		BoulderExplodeBmp1 boulderExplodeBmp1;
		BoulderExplodeBmp2 boulderExplodeBmp2;
		BoulderExplodeBmp3 boulderExplodeBmp3;
		BoulderExplodeBmp4 boulderExplodeBmp4;
		BoulderExplodeBmp5 boulderExplodeBmp5;
		BoulderExplodeBmp6 boulderExplodeBmp6;
		BoulderExplodeBmp7 boulderExplodeBmp7;

		_boulderBmp = createMutableBitmap(&boulderBmp);
		_boulderExplodeBmp1 = createMutableBitmap(&boulderExplodeBmp1);
		_boulderExplodeBmp2 = createMutableBitmap(&boulderExplodeBmp2);
		_boulderExplodeBmp3 = createMutableBitmap(&boulderExplodeBmp3);
		_boulderExplodeBmp4 = createMutableBitmap(&boulderExplodeBmp4);
		_boulderExplodeBmp5 = createMutableBitmap(&boulderExplodeBmp5);
		_boulderExplodeBmp6 = createMutableBitmap(&boulderExplodeBmp6);
		_boulderExplodeBmp7 = createMutableBitmap(&boulderExplodeBmp7);

		makeBouldersBlue();
	};

	static void makeBouldersBlue() {
		swapColours(COLOUR_YELLOW, COLOUR_CYAN, _boulderBmp);
		swapColours(COLOUR_YELLOW_DARK, COLOUR_CYAN_DARK, _boulderBmp);

		swapColours(COLOUR_YELLOW, COLOUR_CYAN, _boulderExplodeBmp1);
		swapColours(COLOUR_YELLOW_DARK, COLOUR_CYAN_DARK, _boulderExplodeBmp1);

		swapColours(COLOUR_YELLOW, COLOUR_CYAN, _boulderExplodeBmp2);
		swapColours(COLOUR_YELLOW_DARK, COLOUR_CYAN_DARK, _boulderExplodeBmp2);

		swapColours(COLOUR_YELLOW, COLOUR_CYAN, _boulderExplodeBmp3);
		swapColours(COLOUR_YELLOW_DARK, COLOUR_CYAN_DARK, _boulderExplodeBmp3);

		swapColours(COLOUR_YELLOW, COLOUR_CYAN, _boulderExplodeBmp4);
		swapColours(COLOUR_YELLOW_DARK, COLOUR_CYAN_DARK, _boulderExplodeBmp4);

		swapColours(COLOUR_YELLOW, COLOUR_CYAN, _boulderExplodeBmp5);
		swapColours(COLOUR_YELLOW_DARK, COLOUR_CYAN_DARK, _boulderExplodeBmp5);

		swapColours(COLOUR_YELLOW, COLOUR_CYAN, _boulderExplodeBmp6);
		swapColours(COLOUR_YELLOW_DARK, COLOUR_CYAN_DARK, _boulderExplodeBmp6);

		swapColours(COLOUR_YELLOW, COLOUR_CYAN, _boulderExplodeBmp7);
		swapColours(COLOUR_YELLOW_DARK, COLOUR_CYAN_DARK, _boulderExplodeBmp7);
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

	static void swapColours(SpectrumColour source, SpectrumColour dest, WoopsiGfx::Bitmap* bitmap) {
		for (s32 x = 0; x < bitmap->getWidth(); ++x) {
			for (s32 y = 0; y < bitmap->getHeight(); ++y) {
				if (bitmap->getPixel(x, y) == (u16)source) bitmap->setPixel(x, y, (u16)dest);
			}
		}
	};

	static WoopsiGfx::Bitmap* createMutableBitmap(WoopsiGfx::BitmapBase* source) {
		WoopsiGfx::Bitmap* dest = new WoopsiGfx::Bitmap(source->getWidth(), source->getHeight());

		WoopsiGfx::Graphics* gfx = dest->newGraphics();
		gfx->drawBitmap(0, 0, source->getWidth(), source->getHeight(), source, 0, 0);
		delete gfx;

		return dest;
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

private:
	static WoopsiGfx::Bitmap* _boulderBmp;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp1;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp2;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp3;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp4;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp5;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp6;
	static WoopsiGfx::Bitmap* _boulderExplodeBmp7;
};

#endif
