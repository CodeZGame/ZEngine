//-----------------------------------------------------------
// CZRectangleShapeRenderComponent.h
//-----------------------------------------------------------

#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "../Types/ZColor.h"
#include "ZRenderComponent.h"

namespace ZEngine
{
	class CZRectangleShapeRenderComponent : public CZRenderComponent
	{
	private:
		sf::RectangleShape m_sfmlRectangleShape;

		ZColor m_InnerColor;
		ZColor m_OutterColor;
		CVector2Df m_pfSize;
		float m_fThickness;

		//virtual void UpdatePosition();

	public:
		CZRectangleShapeRenderComponent(CZActor & p_pOwner, const CVector2Df p_pfSize = CVector2Df(10.0f, 10.0f), CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		~CZRectangleShapeRenderComponent();

		//Getters / Setters
		const CVector2Df & GetSize() const { return m_pfSize; }
		void SetSize(const CVector2Df & p_pfSize);

		ZColor GetInnerColor() const { return m_InnerColor; }
		void SetInnerColor(ZColor p_Color);

		ZColor GetOutterColor() const { return m_OutterColor; }
		void SetOutterColor(ZColor p_Color);

		float GetThickness() const { return m_fThickness; }
		void SetThickness(float p_fThickness);
	};
}

