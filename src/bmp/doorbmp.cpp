#include <nds.h>
#include "doorbmp.h"

static const u16 doorbmp_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 65535, 65535, 65535, 32768, 65535, 65535, 59193, 32768, 59193, 
59193, 59193, 32768, 32768, 32768, 32768, 32768, 65535, 65535, 65535, 32768, 
65535, 65535, 59193, 32768, 32768, 32768, 32768, 59193, 59193, 32768, 32768, 
32768, 65535, 65535, 65535, 32768, 32768, 32768, 32768, 59193, 59193, 59193, 
59193, 59193, 59193, 32768, 32768, 32768, 65535, 65535, 65535, 32768, 65535, 
65535, 59193, 59193, 59193, 59193, 59193, 59193, 59193, 32768, 32768, 32768, 
32768, 32768, 65535, 32768, 32768, 32768, 32768, 59193, 59193, 59193, 59193, 
59193, 59193, 32768, 32768, 32768, 65535, 65535, 32768, 32768, 65535, 65535, 
59193, 32768, 32768, 32768, 32768, 59193, 59193, 32768, 32768, 65535, 32768, 
65535, 65535, 32768, 65535, 65535, 59193, 32768, 59193, 59193, 59193, 32768, 
32768, 32768, 32768, 65535, 65535, 65535, 65535, 32768, 65535, 65535, 59193, 
32768, 59193, 59193, 59193, 32768, 32768, 32768, 32768, 32768, 65535, 65535, 
32768, 32768, 65535, 65535, 59193, 32768, 59193, 59193, 59193, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 65535, 32768, 65535, 65535, 59193, 32768, 
59193, 59193, 59193, 32768, 32768, 32768, 32768, 32768, 65535, 65535, 65535, 
32768, 65535, 65535, 59193, 32768, 32768, 32768, 32768, 59193, 59193, 32768, 
32768, 32768, 65535, 65535, 65535, 32768, 32768, 32768, 32768, 59193, 59193, 
59193, 59193, 59193, 59193, 32768, 32768, 32768, 65535, 65535, 65535, 32768, 
65535, 65535, 59193, 59193, 59193, 59193, 59193, 59193, 59193, 32768, 32768, 
32768, 65535, 65535, 65535, 32768, 32768, 32768, 32768, 59193, 59193, 59193, 
59193, 59193, 59193, 32768, 32768, 32768, 65535, 65535, 65535, 32768, 65535, 
65535, 59193, 32768, 32768, 32768, 32768, 59193, 59193, 32768, 32768, 32768, 
65535, 65535, 65535, 32768, 65535, 65535, 59193, 32768, 59193, 59193, 59193, 
32768, 32768, 32768
};

DoorBmp::DoorBmp() : WoopsiGfx::BitmapWrapper(doorbmp_Bitmap, 16, 16) { };