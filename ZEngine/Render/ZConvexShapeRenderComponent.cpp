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
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZConvexShapeRenderComponent :: ~CZConvexShapeRenderComponent()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZConvexShapeRenderComponent::UpdatePosition()
{
	m_sfmlConvexShape.setPosition(ZVectorToSf(m_pOwner.m_Transform.m_position));
}