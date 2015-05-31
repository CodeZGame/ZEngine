//-----------------------------------------------------------
// ZTexture.cpp
//---------------------------------------------------------

#include "ZDebug.h"
#include "ZAssert.h"
#include "ZTexture.h"

using namespace ZEngine;

//-----------------------------------------------------------
//Static
//----------------------------------------------------------
std::string CZTexture :: ms_ErrorString = "No image referenced";

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZTexture :: CZTexture()
	: m_bIsSmooth(false)
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZTexture :: ~CZTexture()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
bool CZTexture :: LoadFromImage(const CZRessourceImage * p_pImage, const CVector2Di p_pnAreaPos, const CVector2Di p_pnAreaSize)
{
	ZVALIDPOINTER(p_pImage);

	//Entire image used as texture
	if (p_pnAreaPos == CVector2Di::Zero && p_pnAreaSize == CVector2Di::Zero)
	{
		if (m_sfmlTexture.loadFromImage(p_pImage->m_sfmlImage))
		{
			m_pImage = p_pImage;
			return true;
		}
		else
		{
			CZDebug::LogError("Could not load texture from image: %s", p_pImage->GetFilePath());
			return false;
		}
	}
	//only use area of image as texture
	else
	{
		sf::IntRect area(p_pnAreaPos.x, p_pnAreaPos.y, p_pnAreaSize.x, p_pnAreaSize.y);

		if (m_sfmlTexture.loadFromImage(p_pImage->m_sfmlImage, area))
		{
			m_pImage = p_pImage;
			return true;
		}
		else
		{
			CZDebug::LogError("Could not load texture with area from image: %s", p_pImage->GetFilePath());
			return false;
		}
	}
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
const std::string & CZTexture :: GetImageName() const
{
	if (m_pImage)
	{
		return m_pImage->GetFilePath();
	}
	ZASSERT(0);
	return ms_ErrorString;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZTexture :: SetSmooth(bool p_bSmooth)
{
	m_bIsSmooth = p_bSmooth;
	m_sfmlTexture.setSmooth(m_bIsSmooth);
}