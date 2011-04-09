#include <nds.h>
#include "bubblebmp4.h"

using namespace WoopsiUI;

static const u16 bubblebmp4_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 64575, 64575, 64575, 65513, 65513, 65513, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 64575, 64575, 32768, 
32768, 32768, 32768, 32768, 32768, 65513, 65513, 32768, 32768, 32768, 32768, 
32768, 64575, 32768, 32768, 32768, 64575, 64575, 65513, 32768, 32768, 32768, 
32768, 65513, 32768, 32768, 32768, 64575, 32768, 32768, 64575, 64575, 64575, 
64575, 65513, 32768, 32768, 32768, 32768, 32768, 65513, 32768, 32768, 64575, 
32768, 64575, 64575, 64575, 64575, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 65513, 32768, 64575, 32768, 32768, 64575, 64575, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 65513, 64575, 32768, 64575, 
64575, 64575, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 65513, 64575, 32768, 64575, 64575, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 65513, 39935, 32768, 39935, 39935, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
37863, 39935, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 37863, 39935, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 37863, 
32768, 39935, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 37863, 32768, 32768, 39935, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 37863, 32768, 32768, 
32768, 39935, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 37863, 32768, 32768, 32768, 32768, 32768, 39935, 39935, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 37863, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 39935, 39935, 32768, 37863, 32768, 37863, 32768, 32768, 
32768, 32768, 32768
};

BubbleBmp4::BubbleBmp4() : BitmapWrapper(bubblebmp4_Bitmap, 16, 16) { };