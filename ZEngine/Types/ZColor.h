//-----------------------------------------------------------
// ZColor.h
//-----------------------------------------------------------

#pragma once

#include <cstdint>

union ZColor
{
	ZColor();
	ZColor(int p_nHexaColor, float p_fAlpha = 1.0f);
	ZColor(uint8_t p_RedValue, uint8_t p_GreenValue, uint8_t p_BlueValue, float p_fAlpha = 1.0f);

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

	static int Black() { return 0x000000; }
	static int White() { return 0xFFFFFF; }
	static int Red() { return 0xFF0000; }
	static int Green() { return 0x00FF00; }
	static int Blue() { return 0x0000FF; }
};