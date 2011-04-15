#include <nds.h>
#include "teleportbmp2.h"

static const u16 teleportbmp2_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 64543, 64543, 64543, 64543, 58393, 58393, 58393, 58393, 
58393, 32768, 32768, 32768, 32768, 32768, 32768, 64543, 64543, 32768, 32768, 
32768, 58393, 58393, 32768, 58393, 58393, 58393, 32768, 32768, 32768, 32768, 
32768, 64543, 32768, 64543, 32768, 32768, 58393, 32768, 32768, 32768, 32768, 
58393, 32768, 32768, 32768, 32768, 32768, 64543, 64543, 32768, 32768, 32768, 
58393, 58393, 32768, 32768, 58393, 58393, 32768, 32768, 32768, 32768, 32768, 
64543, 64543, 64543, 64543, 64543, 58393, 58393, 58393, 58393, 58393, 58393, 
32768, 32768, 32768, 32768, 32768, 64543, 64543, 64543, 64543, 64543, 58393, 
58393, 58393, 58393, 58393, 58393, 32768, 32768, 32768, 32768, 32768, 64543, 
64543, 64543, 64543, 32768, 32768, 58393, 58393, 58393, 58393, 58393, 32768, 
32768, 32768, 32768, 32768, 64543, 64543, 64543, 32768, 64543, 32768, 32768, 
58393, 58393, 58393, 58393, 32768, 32768, 32768, 32768, 32768, 64543, 64543, 
64543, 64543, 64543, 32768, 32768, 58393, 58393, 58393, 58393, 32768, 32768, 
32768, 32768, 32768, 64543, 64543, 64543, 64543, 64543, 32768, 32768, 58393, 
58393, 58393, 58393, 32768, 32768, 32768, 32768, 32768, 64543, 64543, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 58393, 58393, 32768, 32768, 32768, 
32768, 32768, 64543, 64543, 64543, 64543, 64543, 58393, 58393, 58393, 58393, 
58393, 58393, 32768, 32768, 32768, 32768, 32768, 32768, 64543, 64543, 64543, 
64543, 58393, 58393, 58393, 58393, 58393, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768
};

TeleportBmp2::TeleportBmp2() : WoopsiGfx::BitmapWrapper(teleportbmp2_Bitmap, 16, 16) { };