//-----------------------------------------------------------
// ZTextureManager.h
//---------------------------------------------------------

#pragma once

#include <map>
#include <SFML\Graphics\Texture.hpp>

#include "ZTexture.h"

namespace ZEngine
{
	class CZTextureManager
	{
	protected:
		static std::map<std::string, CZTexture *> ms_vpTextures;

		CZTextureManager();

	public:
		~CZTextureManager();

		static CZTexture * CreateTexture(const std::string & p_pFilePath);

		static CZTexture * CreateTexture(const CZRessourceImage * p_pImage);

		static CZTexture * GetTexture(const std::string & p_pFilePath);
	};
}