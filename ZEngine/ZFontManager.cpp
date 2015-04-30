//-----------------------------------------------------------
// ZFontManager.cpp
//-----------------------------------------------------------

#include <assert.h>
#include <algorithm>
#include "ZFontManager.h"

#define FONT_PATH	"../Build/"

using namespace ZEngine;

sf::Font CZFontManager::ms_loadedFonts[ZENGINE_MAX_FONTS];

unsigned int CZFontManager::ms_uNbLoadedFonts = 0;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZFontManager :: CZFontManager()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZFontManager :: ~CZFontManager()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZFontManager :: LoadFromFile(const std::string & p_sPath)
{
	assert(ms_uNbLoadedFonts < ZENGINE_MAX_FONTS - 1 && "Max font loaded! Increase ZENGINE_MAX_FONTS");

	std::string sFontPath(FONT_PATH);

	sFontPath.append(p_sPath);

	bool bSuccess = ms_loadedFonts[ms_uNbLoadedFonts].loadFromFile(sFontPath);

	++ms_uNbLoadedFonts;

	if (!bSuccess)
	{
		assert(0 && "Could not load font   TODO: Add log");
		// Error loading font from file
	}

	return bSuccess;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
sf::Font * CZFontManager :: GetFontByName(const std::string & p_sFontName)
{
	std::string sFamilyInfo;
	std::string sFontToFind(p_sFontName);

	std::transform(sFontToFind.begin(), sFontToFind.end(),
				   sFontToFind.begin(), ::tolower);

	for (int i = 0; i < ZENGINE_MAX_FONTS && i < (int) ms_uNbLoadedFonts; ++i)
	{
		sFamilyInfo.assign(ms_loadedFonts[i].getInfo().family);

		std::transform(sFamilyInfo.begin(), sFamilyInfo.end(),
					   sFamilyInfo.begin(), ::tolower);
		if (sFontToFind.compare(sFamilyInfo) == 0)
		{
			return &ms_loadedFonts[i];
		}
	}

	assert(0 && "Font not loaded");
	return nullptr;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
sf::Font * CZFontManager :: GetFontByIndex(unsigned int p_uFontIndex)
{
	assert(p_uFontIndex < ZENGINE_MAX_FONTS);

	return & ms_loadedFonts[p_uFontIndex];
}