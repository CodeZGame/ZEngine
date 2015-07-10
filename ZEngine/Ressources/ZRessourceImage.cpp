//-----------------------------------------------------------
// ZRessourceImage.cpp
//----------------------------------------------------------

#include "ZRessourceImage.h"
#include "../Types/ZSFMLConvert.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRessourceImage :: CZRessourceImage()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRessourceImage :: ~CZRessourceImage()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZRessourceImage :: SaveToFile(const std::string & p_FilePath) const
{
	return m_sfmlImage.saveToFile(p_FilePath);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRessourceImage :: ApplyColorMask(const ZColor & p_ColorToMask, float p_Alpha)
{
	m_sfmlImage.createMaskFromColor(ZColorToSf(p_ColorToMask), (int) (p_Alpha * 255.0f));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRessourceImage * CZRessourceImage :: Create(int p_nWIdth, int p_nHeight, const ZColor & p_Color)
{
	CZRessourceImage * pImage = new CZRessourceImage();

	pImage->m_sfmlImage.create(p_nWIdth, p_nHeight, ZColorToSf(p_Color));
	return pImage;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
const std::string & CZRessourceImage :: GetFilePath() const
{
	return m_sFilePath;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CVector2Di CZRessourceImage :: GetSize() const
{
	return m_nImageSize;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
ZColor CZRessourceImage :: GetPixelColor(int p_nPixelX, int p_nPixelY) const
{
	return SfColorToZ(m_sfmlImage.getPixel(p_nPixelX, p_nPixelY));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
ZColor CZRessourceImage :: GetPixelColor(const CVector2Di & p_nPixelPos) const
{
	return SfColorToZ(m_sfmlImage.getPixel(p_nPixelPos.x, p_nPixelPos.y));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRessourceImage :: SetPixelColor(int p_nPixelX, int p_nPixelY, const ZColor & p_PixelColor)
{
	m_sfmlImage.setPixel(p_nPixelX, p_nPixelY, ZColorToSf(p_PixelColor));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRessourceImage :: SetPixelColor(const CVector2Di & p_nPixelPos, const ZColor & p_PixelColor)
{
	m_sfmlImage.setPixel(p_nPixelPos.x, p_nPixelPos.y, ZColorToSf(p_PixelColor));
}