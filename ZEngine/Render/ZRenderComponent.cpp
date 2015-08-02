//-----------------------------------------------------------
// ZRenderComponent.cpp
//-----------------------------------------------------------

#include <SFML/Graphics/Drawable.hpp>

#include "ZRenderComponent.h"
#include "ZWindow.h"

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
