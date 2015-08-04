//-----------------------------------------------------------
// CZCircleShapeRenderComponent.h
//-----------------------------------------------------------

#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "../Types/ZColor.h"
#include "ZRenderComponent.h"

namespace ZEngine
{
	class CZCircleShapeRenderComponent : public CZRenderComponent
	{
	private:
		sf::CircleShape m_sfmlCircleShape;

		ZColor m_InnerColor;
		ZColor m_OutterColor;
		float m_fRadius;
		float m_fThickness;
		int m_nNbPoints;

	public:
		CZCircleShapeRenderComponent(CZActor & p_pOwner, float p_nRadius = 5.0f, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		~CZCircleShapeRenderComponent();


		//Getters / Setters
		float GetRadius() const { return m_fRadius; }
		void SetRadius(float p_fRadius);

		ZColor GetInnerColor() const { return m_InnerColor; }
		void SetInnerColor(ZColor p_Color);
		
		ZColor GetOutterColor() const { return m_OutterColor; }
		void SetOutterColor(ZColor p_Color);

		float GetThickness() const { return m_fThickness; }
		void SetThickness(float p_fThickness);

		unsigned int GetNbPoints() const { return m_nNbPoints; }
		void SetNbPoints(unsigned int p_nNbPoints);
	};
}

