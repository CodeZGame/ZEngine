//-----------------------------------------------------------
// ZShape.h
//----------------------------------------------------------

#pragma once

#include "ZWindowManager.h"
#include "SFML\Graphics\Shape.hpp"
#include "ZInstance.h"
#include "Vector2D.hpp"
#include "ZColor.h"

namespace ZEngine
{
	class CZDebug;

	enum class ZShapeType
	{
		e_Shape_Circle,
		e_Shape_Rectangle,
		e_Shape_Convex,
		e_Shape_None,

		e_Shape_Nb
	};

	class CZShape : public CZInstance
	{
	protected:
		union ShapeInfos
		{
			float m_nRadius;
			struct
			{
				CVector2Df m_pfSize;
			};
		};

		ShapeInfos m_ShapeInfo;

		sf::Shape * m_psfmlShape;
		ZShapeType m_eType;

		ZColor m_InnerColor;
		ZColor m_OutterColor;
		unsigned int m_nNbPoints;
		float m_fThickness;
		float m_fRotatedAngle;

		//Hide constructor
		CZShape(CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));

	public:
		~CZShape();

		static CZShape * CreateCircleShape(const CVector2D<float> &p_pfPos, float p_nRadius = 5.0f, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		static CZShape * CreateRectangleShape(const CVector2D<float> &p_pfPos, const CVector2Df p_pfSize = CVector2Df(10.0f, 10.0f), CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		static CZShape * CreateConvexShape(const CVector2D<float> &p_pfPos, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));

		virtual void Init() override;

		virtual void Reset() override;

		//Getters
		ZColor GetInnerColor() const { return m_InnerColor; }
		ZColor GetOutterColor() const { return m_OutterColor; }
		unsigned int GetNbPoints() const { return m_nNbPoints; }
		float GetThickness() const { return m_fThickness; }
		float GetRotation() const { return m_fRotatedAngle; }

		float GetRadius() { return m_ShapeInfo.m_nRadius; }
		CVector2Df GetSize() { return m_ShapeInfo.m_pfSize; }

		//Setters
		virtual void SetPosition(CVector2D<float> p_pfPos);
		virtual void SetScale(CVector2D<float> p_pfScale);

		void SetShapeType(ZShapeType p_eType);

		//Circle shape
		void SetShapeInfo(float p_nRadius);

		//Rectangle shape
		void SetShapeInfo(CVector2Df p_pfSize);

		//Convex shape
		CVector2Df GetPoint(unsigned int index);
		void SetPoint(unsigned int index, CVector2Df p_pfPos);

		void SetPointCount(int p_nNbPoints);
		void SetInnerColor(ZColor p_Color);
		void SetOutterColor(ZColor p_Color);
		void SetNbPoints(unsigned int p_nNbPoints);
		void SetThickness(float p_fThickness);
		void Rotate(float p_fRotation);

		//Friend zone
		friend CZDebug;
	};

}