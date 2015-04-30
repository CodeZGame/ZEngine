//-----------------------------------------------------------
// ZFontManager.h
//-----------------------------------------------------------

#pragma once

#include <string>
#include <SFML\Graphics\Text.hpp>

#define ZENGINE_MAX_FONTS	10

namespace ZEngine
{
	class CZFontManager
	{
	protected:
		static sf::Font ms_loadedFonts[ZENGINE_MAX_FONTS];
		static unsigned int ms_uNbLoadedFonts;

		CZFontManager();
		~CZFontManager();

	public:

		static bool LoadFromFile(const std::string & p_sPath);

		static sf::Font * GetFontByName(const std::string & p_sFontName);

		static sf::Font * GetFontByIndex(unsigned int p_uFontIndex);
	};
}