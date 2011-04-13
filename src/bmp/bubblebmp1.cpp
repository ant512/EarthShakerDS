#include <nds.h>
#include "bubblebmp1.h"

static const u16 bubblebmp1_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 32768, 33791, 33791, 64799, 64799, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 33791, 33791, 
32768, 32768, 32768, 32768, 64767, 64767, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 33791, 32768, 32768, 32768, 33791, 64767, 32768, 32768, 32768, 
64767, 32768, 32768, 32768, 32768, 32768, 33791, 32768, 32768, 33791, 33791, 
33791, 64799, 32768, 32768, 32768, 32768, 64799, 32768, 32768, 32768, 32768, 
33791, 32768, 33791, 33791, 33791, 32768, 32768, 32768, 32768, 32768, 32768, 
64799, 32768, 32768, 32768, 33791, 32768, 32768, 33791, 33791, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 64767, 32768, 32768, 33791, 32768, 
33791, 33791, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
64799, 32768, 32768, 33791, 32768, 33791, 33791, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 64767, 32768, 32768, 33760, 32768, 33760, 
33760, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 65504, 
32768, 32768, 33760, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 65504, 32768, 32768, 33760, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 65504, 32768, 
32768, 32768, 33760, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 65504, 32768, 32768, 32768, 32768, 33760, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 65504, 32768, 32768, 32768, 
32768, 32768, 33760, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
65504, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 33760, 33760, 32768, 
32768, 32768, 32768, 32768, 65504, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 33760, 33760, 32768, 65504, 32768, 32768, 32768, 
32768, 32768, 32768
};

BubbleBmp1::BubbleBmp1() : WoopsiGfx::BitmapWrapper(bubblebmp1_Bitmap, 16, 16) { };