//-----------------------------------------------------------
// ZText.h
//----------------------------------------------------------

#include "ZFontManager.h"
#include "ZText.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZText :: CZText(const std::string p_sString, CZWindow & p_pWindowOwner)
	: m_sText(p_sString), CZDrawableInstance(p_pWindowOwner)
{
	m_psfmlText = new sf::Text();
	m_bRessourceLoaded = true;

	m_psfmlDrawable = m_psfmlText;

	m_psfmlText->setString(m_sText);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZText :: ~CZText()
{
	delete m_psfmlText;
	m_psfmlText = nullptr;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText :: Init()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText :: Reset()
{
	SetActive(true);
	SetPosition(CVector2Df(0.0f, 0.0f));

	SetCharacterSize(17);
	SetColor(ZColor::White());
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText :: SetStyle(ZTextStyle p_eStyle)
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText :: SetFont(const std::string & p_sFontName)
{
	m_sFontName = p_sFontName;
	m_psfmlText->setFont( * CZFontManager::GetFontByName(p_sFontName));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText::SetFont(sf::Font * font)
{
	m_psfmlText->setFont(*font);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText :: SetText(const std::string & p_sText)
{
	m_sText = p_sText;
	m_psfmlText->setString(m_sText);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText :: SetPosition(CVector2D<float> p_pfPos)
{
	m_pfPos = p_pfPos;
	m_psfmlText->setPosition(sf::Vector2f(m_pfPos.x, m_pfPos.y));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText :: SetScale(CVector2D<float> p_pfScale)
{
	m_pfScale = p_pfScale;
	m_psfmlText->setScale(sf::Vector2f(m_pfScale.x, m_pfScale.y));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText :: SetColor(ZColor p_Color)
{
	m_psfmlText->setColor(sf::Color(p_Color.r, p_Color.g, p_Color.b, p_Color.a));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZText::SetCharacterSize(unsigned int p_uSize)
{
	m_psfmlText->setCharacterSize(p_uSize);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZText * CZText::Create(const std::string p_sText, CZWindow & p_pWindowOwner)
{
	CZText * pText = new CZText(p_sText, p_pWindowOwner);

	pText->SetFont(CZFontManager::GetFontByIndex(0));
	pText->Reset();

	return pText;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZText * CZText :: Create(const std::string p_sText, const std::string & p_sFontName, CZWindow & p_pWindowOwner)
{
	CZText * pText = new CZText(p_sText, p_pWindowOwner);

	pText->SetFont(p_sFontName);
	pText->Reset();

	return pText;
}