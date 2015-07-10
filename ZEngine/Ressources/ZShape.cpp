//-----------------------------------------------------------
// ZShape.cpp
//----------------------------------------------------------

#include <assert.h>
#include "SFML\Graphics\CircleShape.hpp"
#include "SFML\Graphics\RectangleShape.hpp"
#include "SFML\Graphics\ConvexShape.hpp"

#include "../Types/ZSFMLConvert.h"
#include "ZShape.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZShape :: CZShape(CZWindow & p_pWindowOwner)
	: CZInstance(p_pWindowOwner), m_eType(ZShapeType::e_Shape_None)
{
	m_bRessourceLoaded = true;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZShape :: ~CZShape()
{
	delete m_psfmlShape;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZShape * CZShape::CreateCircleShape(const CVector2D<float> &p_pfPos, float p_fRadius, CZWindow & p_pWindowOwner)
{
	CZShape * pShape = new CZShape(p_pWindowOwner);
	pShape->m_psfmlDrawable = new sf::CircleShape(p_fRadius);

	pShape->m_eType = ZShapeType::e_Shape_Circle;

	pShape->m_psfmlShape = static_cast<sf::Shape *>(pShape->m_psfmlDrawable);

	pShape->Reset();
	pShape->SetPosition(p_pfPos);
	return pShape;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZShape * CZShape::CreateRectangleShape(const CVector2D<float> &p_pfPos, const CVector2Df p_pfSize, CZWindow & p_pWindowOwner)
{
	CZShape * pShape = new CZShape(p_pWindowOwner);
	pShape->m_psfmlDrawable = new sf::RectangleShape(ZVectorToSf(p_pfSize));

	pShape->m_eType = ZShapeType::e_Shape_Rectangle;

	pShape->m_psfmlShape = static_cast<sf::Shape *>(pShape->m_psfmlDrawable);

	pShape->Reset();
	pShape->SetPosition(p_pfPos);
	return pShape;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZShape * CZShape::CreateConvexShape(const CVector2D<float> &p_pfPos, CZWindow & p_pWindowOwner)
{
	CZShape * pShape = new CZShape(p_pWindowOwner);
	pShape->m_psfmlDrawable = new sf::ConvexShape(50);

	pShape->m_eType = ZShapeType::e_Shape_Convex;

	pShape->m_psfmlShape = static_cast<sf::Shape *>(pShape->m_psfmlDrawable);

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
	SetActive(true);
	m_bRessourceLoaded = true;

	m_pfRotationAngle = 0.0f;
	SetInnerColor(ZColor::White());
	SetOutterColor(ZColor::White());
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: SetShapeType(ZShapeType p_eType)
{
	m_eType = p_eType;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: SetShapeInfo(float p_nRadius)
{
	assert(m_eType == ZShapeType::e_Shape_Circle);
	m_ShapeInfo.m_nRadius = p_nRadius;
	((sf::CircleShape*) m_psfmlShape)->setRadius(p_nRadius);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: SetShapeInfo(CVector2Df p_pfSize)
{
	assert(m_eType == ZShapeType::e_Shape_Rectangle);
	m_ShapeInfo.m_pfSize = p_pfSize;
	((sf::RectangleShape*) m_psfmlShape)->setSize(ZVectorToSf(p_pfSize));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CVector2Df CZShape::GetPoint(unsigned int index)
{
	return SfVectorToZ(static_cast<sf::ConvexShape*>(m_psfmlShape)->getPoint(index));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: SetPoint(unsigned int index, CVector2Df p_pfPos)
{
	static_cast<sf::ConvexShape*>(m_psfmlShape)->setPoint(index, ZVectorToSf(p_pfPos));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: SetPointCount(int p_nNbPoints)
{
	static_cast<sf::ConvexShape*>(m_psfmlShape)->setPointCount(p_nNbPoints);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: SetPosition(CVector2D<float> p_pfPos)
{
	m_pfPos = p_pfPos;
	m_psfmlShape->setPosition(sf::Vector2f(m_pfPos.x, m_pfPos.y));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape :: SetScale(CVector2D<float> p_pfScale)
{
	m_pfScale = p_pfScale;
	m_psfmlShape->setScale(sf::Vector2f(m_pfScale.x, m_pfScale.y));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape::SetInnerColor(ZColor p_Color)
{
	m_InnerColor = p_Color;
	m_psfmlShape->setFillColor(sf::Color(m_InnerColor.r, m_InnerColor.g, m_InnerColor.b, m_InnerColor.a));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape::SetOutterColor(ZColor p_Color)
{
	m_OutterColor = p_Color;
	m_psfmlShape->setOutlineColor(sf::Color(m_OutterColor.r, m_OutterColor.g, m_OutterColor.b, m_OutterColor.a));
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
	m_psfmlShape->setOutlineThickness(m_fThickness);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZShape::Rotate(float p_fRotation)
{
	m_fRotatedAngle = p_fRotation;
	m_psfmlShape->rotate(m_fRotatedAngle);
}