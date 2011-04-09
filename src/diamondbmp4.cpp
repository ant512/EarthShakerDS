#include <nds.h>
#include "diamondbmp4.h"

using namespace WoopsiUI;

static const u16 diamondbmp4_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 32768, 32768, 39935, 65513, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 39935, 
32768, 39935, 65513, 32768, 65513, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 39935, 32768, 39935, 39935, 65513, 65513, 32768, 65513, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 39935, 39935, 32768, 39935, 
39935, 65513, 65513, 32768, 65513, 65513, 32768, 32768, 32768, 32768, 32768, 
39935, 39935, 32768, 39935, 39935, 39935, 65513, 65513, 65513, 32768, 65513, 
65513, 32768, 32768, 32768, 39935, 32768, 39935, 32768, 39935, 39935, 39935, 
65513, 65513, 65513, 32768, 65513, 32768, 65513, 32768, 32768, 39935, 39935, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 65513, 
65513, 32768, 32768, 32768, 39935, 39935, 32768, 39935, 39935, 39935, 65513, 
65513, 65513, 32768, 65513, 65513, 32768, 32768, 32768, 65513, 32768, 65513, 
32768, 65513, 65513, 65513, 37863, 37863, 37863, 32768, 37863, 32768, 37863, 
32768, 32768, 32768, 65513, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 37863, 32768, 32768, 32768, 32768, 65513, 65513, 32768, 
65513, 65513, 65513, 37863, 37863, 37863, 32768, 37863, 37863, 32768, 32768, 
32768, 32768, 32768, 65513, 32768, 65513, 65513, 65513, 37863, 37863, 37863, 
32768, 37863, 32768, 32768, 32768, 32768, 32768, 32768, 65513, 65513, 32768, 
65513, 65513, 37863, 37863, 32768, 37863, 37863, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 65513, 32768, 65513, 65513, 37863, 37863, 32768, 37863, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 65513, 32768, 
65513, 37863, 32768, 37863, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 65513, 37863, 32768, 32768, 32768, 32768, 
32768, 32768, 32768
};

DiamondBmp4::DiamondBmp4() : BitmapWrapper(diamondbmp4_Bitmap, 16, 16) { };