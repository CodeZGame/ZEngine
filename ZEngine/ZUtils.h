//-----------------------------------------------------------
// ZUtils.h
//----------------------------------------------------------

#pragma once

#include <SFML/System.hpp>
#include "ZInit.h"
#include "Vector2D.hpp"

//Vector Utils

template<typename T>
sf::Vector2<T> ZVectorToSf(CVector2D<T> p_ptVector)
{
	return sf::Vector2<T>(p_ptVector.x, p_ptVector.y);
}

template<typename T>
sf::Vector2u ZVectorToSfu(CVector2D<T> p_ptVector)
{
	return sf::Vector2u(p_ptVector.x, p_ptVector.y);
}

template<typename T>
CVector2D<T> SfVectorToZ(sf::Vector2<T> p_ptVector)
{
	return CVector2D<T>(p_ptVector.x, p_ptVector.y);
}