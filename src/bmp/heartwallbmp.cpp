#include <nds.h>
#include "heartwallbmp.h"

static const u16 heartwallbmp_Bitmap[256] __attribute__ ((aligned (4))) = {
33791, 32768, 32768, 32768, 32768, 32768, 33791, 33791, 33791, 32768, 32768, 
32768, 32768, 32768, 33791, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 33791, 32768, 32768, 33791, 32768, 33791, 32768, 32768, 32768, 32768, 
33791, 33791, 32768, 33791, 33791, 32768, 32768, 32768, 33791, 33791, 33791, 
33791, 33791, 32768, 32768, 33791, 33791, 33791, 33791, 33791, 33791, 33791, 
32768, 32768, 32768, 33791, 33791, 33791, 32768, 32768, 32768, 33791, 33791, 
33791, 33791, 33791, 33791, 33791, 32768, 32768, 32768, 32768, 33791, 32768, 
32768, 32768, 32768, 32768, 33791, 33791, 33791, 33791, 33791, 32768, 32768, 
33791, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 33791, 
33791, 33791, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 33791, 
32768, 33791, 33791, 32768, 32768, 33791, 32768, 32768, 33791, 33791, 32768, 
33791, 33791, 32768, 33791, 33791, 33791, 33791, 32768, 32768, 32768, 32768, 
32768, 33791, 33791, 33791, 33791, 33791, 33791, 33791, 32768, 33791, 33791, 
33791, 32768, 32768, 32768, 32768, 32768, 33791, 33791, 33791, 33791, 33791, 
33791, 33791, 32768, 32768, 33791, 32768, 32768, 33791, 32768, 33791, 32768, 
32768, 33791, 33791, 33791, 33791, 33791, 32768, 32768, 32768, 32768, 32768, 
33791, 33791, 33791, 33791, 33791, 32768, 32768, 33791, 33791, 33791, 32768, 
32768, 32768, 32768, 32768, 32768, 33791, 33791, 33791, 33791, 33791, 32768, 
32768, 32768, 33791, 32768, 32768, 33791, 32768, 33791, 32768, 32768, 32768, 
33791, 33791, 33791, 32768, 32768, 32768, 32768, 32768, 32768, 33791, 33791, 
33791, 33791, 33791, 32768, 32768, 32768, 33791, 32768, 32768, 32768, 33791, 
32768, 33791, 32768, 32768, 33791, 33791, 33791, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 33791, 33791, 33791, 33791, 33791, 32768, 32768, 33791, 
32768, 32768, 32768
};

HeartWallBmp::HeartWallBmp() : WoopsiGfx::BitmapWrapper(heartwallbmp_Bitmap, 16, 16) { };