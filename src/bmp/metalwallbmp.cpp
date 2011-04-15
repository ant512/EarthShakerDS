#include <nds.h>
#include "metalwallbmp.h"

static const u16 metalwallbmp_Bitmap[256] __attribute__ ((aligned (4))) = {
33568, 33568, 32768, 33568, 32768, 33568, 33568, 33568, 33568, 33568, 32768, 
33568, 32768, 33568, 33568, 32768, 33568, 32768, 32768, 32768, 33568, 33568, 
33568, 33568, 33568, 32768, 33568, 32768, 32768, 32768, 33568, 32768, 32768, 
32768, 33568, 32768, 33568, 33568, 33568, 33568, 32768, 33568, 32768, 32768, 
33568, 32768, 33568, 32768, 33568, 32768, 32768, 33568, 33568, 33568, 33568, 
32768, 33568, 32768, 33568, 32768, 32768, 33568, 33568, 32768, 32768, 33568, 
33568, 33568, 33568, 33568, 32768, 33568, 32768, 33568, 33568, 33568, 33568, 
33568, 32768, 32768, 33568, 33568, 33568, 33568, 33568, 32768, 33568, 32768, 
33568, 33568, 33568, 33568, 33568, 32768, 33568, 32768, 33568, 33568, 33568, 
33568, 32768, 33568, 32768, 33568, 33568, 33568, 33568, 33568, 32768, 33568, 
32768, 32768, 33568, 33568, 33568, 32768, 33568, 32768, 33568, 33568, 33568, 
33568, 33568, 32768, 33568, 32768, 33568, 32768, 33568, 33568, 32768, 33568, 
32768, 33568, 33568, 33568, 33568, 33568, 32768, 33568, 32768, 33568, 33568, 
32768, 33568, 32768, 33568, 32768, 33568, 33568, 33568, 33568, 33568, 32768, 
33568, 32768, 33568, 33568, 33568, 32768, 32768, 33568, 32768, 33568, 33568, 
33568, 33568, 33568, 32768, 33568, 32768, 33568, 33568, 33568, 33568, 32768, 
33568, 32768, 32768, 32768, 33568, 33568, 33568, 32768, 33568, 32768, 33568, 
33568, 32768, 32768, 33568, 32768, 32768, 32768, 33568, 32768, 33568, 33568, 
32768, 33568, 32768, 33568, 33568, 32768, 33568, 32768, 33568, 32768, 33568, 
32768, 32768, 33568, 33568, 32768, 33568, 32768, 33568, 33568, 33568, 32768, 
32768, 33568, 33568, 32768, 33568, 33568, 33568, 33568, 32768, 33568, 32768, 
33568, 33568, 33568, 33568, 33568, 33568, 33568, 33568, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768
};

MetalWallBmp::MetalWallBmp() : WoopsiGfx::BitmapWrapper(metalwallbmp_Bitmap, 16, 16) { };