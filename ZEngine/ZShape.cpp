//-----------------------------------------------------------
// ZShape.cpp
//----------------------------------------------------------

#include "SFML\Graphics\CircleShape.hpp"
#include "SFML\Graphics\RectangleShape.hpp"
#include "SFML\Graphics\ConvexShape.hpp"

#include "ZShape.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZShape::CZShape(CZEngineWindow & p_pWindowOwner)
	: ZInstance(p_pWindowOwner)
{
	m_bIsActive = true;
	m_bRessourceLoaded = true;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZShape :: ~CZShape()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZShape * CZShape::Create(ZShapeType p_eType, CZEngineWindow & p_pWindowOwner)
{
	return Create(p_eType, p_pWindowOwner, CVector2D<float>(0.0f, 0.0f));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZShape * CZShape::Create(ZShapeType p_eType, CZEngineWindow & p_pWindowOwner, CVector2D<float> &p_pfPos)
{
	CZShape * pShape = new CZShape(p_pWindowOwner);

	switch (p_eType)
	{
	case ZShapeType::e_Shape_Circle:
		pShape->m_pDrawable = new sf::CircleShape(5.0f, 30);
		break;
	case ZShapeType::e_Shape_Convex:
		pShape->m_pDrawable = new sf::ConvexShape(5);
		break;
	case ZShapeType::e_Shape_Rectangle:
		pShape->m_pDrawable = new sf::RectangleShape(sf::Vector2f(5.0f, 5.0f));
		break;
	}

	pShape->m_pShape = static_cast<sf::Shape *>(pShape->m_pDrawable);

	pShape->Reset();
	pShape->SetPosition(p_pfPos);
	return pShape;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: Init()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: Reset()
{
	m_bIsActive = true;
	m_bRessourceLoaded = true;
	m_InnerColor = ZColor::White();
	m_OutterColor = ZColor::White();
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: SetPosition(CVector2D<float> p_pfPos)
{
	m_pfPos = p_pfPos;
	m_pShape->setPosition(sf::Vector2f(m_pfPos.x, m_pfPos.y));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: SetScale(CVector2D<float> p_pfScale)
{
	m_pfScale = p_pfScale;
	m_pShape->setScale(sf::Vector2f(m_pfScale.x, m_pfScale.y));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape::SetInnerColor(ZColor p_Color)
{
	m_InnerColor = p_Color;
	m_pShape->setFillColor(sf::Color(m_InnerColor.r, m_InnerColor.g, m_InnerColor.b, m_InnerColor.a));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape::SetOutterColor(ZColor p_Color)
{
	m_OutterColor = p_Color;
	m_pShape->setOutlineColor(sf::Color(m_OutterColor.r, m_OutterColor.g, m_OutterColor.b, m_OutterColor.a));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape::SetNbPoints(unsigned int p_nNbPoints)
{
	m_nNbPoints = p_nNbPoints;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape::SetThickness(float p_fThickness)
{
	m_fThickness = p_fThickness;
	m_pShape->setOutlineThickness(m_fThickness);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape::Rotate(float p_fRotation)
{
	m_fRotatedAngle = p_fRotation;
	m_pShape->rotate(m_fRotatedAngle);
}