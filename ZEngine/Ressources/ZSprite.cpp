//-----------------------------------------------------------
// ZSprite.cpp
//----------------------------------------------------------

#include "ZSprite.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZSprite :: CZSprite(CZWindow & p_pWindowOwner)
	: CZInstance(p_pWindowOwner)
{
	m_psfmlDrawable = &m_sfmlSprite;
	Reset();
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZSprite :: CZSprite(const CZTexture * p_pTexture, CZWindow & p_pWindowOwner)
	: CZInstance(p_pWindowOwner)
{
	m_psfmlDrawable = &m_sfmlSprite;
	m_pTexture = p_pTexture;
	m_sfmlSprite.setTexture(p_pTexture->m_sfmlTexture);

	Reset();
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZSprite :: ~CZSprite()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZSprite :: Init()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZSprite :: Reset()
{
	SetActive(true);
	m_bRessourceLoaded = true;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
const CZTexture * CZSprite :: GetTexture() const
{
	return m_pTexture;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
ZColor CZSprite :: GetColor() const
{
	return m_Color;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZSprite :: SetTexture(const CZTexture * p_pTexture)
{
	m_pTexture = p_pTexture;
	m_sfmlSprite.setTexture(p_pTexture->m_sfmlTexture);
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZSprite :: SetColor(ZColor p_Color)
{
	m_Color = p_Color;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZSprite :: SetPosition(CVector2D<float> p_pfPos)
{
	m_pfPos = p_pfPos;
	m_sfmlSprite.setPosition(sf::Vector2f(m_pfPos.x, m_pfPos.y));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZSprite :: Move(CVector2D<float> p_pfPos)
{
	m_pfPos = m_pfPos + p_pfPos;
	m_sfmlSprite.move(sf::Vector2f(m_pfPos.x, m_pfPos.y));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZSprite :: SetScale(CVector2D<float> p_pfScale)
{
	m_pfScale = p_pfScale;
	m_sfmlSprite.setScale(sf::Vector2f(m_pfScale.x, m_pfScale.y));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZSprite :: SetRotation(float p_fRotationAngle)
{
	m_pfRotationAngle = p_fRotationAngle;
	m_sfmlSprite.setRotation(m_pfRotationAngle);
}