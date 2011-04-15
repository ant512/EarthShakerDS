#include <nds.h>
#include "teleportbmp3.h"

static const u16 teleportbmp3_Bitmap[256] __attribute__ ((aligned (4))) = {
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

TeleportBmp3::TeleportBmp3() : WoopsiGfx::BitmapWrapper(teleportbmp3_Bitmap, 16, 16) { };