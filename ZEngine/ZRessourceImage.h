//-----------------------------------------------------------
// ZRessourceImage.h
//----------------------------------------------------------

#pragma once

#include <SFML\Graphics\Image.hpp>

#include "Vector2D.hpp"
#include "ZColor.h"

namespace ZEngine
{
	class CZRessourceImageManager;
	class CZTexture;

	class CZRessourceImage
	{
	protected:
		sf::Image m_sfmlImage;
		std::string m_sFilePath;

		CVector2Di m_nImageSize;

		CZRessourceImage();

	public:
		~CZRessourceImage();

		bool SaveToFile(const std::string & p_FilePath) const;

		void ApplyColorMask(const ZColor & p_ColorToMask, float p_Alpha = 0.0f);

		static CZRessourceImage * Create(int p_nWIdth, int p_nHeight, const ZColor & p_Color);

		//Getters
		const std::string & GetFilePath() const;				//File path used to create the image
		CVector2Di GetSize() const;					//Width & height of the image
		ZColor GetPixelColor(int p_nPixelX, int p_nPixelY) const;
		ZColor GetPixelColor(const CVector2Di & p_nPixelPos) const;

		//Setters
		void SetPixelColor(int p_nPixelX, int p_nPixelY, const ZColor & p_PixelColor);
		void SetPixelColor(const CVector2Di & p_nPixelPos, const ZColor & p_PixelColor);

		//Friend zone
		friend CZRessourceImageManager;
		friend CZTexture;
	};
}