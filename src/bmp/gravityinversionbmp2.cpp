#include <nds.h>
#include "gravityinversionbmp2.h"

static const u16 gravityinversionbmp2_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 65504, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 65504, 65504, 59168, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 65504, 65504, 
32768, 59168, 59168, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 65504, 65504, 32768, 65504, 32768, 59168, 59168, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 65504, 65504, 
59168, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 65504, 65504, 65504, 59168, 59168, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 65504, 65504, 65504, 65504, 59168, 
59168, 59168, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 65504, 65504, 59168, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 65504, 65504, 59168, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 65504, 65504, 59168, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 65504, 65504, 59168, 32768, 59168, 
59168, 59168, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
65504, 65504, 59168, 32768, 59168, 59168, 59168, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 65504, 65504, 59168, 59168, 59168, 59168, 
59168, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 65504, 
65504, 59168, 59168, 59168, 59168, 59168, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 65504, 59168, 59168, 59168, 59168, 32768, 
32768, 32768, 32768
};

GravityInversionBmp2::GravityInversionBmp2() : WoopsiGfx::BitmapWrapper(gravityinversionbmp2_Bitmap, 16, 16) { };