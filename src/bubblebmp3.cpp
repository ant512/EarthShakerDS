#include <nds.h>
#include "bubblebmp3.h"

using namespace WoopsiUI;

static const u16 bubblebmp3_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 65513, 
65513, 65513, 37863, 37863, 37863, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 65513, 65513, 32768, 32768, 32768, 32768, 32768, 32768, 37863, 
37863, 32768, 32768, 32768, 32768, 32768, 65513, 32768, 32768, 32768, 65513, 
65513, 37863, 32768, 32768, 32768, 32768, 37863, 32768, 32768, 32768, 65513, 
32768, 32768, 65513, 65513, 65513, 65513, 37863, 32768, 32768, 32768, 32768, 
32768, 37863, 32768, 32768, 65513, 32768, 65513, 65513, 65513, 65513, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 37863, 32768, 65513, 32768, 32768, 
65513, 65513, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 37863, 65513, 32768, 65513, 65513, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 37863, 64575, 32768, 64575, 64575, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
39935, 64575, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 39935, 32768, 64575, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 39935, 32768, 
32768, 64575, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 39935, 32768, 32768, 32768, 64575, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 39935, 32768, 32768, 32768, 
32768, 32768, 64575, 64575, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
39935, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 64575, 64575, 
32768, 39935, 32768, 39935, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768
};

BubbleBmp3::BubbleBmp3() : BitmapWrapper(bubblebmp3_Bitmap, 16, 16) { };