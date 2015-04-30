//-----------------------------------------------------------
// ZMouseHandler.cpp
//-----------------------------------------------------------

#include "ZMouseHandler.h"
#include "../ZEngine/ZUtils.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZMouseHandler :: CZMouseHandler()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZMouseHandler :: ~CZMouseHandler()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CVector2Di CZMouseHandler :: GetPosition()
{
	return SfVectorToZ(sf::Mouse::getPosition());
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZMouseHandler :: IsButtonPressed(ZMouseButton p_eButton)
{
	return sf::Mouse::isButtonPressed((sf::Mouse::Button) p_eButton);
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZMouseHandler :: SetPosition(CVector2Di p_pfMousePos)
{
	sf::Mouse::setPosition(ZVectorToSf(p_pfMousePos));
}