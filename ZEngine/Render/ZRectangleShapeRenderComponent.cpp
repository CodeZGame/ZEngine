//-----------------------------------------------------------
// CZRectangleShapeRenderComponent.cpp
//-----------------------------------------------------------

#include "ZRectangleShapeRenderComponent.h"
#include "../Types/ZSFMLConvert.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZRectangleShapeRenderComponent::CZRectangleShapeRenderComponent(CZActor & p_pOwner, const CVector2Df p_pfSize /* = CVector2Df(10.0f, 10.0f) */, CZWindow & p_pWindowOwner /* = CZWindowManager::GetWindow(0) */)
	:	CZRenderComponent(p_pOwner, m_sfmlRectangleShape, p_pWindowOwner)
{
	SetSize(p_pfSize);
	SetInnerColor(ZColor::White());
	SetOutterColor(ZColor::White());
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZRectangleShapeRenderComponent :: ~CZRectangleShapeRenderComponent()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZRectangleShapeRenderComponent :: SetSize(const CVector2Df & p_pfSize)
{
	m_pfSize = p_pfSize;
	m_sfmlRectangleShape.setSize(ZVectorToSf(p_pfSize));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZRectangleShapeRenderComponent :: SetInnerColor(ZColor p_Color)
{
	m_InnerColor = p_Color;
	m_sfmlRectangleShape.setFillColor(ZColorToSf(m_InnerColor));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZRectangleShapeRenderComponent :: SetOutterColor(ZColor p_Color)
{
	m_OutterColor = p_Color;
	m_sfmlRectangleShape.setOutlineColor(ZColorToSf(m_OutterColor));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZRectangleShapeRenderComponent :: SetThickness(float p_fThickness)
{
	m_fThickness = p_fThickness;
	m_sfmlRectangleShape.setOutlineThickness(m_fThickness);
}