//-----------------------------------------------------------
// CZTextRenderComponent.cpp
//-----------------------------------------------------------

#include "ZTextRenderComponent.h"
#include "../Texts/ZFontManager.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZTextRenderComponent :: CZTextRenderComponent(CZActor & p_pOwner, CZWindow & p_pWindowOwner /* = CZWindowManager::GetWindow(0) */)
	: CZRenderComponent(p_pOwner, m_sfmlText, p_pWindowOwner)
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZTextRenderComponent :: ~CZTextRenderComponent()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZTextRenderComponent :: SetStyle(unsigned int p_eStyle)
{
	//Apply mask style
	m_nTextStyle |= p_eStyle;
	m_sfmlText.setStyle(m_nTextStyle);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZTextRenderComponent :: SetFont(const std::string & p_sFontName)
{
	m_sFontName = p_sFontName;
	m_sfmlText.setFont(*CZFontManager::GetFontByName(p_sFontName));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
//void CZTextRenderComponent :: SetFont(sf::Font * font)
//{
//	m_sfmlText.setFont(*font);
//}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZTextRenderComponent :: SetText(const std::string & p_sText)
{
	m_sText = p_sText;
	m_sfmlText.setString(m_sText);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZTextRenderComponent :: SetColor(const ZColor & p_Color)
{
	m_sfmlText.setColor(sf::Color(p_Color.r, p_Color.g, p_Color.b, p_Color.a));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZTextRenderComponent :: SetCharacterSize(unsigned int p_uSize)
{
	m_sfmlText.setCharacterSize(p_uSize);
}