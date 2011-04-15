#include <nds.h>
#include "barrierbmp2.h"

static const u16 barrierbmp2_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 33791, 33791, 32768, 33791, 33791, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 33791, 32768, 32768, 33791, 33791, 33791, 33791, 
33791, 33791, 33791, 32768, 32768, 32768, 32768, 32768, 33791, 33791, 32768, 
32768, 33791, 33791, 33791, 33791, 33791, 33791, 33791, 32768, 32768, 32768, 
32768, 32768, 33791, 33791, 32768, 32768, 33791, 33791, 33791, 33791, 33791, 
33791, 33791, 32768, 32768, 32768, 32768, 32768, 33791, 33791, 32768, 32768, 
33791, 33791, 33791, 33791, 33791, 33791, 33791, 33791, 32768, 32768, 32768, 
32768, 33791, 33791, 32768, 33791, 33791, 33791, 33791, 32768, 33791, 33791, 
33791, 33791, 32768, 32768, 32768, 33791, 33791, 33791, 32768, 33791, 33791, 
33791, 32768, 32768, 33791, 33791, 33791, 33791, 32768, 32768, 32768, 33791, 
33791, 33791, 32768, 33791, 33791, 33791, 32768, 32768, 33791, 33791, 33791, 
33791, 33791, 32768, 32768, 33791, 33791, 33791, 32768, 33791, 33791, 33791, 
32768, 32768, 32768, 33791, 33791, 33791, 33791, 32768, 32768, 33791, 33791, 
33791, 32768, 33791, 33791, 33791, 32768, 32768, 32768, 33791, 33791, 33791, 
33791, 32768, 33791, 33791, 33791, 33791, 32768, 33791, 33791, 32768, 32768, 
32768, 32768, 33791, 33791, 33791, 33791, 33791, 33791, 33791, 33791, 32768, 
32768, 33791, 33791, 32768, 32768, 32768, 32768, 32768, 33791, 33791, 33791, 
33791, 33791, 33791, 33791, 32768, 32768, 33791, 33791, 32768, 32768, 32768, 
32768, 32768, 33791, 33791, 33791, 33791, 33791, 33791, 33791, 32768, 32768, 
33791, 33791, 32768, 32768, 32768, 32768, 32768, 33791, 33791, 33791, 33791, 
33791, 33791, 33791, 32768, 32768, 33791, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 33791, 33791, 32768, 33791, 33791, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768
};

BarrierBmp2::BarrierBmp2() : WoopsiGfx::BitmapWrapper(barrierbmp2_Bitmap, 16, 16) { };