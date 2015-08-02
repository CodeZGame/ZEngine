//-----------------------------------------------------------
// CZDebugShapeActor.h
//-----------------------------------------------------------

#pragma once

#include "../Render/ZRenderComponent.h"
#include "../Actors/ZActor.h"


namespace ZEngine
{
	class CZDebugShapeActor : public CZActor
	{
	public:
		enum class ZShapeType
		{
			e_Shape_Circle,
			e_Shape_Rectangle,
			e_Shape_Convex,
			e_Shape_None,

			e_Shape_Nb
		};

	private:
		ZShapeType m_eShapeType;

		//Must be a shape render component
		CZRenderComponent *	m_pRenderComponent;
		
		//Hide constructor, must use Create* methods
		CZDebugShapeActor();
	
		void SetRenderComponent(CZRenderComponent * p_pRenderComponent);

	public:
		~CZDebugShapeActor();

		static CZDebugShapeActor * CreateCircleShape(const CVector2D<float> &p_pfPos, float p_nRadius = 5.0f, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		static CZDebugShapeActor * CreateRectangleShape(const CVector2D<float> &p_pfPos, const CVector2Df p_pfSize = CVector2Df(10.0f, 10.0f), CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		static CZDebugShapeActor * CreateConvexShape(const CVector2D<float> &p_pfPos, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
	};
}