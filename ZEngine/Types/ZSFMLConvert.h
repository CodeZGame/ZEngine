//-----------------------------------------------------------
// ZSFMLConvert.h
//----------------------------------------------------------

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "Vector2D.hpp"
#include "ZRect.hpp"
#include "ZColor.h"

//Vector Convert

//-----------------------------------------------------------
//
//-----------------------------------------------------------
template<typename T>
inline sf::Vector2<T> ZVectorToSf(CVector2D<T> p_ptVector)
{
	return sf::Vector2<T>(p_ptVector.x, p_ptVector.y);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------

inline sf::Vector2u ZVectorToSfu(CVector2Di p_ptVector)
{
	return sf::Vector2u(p_ptVector.x, p_ptVector.y);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
template<typename T>
inline CVector2D<T> SfVectorToZ(sf::Vector2<T> p_ptVector)
{
	return CVector2D<T>(p_ptVector.x, p_ptVector.y);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
inline CVector2Di SfuVectorToZ(sf::Vector2u p_ptVector)
{
	return CVector2Di(p_ptVector.x, p_ptVector.y);
}

//Color Convert

//-----------------------------------------------------------
//
//-----------------------------------------------------------
inline ZColor SfColorToZ(const sf::Color & p_sfColor)
{
	return ZColor(p_sfColor.r, p_sfColor.g, p_sfColor.b, p_sfColor.a);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
inline sf::Color ZColorToSf(const ZColor & p_Color)
{
	return sf::Color(p_Color.r, p_Color.g, p_Color.b, p_Color.a);
}

//Rect Convert

//-----------------------------------------------------------
//
//-----------------------------------------------------------
template<typename T>
inline sf::Rect<T> ZRectToSf(ZRect<T> p_ptRect)
{
	return sf::Rect<T>(p_ptRect.top, p_ptRect.left, p_ptRect.width, p_ptRect.height);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
template<typename T>
inline ZRect<T> SfRectToZ(sf::Rect<T> p_ptRect)
{
	return ZRect<T>(p_ptRect.top, p_ptRect.left, p_ptRect.width, p_ptRect.height);
}