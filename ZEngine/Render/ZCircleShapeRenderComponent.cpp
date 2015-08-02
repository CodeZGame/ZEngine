//-----------------------------------------------------------
// CZCircleShapeRenderComponent.cpp
//-----------------------------------------------------------

#include "ZCircleShapeRenderComponent.h"
#include "../Types/ZSFMLConvert.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZCircleShapeRenderComponent :: CZCircleShapeRenderComponent(CZActor & p_pOwner, float p_nRadius /* = 5.0f */, CZWindow & p_pWindowOwner /* = CZWindowManager::GetWindow(0) */)
	:	CZRenderComponent(p_pOwner, m_sfmlCircleShape, p_pWindowOwner)
{
	SetRadius(p_nRadius);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZCircleShapeRenderComponent :: ~CZCircleShapeRenderComponent()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZCircleShapeRenderComponent :: SetRadius(float p_fRadius)
{
	m_fRadius = p_fRadius;
	m_sfmlCircleShape.setRadius(m_fRadius);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZCircleShapeRenderComponent :: SetInnerColor(ZColor p_Color)
{
	m_InnerColor = p_Color;
	m_sfmlCircleShape.setFillColor(ZColorToSf(m_InnerColor));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZCircleShapeRenderComponent :: SetOutterColor(ZColor p_Color)
{
	m_OutterColor = p_Color;
	m_sfmlCircleShape.setOutlineColor(ZColorToSf(m_OutterColor));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZCircleShapeRenderComponent :: SetThickness(float p_fThickness)
{
	m_fThickness = p_fThickness;
	m_sfmlCircleShape.setOutlineThickness(m_fThickness);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZCircleShapeRenderComponent :: SetNbPoints(unsigned int p_nNbPoints)
{
	m_nNbPoints = p_nNbPoints;
	m_sfmlCircleShape.setPointCount(m_nNbPoints);
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZCircleShapeRenderComponent :: UpdatePosition()
{
	m_sfmlCircleShape.setPosition(ZVectorToSf(m_pOwner.m_Transform.m_position));
}
