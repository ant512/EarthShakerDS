#include <nds.h>
#include "extralifemapbmp.h"

static const u16 extralifemapbmp_Bitmap[64] __attribute__ ((aligned (4))) = {
32768, 33791, 32768, 32768, 32768, 32768, 33791, 32768, 32768, 32768, 33791, 
32768, 32768, 33791, 32768, 32768, 32768, 32768, 33791, 32768, 32768, 33791, 
32768, 32768, 32768, 32768, 33791, 32768, 32768, 33791, 32768, 32768, 32768, 
33791, 32768, 33791, 33791, 32768, 33791, 32768, 33791, 32768, 33791, 33791, 
33791, 33791, 32768, 33791, 33791, 32768, 32768, 32768, 32768, 32768, 32768, 
33791, 32768, 33791, 33791, 33791, 33791, 33791, 33791, 32768
};

ExtraLifeMapBmp::ExtraLifeMapBmp() : WoopsiGfx::BitmapWrapper(extralifemapbmp_Bitmap, 8, 8) { };