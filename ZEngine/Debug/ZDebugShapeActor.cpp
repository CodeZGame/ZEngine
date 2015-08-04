//-----------------------------------------------------------
// CZDebugShapeActor.cpp
//-----------------------------------------------------------

#include "ZDebugShapeActor.h"
#include "../Render/ZCircleShapeRenderComponent.h"
#include "../Render/ZRectangleShapeRenderComponent.h"
#include "../Render/ZConvexShapeRenderComponent.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZDebugShapeActor :: CZDebugShapeActor()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZDebugShapeActor :: ~CZDebugShapeActor()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZDebugShapeActor :: SetRenderComponent(CZRenderComponent * p_pRenderComponent)
{
	m_pRenderComponent = p_pRenderComponent;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZDebugShapeActor * CZDebugShapeActor::CreateCircleShape(const CVector2D<float> &p_pfPos, float p_nRadius /*= 5.0f*/, CZWindow & p_pWindowOwner /*= CZWindowManager::GetWindow(0)*/)
{
	CZDebugShapeActor * pDebugShape = new CZDebugShapeActor();

	pDebugShape->SetRenderComponent(new CZCircleShapeRenderComponent(*pDebugShape, p_nRadius, p_pWindowOwner));

	pDebugShape->m_eShapeType = ZShapeType::e_Shape_Circle;
	pDebugShape->m_Transform.m_position = p_pfPos;
	return pDebugShape;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZDebugShapeActor * CZDebugShapeActor::CreateRectangleShape(const CVector2D<float> &p_pfPos, const CVector2Df p_pfSize /*= CVector2Df(10.0f, 10.0f)*/, CZWindow & p_pWindowOwner /*= CZWindowManager::GetWindow(0)*/)
{
	CZDebugShapeActor * pDebugShape = new CZDebugShapeActor();

	pDebugShape->SetRenderComponent(new CZRectangleShapeRenderComponent(*pDebugShape, p_pfSize, p_pWindowOwner));

	pDebugShape->m_eShapeType = ZShapeType::e_Shape_Rectangle;
	pDebugShape->m_Transform.m_position = p_pfPos;
	return pDebugShape;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZDebugShapeActor * CZDebugShapeActor::CreateConvexShape(const CVector2D<float> &p_pfPos, CZWindow & p_pWindowOwner /*= CZWindowManager::GetWindow(0)*/)
{
	CZDebugShapeActor * pDebugShape = new CZDebugShapeActor();
	
	pDebugShape->SetRenderComponent(new CZConvexShapeRenderComponent(*pDebugShape, p_pWindowOwner));

	pDebugShape->m_eShapeType = ZShapeType::e_Shape_Rectangle;
	pDebugShape->m_Transform.m_position = p_pfPos;
	return pDebugShape;
}