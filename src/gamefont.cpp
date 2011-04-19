#include "gamefont.h"
#include <nds.h>

static const u16 GameFont_glyphdata[308] = {
/* '$' */	0x003C,0xD9B1,0xE0CD,0x8E00,
/* '%' */	0x1047,0xCE11,0xB384,
/* '&' */	0x10E6,0xC439,0xF104,
/* ''' */	0x00C6,0x1100,0x0000,
/* '(' */	0x00F7,0x1C71,0xC3C0,
/* ')' */	0x0078,0x3870,0xE1CF,0x0000,
/* '*' */	0x38FA,0xEE35,0x4A8A,0x0800,
/* '+' */	0x00DB,0xFFFF,0xEF8E,0x0800,
/* ',' */	0x0000,0x018C,0x2200,
/* '-' */	0x0000,0x07F0,0x0000,0x0000,
/* '.' */	0x0000,0x0000,0x6300,
/* '/' */	0x0000,
/* '0' */	0x00FB,0xBF7E,0xFDDF,0x0000,
/* '1' */	0x0073,0xE1C3,0x873F,0x8000,
/* '2' */	0x00FB,0x7EF3,0xCF3F,0x8000,
/* '3' */	0x00FB,0x79E1,0xFBDF,0x0000,
/* '4' */	0x01DB,0xB7F1,0xC387,0x0000,
/* '5' */	0x01FB,0x87E1,0xE3FF,0x0000,
/* '6' */	0x00FB,0x87EE,0xFDDF,0x0000,
/* '7' */	0x01FC,0x38E3,0x870E,0x0000,
/* '8' */	0x00FB,0xBBEE,0xFDDF,0x0000,
/* '9' */	0x00FB,0xBF77,0xE1DF,0x0000,
/* ':' */	0x00C6,0x000C,0x6000,
/* ';' */	0x0000,
/* '<' */	0x0000,
/* '=' */	0x0003,0xF80F,0xE000,0x0000,
/* '>' */	0x0000,
/* '?' */	0x00FB,0xB871,0xC00C,0x0000,
/* '@' */	0x0000,
/* 'A' */	0x00FB,0xBF7F,0xFDFB,0x8000,
/* 'B' */	0x01FB,0x7FED,0xFBFF,0x0000,
/* 'C' */	0x00FB,0xDF8F,0x1EDF,0x0000,
/* 'D' */	0x01FB,0xBF7E,0xFDFF,0x0000,
/* 'E' */	0x00FF,0xC7FF,0x1FDF,0x8000,
/* 'F' */	0x00FF,0xC7FF,0x1E3C,0x0000,
/* 'G' */	0x00FB,0xBF0E,0xFCDF,0x8000,
/* 'H' */	0x01DF,0xBFFE,0xFDFB,0x8000,
/* 'I' */	0x01FC,0xE1C3,0x873F,0x8000,
/* 'J' */	0x01FC,0x70ED,0xDB9E,0x0000,
/* 'K' */	0x01DF,0xBFEE,0xFDFB,0x8000,
/* 'L' */	0x01C3,0x870E,0x1C3F,0x8000,
/* 'M' */	0x00DB,0xFFFF,0xFAF5,0x8000,
/* 'N' */	0x00FB,0xBF7E,0xFDFB,0x8000,
/* 'O' */	0x00FB,0xBF7E,0xFDDF,0x0000,
/* 'P' */	0x01FB,0xBF7F,0xDC38,0x0000,
/* 'Q' */	0x007C,0xEEEE,0xEEEE,0x7F00,
/* 'R' */	0x01FB,0xBF7F,0xDDFB,0x8000,
/* 'S' */	0x00FF,0xC7E7,0xE3FF,0x0000,
/* 'T' */	0x01FC,0xE1C3,0x870E,0x0000,
/* 'U' */	0x01DF,0xBF7E,0xFDDF,0x0000,
/* 'V' */	0x01DF,0xBF7E,0xED8E,0x0000,
/* 'W' */	0x01AF,0x5FFF,0xFFDB,0x0000,
/* 'X' */	0x01DF,0xBBEE,0xFDFB,0x8000,
/* 'Y' */	0x01DF,0xBF77,0xC70E,0x0000,
/* 'Z' */	0x01FC,0x79E7,0x9E3F,0x8000,
/* '[' */	0x0000,
/* '\' */	0x0000,
/* ']' */	0x0000,
/* '^' */	0x0000,
/* '_' */	0x0000,
/* '`' */	0x0000,
/* 'a' */	0x00FB,0xBF7F,0xFDFB,0x8000,
/* 'b' */	0x01FB,0x7FED,0xFBFF,0x0000,
/* 'c' */	0x00FB,0xDF8F,0x1EDF,0x0000,
/* 'd' */	0x01FB,0xBF7E,0xFDFF,0x0000,
/* 'e' */	0x00FF,0xC7FF,0x1FDF,0x8000,
/* 'f' */	0x00FF,0xC7FF,0x1E3C,0x0000,
/* 'g' */	0x00FB,0xBF0E,0xFCDF,0x8000,
/* 'h' */	0x01DF,0xBFFE,0xFDFB,0x8000,
/* 'i' */	0x01FC,0xE1C3,0x873F,0x8000,
/* 'j' */	0x01FC,0x70ED,0xDB9E,0x0000,
/* 'k' */	0x01DF,0xBFEE,0xFDFB,0x8000,
/* 'l' */	0x01C3,0x870E,0x1C3F,0x8000,
/* 'm' */	0x00DB,0xFFFF,0xFAF5,0x8000,
/* 'n' */	0x00FB,0xBF7E,0xFDFB,0x8000,
/* 'o' */	0x00FB,0xBF7E,0xFDDF,0x0000,
/* 'p' */	0x01FB,0xBF7F,0xDC38,0x0000,
/* 'q' */	0x007C,0xEEEE,0xEEEE,0x7F00,
/* 'r' */	0x01FB,0xBF7F,0xDDFB,0x8000,
/* 's' */	0x00FF,0xC7E7,0xE3FF,0x0000,
/* 't' */	0x01FC,0xE1C3,0x870E,0x0000,
/* 'u' */	0x01DF,0xBF7E,0xFDDF,0x0000,
/* 'v' */	0x01DF,0xBF7E,0xED8E,0x0000,
/* 'w' */	0x01AF,0x5FFF,0xFFDB,0x0000,
/* 'x' */	0x01DF,0xBBEE,0xFDFB,0x8000,
/* 'y' */	0x01DF,0xBF77,0xC70E,0x0000,
/* 'z' */	0x01FC,0x79E7,0x9E3F,0x8000,
};

