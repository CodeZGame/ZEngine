//-----------------------------------------------------------
// ZColor.h
//-----------------------------------------------------------

#pragma once

#include <cstdint>

union ZColor
{
	ZColor();
	ZColor(int p_nHexaColor);

	struct
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};

	float c[4];

	void operator=(const ZColor& p_Color);
	void operator=(int p_nHexaColor);

	static int Black() { return 0x000000FF; }
	static int White() { return 0xFFFFFFFF; }
	static int Red() { return 0xFF0000FF; }
	static int Green() { return 0x00FF00FF; }
	static int Blue() { return 0x0000FFFF; }
	static int Transparent() { return 0x00000000; }
};