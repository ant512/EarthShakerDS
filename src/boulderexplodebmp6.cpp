#include <nds.h>
#include "boulderexplodebmp6.h"

static const u16 boulderexplodebmp6_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 37722, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 39935, 32768, 
39935, 32768, 32768, 32768, 32768, 32768, 37722, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 39935, 32768, 37722, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 39935, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 37722, 32768, 39935, 32768, 
39935, 32768, 39935, 32768, 32768, 39935, 32768, 32768, 32768, 37722, 32768, 
37722, 32768, 32768
};

BoulderExplodeBmp6::BoulderExplodeBmp6() : WoopsiGfx::BitmapWrapper(boulderexplodebmp6_Bitmap, 16, 16) { };