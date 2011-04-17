#include <nds.h>
#include "teleportbmp4.h"

static const u16 teleportbmp4_Bitmap[256] __attribute__ ((aligned (4))) = {
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

TeleportBmp4::TeleportBmp4() : WoopsiGfx::BitmapWrapper(teleportbmp4_Bitmap, 16, 16) { };