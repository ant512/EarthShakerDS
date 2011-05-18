#include <nds.h>
#include "soilmapbmp.h"

static const u16 soilmapbmp_Bitmap[64] __attribute__ ((aligned (4))) = {
64512, 32768, 32768, 32768, 32768, 32768, 64512, 32768, 64512, 32768, 64512, 
64512, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 64512, 
64512, 32768, 32768, 64512, 32768, 64512, 64512, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 64512, 64512, 32768, 64512, 32768, 64512, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 64512, 
32768, 32768, 64512, 32768, 32768, 64512, 32768, 32768, 32768
};

SoilMapBmp::SoilMapBmp() : WoopsiGfx::BitmapWrapper(soilmapbmp_Bitmap, 8, 8) { };