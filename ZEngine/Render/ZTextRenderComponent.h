//-----------------------------------------------------------
// CZTextRenderComponent.h
//-----------------------------------------------------------

#pragma once

#include <SFML/Graphics/Text.hpp>

#include "../Types/ZColor.h"
#include "ZRenderComponent.h"

namespace ZEngine
{
	class CZTextRenderComponent : public CZRenderComponent
	{
	public:
		enum ZTextStyle
		{
			e_ZTextStyle_Regular = 0,
			e_ZTextStyle_Bold = 1,
			e_ZTextStyle_Italic = 1 << 1,
			e_ZTextStyle_Underlined = 1 << 2,
			e_ZTextStyle_Strike = 1 << 3,
		};

	private:
		sf::Text m_sfmlText;
		
		int	m_nTextStyle;
		std::string m_sFontName;
		std::string m_sText;
		ZColor m_Color;
		unsigned int m_uCharacterSize;

	public:
		CZTextRenderComponent(CZActor & p_pOwner, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		~CZTextRenderComponent();

		//Setters
		const std::string & GetText() const { return m_sText; }
		void SetText(const std::string & p_sText);

		const std::string & GetFontName() const { return m_sFontName; }
		void SetFont(const std::string & p_sFontName);

		const ZColor & GetColor() const { return m_Color; }
		void SetColor(const ZColor & p_Color);
		
		unsigned int GetCharacterSize() const { return m_uCharacterSize; }
		void SetCharacterSize(unsigned int p_uSize);

		unsigned int GetStyle() const { return m_nTextStyle; }
		void SetStyle(unsigned int p_eStyle);
	};
}