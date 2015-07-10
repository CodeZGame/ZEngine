//-----------------------------------------------------------
// ZColor.cpp
//-----------------------------------------------------------

#include <assert.h>
#include "ZColor.h"

//-----------------------------------------------------------
//
//-----------------------------------------------------------
ZColor::ZColor()
{
	r = 0x00;
	g = 0x00;
	b = 0x00;
	a = 0xFF;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
ZColor :: ZColor(int p_nHexaColor, float p_fAlpha)
{
	assert(p_fAlpha >= 0.0f && p_fAlpha <= 1.0f);
	r = ((p_nHexaColor >> 16) & 0xFF);
	g = ((p_nHexaColor >> 8) & 0xFF);
	b = (p_nHexaColor & 0xFF);
	a = (int) (255.0f * p_fAlpha);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
ZColor :: ZColor(uint8_t p_RedValue, uint8_t p_GreenValue, uint8_t p_BlueValue, float p_fAlpha)
{
	assert(p_fAlpha >= 0.0f && p_fAlpha <= 1.0f);
	assert(p_RedValue >= 0 && p_RedValue <= 255);
	assert(p_GreenValue >= 0 && p_GreenValue <= 255);
	assert(p_BlueValue >= 0 && p_BlueValue <= 255);

	r = p_RedValue;
	g = p_GreenValue;
	b = p_BlueValue;
	a = (int)(255.0f * p_fAlpha);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void ZColor::operator=(const ZColor& p_Color)
{
	r = p_Color.r;
	g = p_Color.g;
	b = p_Color.b;
	a = p_Color.a;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void ZColor::operator=(int p_nHexaColor)
{
	r = ((p_nHexaColor >> 16) & 0xFF);
	g = ((p_nHexaColor >> 8) & 0xFF);
	b = (p_nHexaColor & 0xFF);
}