//-----------------------------------------------------------
// CZConvexShapeRenderComponent.cpp
//-----------------------------------------------------------

#include "ZConvexShapeRenderComponent.h"
#include "../Types/ZSFMLConvert.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZConvexShapeRenderComponent :: CZConvexShapeRenderComponent(CZActor & p_pOwner, CZWindow & p_pWindowOwner /* = CZWindowManager::GetWindow(0) */)
	:	CZRenderComponent(p_pOwner, m_sfmlConvexShape, p_pWindowOwner)
{
	SetInnerColor(ZColor::White());
	SetOutterColor(ZColor::White());
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZConvexShapeRenderComponent :: ~CZConvexShapeRenderComponent()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZConvexShapeRenderComponent :: SetInnerColor(ZColor p_Color)
{
	m_InnerColor = p_Color;
	m_sfmlConvexShape.setFillColor(ZColorToSf(m_InnerColor));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZConvexShapeRenderComponent :: SetOutterColor(ZColor p_Color)
{
	m_OutterColor = p_Color;
	m_sfmlConvexShape.setOutlineColor(ZColorToSf(m_OutterColor));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZConvexShapeRenderComponent :: SetThickness(float p_fThickness)
{
	m_fThickness = p_fThickness;
	m_sfmlConvexShape.setOutlineThickness(m_fThickness);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CVector2Df CZConvexShapeRenderComponent :: GetPoint(unsigned int index)
{
	return SfVectorToZ(m_sfmlConvexShape.getPoint(index));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZConvexShapeRenderComponent :: SetPoint(unsigned int index, CVector2Df p_pfPos)
{
	m_sfmlConvexShape.setPoint(index, ZVectorToSf(p_pfPos));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZConvexShapeRenderComponent :: SetPointCount(int p_nNbPoints)
{
	m_sfmlConvexShape.setPointCount(p_nNbPoints);
}