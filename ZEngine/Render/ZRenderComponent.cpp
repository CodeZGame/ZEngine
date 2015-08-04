//-----------------------------------------------------------
// ZRenderComponent.cpp
//-----------------------------------------------------------

#include <SFML/Graphics/Drawable.hpp>

#include "ZRenderComponent.h"
#include "ZWindow.h"
#include "../Types/ZSFMLConvert.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRenderComponent :: CZRenderComponent(CZActor & p_pOwner, sf::Drawable & p_pDrawable, CZWindow & p_pWindowOwner /* = CZWindowManager::GetWindow(0) */)
	:	m_pOwner(p_pOwner),
		m_pSfmlDrawable(p_pDrawable),
		m_pWindowOwner(p_pWindowOwner)
{
	m_pWindowOwner.AddDrawableInstance(this);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRenderComponent :: ~CZRenderComponent()
{
}

#pragma  message("TODO: Test performance of dynamic_cast VS reinterpret")
//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRenderComponent :: UpdatePosition()
{
	//Update the sfml object position using current Actor position
	//Dynamic cast to Transformable, all sfml drawable objects inherit from it
	//Except Vertex Array (careful with those !)
	dynamic_cast<sf::Transformable&>(m_pSfmlDrawable).setPosition(ZVectorToSf(m_pOwner.m_Transform.m_position));
}