//-----------------------------------------------------------
// CZConvexShapeRenderComponent.h
//-----------------------------------------------------------

#pragma once

#include <SFML/Graphics/ConvexShape.hpp>

#include "ZRenderComponent.h"

namespace ZEngine
{
	class CZConvexShapeRenderComponent : public CZRenderComponent
	{
	private:
		sf::ConvexShape m_sfmlConvexShape;

		virtual void UpdatePosition();

	public:
		CZConvexShapeRenderComponent(CZActor & p_pOwner, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		~CZConvexShapeRenderComponent();
	};
}

