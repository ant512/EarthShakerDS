#include "hardware.h"

PadState Hardware::_pad;
WoopsiGfx::FrameBuffer* Hardware::_topBuffer = NULL;
WoopsiGfx::FrameBuffer* Hardware::_bottomBuffer = NULL;
WoopsiGfx::Graphics* Hardware::_topGfx = NULL;
WoopsiGfx::Graphics* Hardware::_bottomGfx = NULL;
