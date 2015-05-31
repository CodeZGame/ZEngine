//-----------------------------------------------------------
// ZTexture.h
//---------------------------------------------------------

#pragma once

#include <SFML\Graphics\Texture.hpp>

#include "ZRessourceImage.h"

namespace ZEngine
{
	class CZTextureManager;
	class CZSprite;

	class CZTexture
	{
	protected:
		static std::string ms_ErrorString;

		sf::Texture m_sfmlTexture;

		bool m_bIsSmooth;

		const CZRessourceImage * m_pImage;

		CZTexture();

	public:
		~CZTexture();

		bool LoadFromImage(const CZRessourceImage * p_pImage, const CVector2Di p_pnAreaPos = CVector2Di::Zero, const CVector2Di p_pnAreaSize = CVector2Di::Zero);

		//Getters
		const std::string & GetImageName() const;
		bool IsSmooth() const { return m_bIsSmooth; }

		//Setters
		void SetSmooth(bool p_bSmooth);

		friend class CZTextureManager;
		friend class CZSprite;
	};
}