//-----------------------------------------------------------
// CZRectangleShapeRenderComponent.h
//-----------------------------------------------------------

#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "ZRenderComponent.h"

namespace ZEngine
{
	class CZRectangleShapeRenderComponent : public CZRenderComponent
	{
	private:
		sf::RectangleShape m_sfmlRectangleShape;

		virtual void UpdatePosition();

	public:
		CZRectangleShapeRenderComponent(CZActor & p_pOwner, const CVector2Df p_pfSize = CVector2Df(10.0f, 10.0f), CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		~CZRectangleShapeRenderComponent();
	};
}

