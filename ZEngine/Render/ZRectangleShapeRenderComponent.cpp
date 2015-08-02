//-----------------------------------------------------------
// CZRectangleShapeRenderComponent.cpp
//-----------------------------------------------------------

#include "ZRectangleShapeRenderComponent.h"
#include "../Types/ZSFMLConvert.h"

using namespace ZEngine;

CZRectangleShapeRenderComponent::CZRectangleShapeRenderComponent(CZActor & p_pOwner, const CVector2Df p_pfSize /* = CVector2Df(10.0f, 10.0f) */, CZWindow & p_pWindowOwner /* = CZWindowManager::GetWindow(0) */)
	:	CZRenderComponent(p_pOwner, m_sfmlRectangleShape, p_pWindowOwner)
{
}


CZRectangleShapeRenderComponent :: ~CZRectangleShapeRenderComponent()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZRectangleShapeRenderComponent::UpdatePosition()
{
	m_sfmlRectangleShape.setPosition(ZVectorToSf(m_pOwner.m_Transform.m_position));
}
