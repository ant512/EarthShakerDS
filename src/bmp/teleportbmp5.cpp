#include <nds.h>
#include "teleportbmp5.h"

static const u16 teleportbmp5_Bitmap[256] __attribute__ ((aligned (4))) = {
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 
32768, 32768, 64543, 64543, 64543, 64543, 58393, 58393, 58393, 58393, 58393, 
32768, 32768, 32768, 32768, 32768, 32768, 64543, 64543, 32768, 32768, 32768, 
58393, 58393, 32768, 32768, 58393, 58393, 32768, 32768, 32768, 32768, 32768, 
64543, 32768, 32768, 32768, 32768, 58393, 32768, 32768, 32768, 32768, 58393, 
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

TeleportBmp5::TeleportBmp5() : WoopsiGfx::BitmapWrapper(teleportbmp5_Bitmap, 16, 16) { };