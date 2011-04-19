#include <nds.h>
#include "barrierbmp4.h"

static const u16 barrierbmp4_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 39935, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 39935, 39935, 32768, 39935, 39935, 32768, 32768, 32768, 
39935, 39935, 32768, 32768, 32768, 32768, 32768, 39935, 39935, 39935, 39935, 
39935, 39935, 39935, 32768, 32768, 39935, 39935, 32768, 32768, 32768, 32768, 
32768, 39935, 39935, 39935, 39935, 39935, 39935, 39935, 32768, 32768, 39935, 
39935, 32768, 32768, 32768, 32768, 32768, 39935, 39935, 39935, 39935, 39935, 
39935, 39935, 32768, 32768, 39935, 39935, 32768, 32768, 32768, 32768, 39935, 
39935, 39935, 39935, 39935, 39935, 39935, 39935, 32768, 32768, 39935, 39935, 
39935, 32768, 32768, 32768, 39935, 39935, 39935, 39935, 32768, 39935, 39935, 
39935, 39935, 32768, 39935, 39935, 39935, 32768, 32768, 32768, 39935, 39935, 
39935, 39935, 32768, 32768, 39935, 39935, 39935, 32768, 39935, 39935, 39935, 
32768, 32768, 39935, 39935, 39935, 39935, 39935, 32768, 32768, 39935, 39935, 
39935, 32768, 39935, 39935, 39935, 32768, 32768, 39935, 39935, 39935, 39935, 
32768, 32768, 32768, 39935, 39935, 39935, 32768, 39935, 39935, 39935, 39935, 
32768, 39935, 39935, 39935, 39935, 32768, 32768, 32768, 39935, 39935, 39935, 
32768, 32768, 39935, 39935, 39935, 39935, 39935, 39935, 39935, 39935, 32768, 
32768, 32768, 32768, 39935, 39935, 32768, 32768, 39935, 39935, 39935, 39935, 
39935, 39935, 39935, 32768, 32768, 32768, 32768, 32768, 39935, 39935, 32768, 
32768, 39935, 39935, 39935, 39935, 39935, 39935, 39935, 32768, 32768, 32768, 
32768, 32768, 39935, 39935, 32768, 32768, 39935, 39935, 39935, 39935, 39935, 
39935, 39935, 32768, 32768, 32768, 32768, 32768, 39935, 39935, 32768, 32768, 
32768, 39935, 39935, 32768, 39935, 39935, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 39935
};

BarrierBmp4::BarrierBmp4() : WoopsiGfx::BitmapWrapper(barrierbmp4_Bitmap, 16, 16) { };