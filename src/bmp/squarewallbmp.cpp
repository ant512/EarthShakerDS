#include <nds.h>
#include "squarewallbmp.h"

static const u16 squarewallbmp_Bitmap[256] __attribute__ ((aligned (4))) = {
60250, 60250, 60250, 60250, 60250, 60250, 60250, 32768, 60250, 60250, 60250, 
60250, 60250, 60250, 60250, 32768, 60250, 60250, 60250, 60250, 60250, 60250, 
32768, 32768, 60250, 60250, 60250, 60250, 60250, 60250, 32768, 32768, 60250, 
60250, 60250, 60250, 60250, 60250, 60250, 32768, 60250, 60250, 60250, 60250, 
60250, 60250, 60250, 32768, 60250, 60250, 60250, 60250, 60250, 60250, 32768, 
32768, 60250, 60250, 60250, 60250, 60250, 60250, 32768, 32768, 60250, 60250, 
60250, 60250, 60250, 60250, 60250, 32768, 60250, 60250, 60250, 60250, 60250, 
60250, 60250, 32768, 60250, 60250, 60250, 60250, 60250, 60250, 32768, 32768, 
60250, 60250, 60250, 60250, 60250, 60250, 32768, 32768, 60250, 32768, 60250, 
32768, 60250, 32768, 60250, 32768, 60250, 32768, 60250, 32768, 60250, 32768, 
60250, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 60250, 60250, 60250, 60250, 
60250, 60250, 60250, 32768, 60250, 60250, 60250, 60250, 60250, 60250, 60250, 
32768, 60250, 60250, 60250, 60250, 60250, 60250, 32768, 32768, 60250, 60250, 
60250, 60250, 60250, 60250, 32768, 32768, 60250, 60250, 60250, 60250, 60250, 
60250, 60250, 32768, 60250, 60250, 60250, 60250, 60250, 60250, 60250, 32768, 
60250, 60250, 60250, 60250, 60250, 60250, 32768, 32768, 60250, 60250, 60250, 
60250, 60250, 60250, 32768, 32768, 60250, 60250, 60250, 60250, 60250, 60250, 
60250, 32768, 60250, 60250, 60250, 60250, 60250, 60250, 60250, 32768, 60250, 
60250, 60250, 60250, 60250, 60250, 32768, 32768, 60250, 60250, 60250, 60250, 
60250, 60250, 32768, 32768, 60250, 32768, 60250, 32768, 60250, 32768, 60250, 
32768, 60250, 32768, 60250, 32768, 60250, 32768, 60250, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768
};

SquareWallBmp::SquareWallBmp() : WoopsiGfx::BitmapWrapper(squarewallbmp_Bitmap, 16, 16) { };