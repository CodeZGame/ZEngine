//-----------------------------------------------------------
// ZMathUtils.h
//----------------------------------------------------------

#pragma once

//-----------------------------------------------------------
//
//-----------------------------------------------------------
inline float Maxf(float p_fValue, float p_fMax)
{
	if (p_fValue > p_fMax)
		return p_fMax;
	return p_fValue;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
inline float Minf(float p_fValue, float p_fMin)
{
	if (p_fValue < p_fMin)
		return p_fMin;
	return p_fValue;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
inline float Clampf(float p_fValue, float p_fMin, float p_fMax)
{
	return Minf(Maxf(p_fValue, p_fMax), p_fMin);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
inline int Max(int p_nValue, int p_nMax)
{
	if (p_nValue > p_nMax)
		return p_nMax;
	return p_nValue;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
inline int Min(int p_nValue, int p_fnMin)
{
	if (p_nValue < p_fnMin)
		return p_fnMin;
	return p_nValue;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
inline int Clamp(int p_nValue, int p_nMin, int p_nMax)
{
	return Min(Max(p_nValue, p_nMax), p_nMin);
}