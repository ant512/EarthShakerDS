#include <nds.h>
#include "diamondbmp1.h"

static const u16 diamondbmp1_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 32768, 32768, 64543, 32799, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 64543, 
32768, 64543, 32799, 32768, 32799, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 64543, 32768, 64543, 64543, 32799, 32799, 32768, 32799, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 64543, 64543, 32768, 64543, 
64543, 32799, 32799, 32768, 32799, 32799, 32768, 32768, 32768, 32768, 32768, 
64543, 64543, 32768, 64543, 64543, 64543, 32799, 32799, 32799, 32768, 32799, 
32799, 32768, 32768, 32768, 64543, 32768, 64543, 32768, 64543, 64543, 64543, 
32799, 32799, 32799, 32768, 32799, 32768, 32799, 32768, 32768, 64543, 64543, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32799, 
32799, 32768, 32768, 32768, 64543, 64543, 32768, 64543, 64543, 64543, 32799, 
32799, 32799, 32768, 32799, 32799, 32768, 32768, 32768, 32799, 32768, 32799, 
32768, 32799, 32799, 32799, 64512, 64512, 64512, 32768, 64512, 32768, 64512, 
32768, 32768, 32768, 32799, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 64512, 32768, 32768, 32768, 32768, 32799, 32799, 32768, 
32799, 32799, 32799, 64512, 64512, 64512, 32768, 64512, 64512, 32768, 32768, 
32768, 32768, 32768, 32799, 32768, 32799, 32799, 32799, 64512, 64512, 64512, 
32768, 64512, 32768, 32768, 32768, 32768, 32768, 32768, 32799, 32799, 32768, 
32799, 32799, 64512, 64512, 32768, 64512, 64512, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32799, 32768, 32799, 32799, 64512, 64512, 32768, 64512, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32799, 32768, 
32799, 64512, 32768, 64512, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32799, 64512, 32768, 32768, 32768, 32768, 
32768, 32768, 32768
};

DiamondBmp1::DiamondBmp1() : WoopsiGfx::BitmapWrapper(diamondbmp1_Bitmap, 16, 16) { };