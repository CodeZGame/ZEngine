//-----------------------------------------------------------
// Vector2D.cpp
//-----------------------------------------------------------


#include "Vector2D.h"

using namespace ZEngine;

/*template<typename T>
CVector2D<T> ::CVector2D(const T p_tX, const T p_tY)
	: x(p_tX), y(p_tY)
{
}*/

template<>
//CVector2D<int> ::CVector2D(const int p_tX, const int p_tY)
CVector2D<int> :: CVector2D(const int p_tX, const int p_tY)
{
	x = p_tX;
	y = p_tY;
}

template<class T>
CVector2D<T> :: ~CVector2D()
{
}

template<typename T>
void CVector2D<T> :: Set(const T p_tX, const T p_tY)
{
	this->x = p_tX;
	this->y = p_tY;
}