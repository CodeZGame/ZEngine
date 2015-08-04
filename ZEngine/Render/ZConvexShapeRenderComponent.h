//-----------------------------------------------------------
// CZConvexShapeRenderComponent.h
//-----------------------------------------------------------

#pragma once

#include <SFML/Graphics/ConvexShape.hpp>

#include "../Types/ZColor.h"
#include "ZRenderComponent.h"

namespace ZEngine
{
	class CZConvexShapeRenderComponent : public CZRenderComponent
	{
	private:
		sf::ConvexShape m_sfmlConvexShape;

		ZColor m_InnerColor;
		ZColor m_OutterColor;
		float m_fThickness;
		unsigned int m_nNbPoints;

	public:
		CZConvexShapeRenderComponent(CZActor & p_pOwner, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		~CZConvexShapeRenderComponent();

		//Getters / Setters
		ZColor	GetInnerColor() const { return m_InnerColor; }
		void	SetInnerColor(ZColor p_Color);

		ZColor	GetOutterColor() const { return m_OutterColor; }
		void	SetOutterColor(ZColor p_Color);

		float	GetThickness() const { return m_fThickness; }
		void	SetThickness(float p_fThickness);

		CVector2Df GetPoint(unsigned int index);
		void	SetPoint(unsigned int index, CVector2Df p_pfPos);

		int		GetPointCount() const { return m_nNbPoints; }
		void	SetPointCount(int p_nNbPoints);
	};
}

