#include <nds.h>
#include "boulderbmp.h"

static const u16 boulderbmp_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 39935, 39935, 39935, 39935, 37722, 37722, 37722, 
37722, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 39935, 39935, 39935, 
39935, 39935, 37722, 37722, 37722, 37722, 37722, 32768, 32768, 32768, 32768, 
32768, 39935, 39935, 39935, 39935, 39935, 39935, 37722, 37722, 37722, 37722, 
37722, 37722, 32768, 32768, 32768, 39935, 39935, 39935, 39935, 39935, 39935, 
39935, 37722, 37722, 37722, 37722, 37722, 37722, 32768, 32768, 32768, 39935, 
39935, 39935, 39935, 39935, 39935, 39935, 37722, 37722, 37722, 37722, 37722, 
32768, 37722, 32768, 39935, 39935, 39935, 39935, 39935, 39935, 39935, 39935, 
37722, 37722, 37722, 37722, 32768, 37722, 32768, 37722, 39935, 39935, 39935, 
39935, 39935, 39935, 39935, 39935, 37722, 37722, 37722, 32768, 37722, 32768, 
37722, 32768, 39935, 39935, 39935, 39935, 39935, 39935, 39935, 39935, 32768, 
37722, 32768, 37722, 32768, 37722, 32768, 37722, 39935, 39935, 39935, 39935, 
39935, 39935, 39935, 32768, 37722, 32768, 37722, 32768, 37722, 32768, 37722, 
32768, 39935, 39935, 39935, 39935, 39935, 39935, 32768, 39935, 32768, 37722, 
32768, 37722, 32768, 37722, 32768, 37722, 32768, 39935, 39935, 32768, 39935, 
32768, 39935, 32768, 37722, 32768, 37722, 32768, 37722, 32768, 37722, 32768, 
32768, 39935, 32768, 39935, 32768, 39935, 32768, 39935, 32768, 37722, 32768, 
37722, 32768, 37722, 32768, 32768, 32768, 32768, 39935, 32768, 39935, 32768, 
39935, 32768, 37722, 32768, 37722, 32768, 37722, 32768, 37722, 32768, 32768, 
32768, 32768, 39935, 32768, 39935, 32768, 39935, 32768, 37722, 32768, 37722, 
32768, 37722, 32768, 32768, 32768, 32768, 32768, 32768, 39935, 32768, 39935, 
32768, 37722, 32768, 37722, 32768, 37722, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 39935, 32768, 39935, 32768, 37722, 32768, 37722, 32768, 
32768, 32768, 32768
};

BoulderBmp::BoulderBmp() : WoopsiGfx::BitmapWrapper(boulderbmp_Bitmap, 16, 16) { };