static const u16 GameFont_offset[87] = {
    0,    4,    7,   10,   13,   16,   20,   24,   28,   31,   35,   38,   39,   43,   47,   51,
   55,   59,   63,   67,   71,   75,   79,   82,   83,   84,   88,   89,   93,   94,   98,  102,
  106,  110,  114,  118,  122,  126,  130,  134,  138,  142,  146,  150,  154,  158,  162,  166,
  170,  174,  178,  182,  186,  190,  194,  198,  199,  200,  201,  202,  203,  204,  208,  212,
  216,  220,  224,  228,  232,  236,  240,  244,  248,  252,  256,  260,  264,  268,  272,  276,
  280,  284,  288,  292,  296,  300,  304
};

static const u8 GameFont_width[87] = {
 7, 6, 6, 5, 6, 7, 7, 7, 5, 7, 5, 0, 7, 7, 7, 7,
 7, 7, 7, 7, 7, 7, 5, 0, 0, 7, 0, 7, 0, 7, 7, 7,
 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 7, 7,
 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 7,
 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 7, 7,
 7, 7, 7, 7, 7, 7, 7
};

GameFont::GameFont() : WoopsiGfx::PackedFont1 (
	36,
	122,
	GameFont_glyphdata,
	GameFont_offset,
	GameFont_width,
	8,
	8,
	6,
	8
) {
	setFontWidth(8);
};
