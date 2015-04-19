//-----------------------------------------------------------
// ZShape.h
//----------------------------------------------------------

#pragma once

#include "SFML\Graphics\Shape.hpp"
#include "ZInstance.h"
#include "Vector2D.hpp"
#include "ZColor.h"

namespace ZEngine
{
	enum class ZShapeType
	{
		e_Shape_Circle,
		e_Shape_Rectangle,
		e_Shape_Convex,

		e_Shape_Nb
	};

	class CZShape : ZInstance
	{
	protected:
		sf::Shape * m_pShape;
		ZColor m_InnerColor;
		ZColor m_OutterColor;
		unsigned int m_nNbPoints;
		float m_fThickness;
		float m_fRotatedAngle;


	public:
		CZShape(CZEngineWindow & p_pWindowOwner);
		~CZShape();

		static CZShape * Create(ZShapeType p_eType, CZEngineWindow & p_pWindowOwner);
		static CZShape * Create(ZShapeType p_eType, CZEngineWindow & p_pWindowOwner, CVector2D<float> &p_pfPos);

		virtual void Init() override;

		virtual void Reset() override;

		//Getters
		ZColor GetInnerColor() const { return m_InnerColor; }
		ZColor GetOutterColor() const { return m_OutterColor; }
		unsigned int GetNbPoints() const { return m_nNbPoints; }
		float GetThickness() const { return m_fThickness; }
		float GetRotation() const { return m_fRotatedAngle; }

		//Setters
		virtual void SetPosition(CVector2D<float> p_pfPos);
		virtual void SetScale(CVector2D<float> p_pfScale);

		void SetInnerColor(ZColor p_Color);
		void SetOutterColor(ZColor p_Color);
		void SetNbPoints(unsigned int p_nNbPoints);
		void SetThickness(float p_fThickness);
		void Rotate(float p_fRotation);
	};

}