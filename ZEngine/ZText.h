//-----------------------------------------------------------
// ZText.h
//----------------------------------------------------------

#pragma once

#include <SFML\Graphics\Text.hpp>
#include "ZInstance.h"
#include "ZColor.h"
#include "ZWindowManager.h"

namespace ZEngine
{
	class CZDebug;

	class CZText : public CZInstance
	{
		enum ZTextStyle
		{
			e_ZTextStyle_Regular = 0,
			e_ZTextStyle_Bold = 2,
			e_ZTextStyle_Italic = 4,
			e_ZTextStyle_Underlined = 8,
			e_ZTextStyle_Strike = 16,
		};

		ZTextStyle m_eStyle;

		sf::Text * m_psfmlText;

		std::string m_sFontName;
		std::string m_sText;
		ZColor m_Color;
		unsigned int m_uCharacterSize;

		//Hide constructor
		CZText(const std::string p_sString = "", CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));

	public:
		~CZText();

		virtual void Init() override;

		virtual void Reset() override;

		static CZText * Create(const std::string p_sText = "", CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		static CZText * Create(const std::string p_sText, const std::string & p_sFontName, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));

		//Getters
		ZTextStyle GetStyle() const { return m_eStyle; }
		unsigned int GetCharacterSize() const { return m_uCharacterSize; }

		//Setters
		virtual void SetPosition(CVector2D<float> p_pfPos);
		virtual void SetScale(CVector2D<float> p_pfScale);
		
		void	SetText(const std::string & p_sText);
		void	SetFont(const std::string & p_sFontName);
		void	SetFont(sf::Font * font);
		void	SetColor(ZColor p_Color);
		void	SetCharacterSize(unsigned int p_uSize);

		void SetStyle(ZTextStyle p_eStyle);
		void SetCharacterSIze(unsigned int p_uSize);


		//Friend zone
		friend CZDebug;
	};
}