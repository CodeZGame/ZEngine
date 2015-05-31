//-----------------------------------------------------------
// ZTextureManager.cpp
//---------------------------------------------------------

#include "ZAssert.h"
#include "ZDebug.h"
#include "ZTextureManager.h"
#include "ZRessourceImageManager.h"

using namespace ZEngine;

//-----------------------------------------------------------
//Static
//----------------------------------------------------------
std::map<std::string, CZTexture *> CZTextureManager::ms_vpTextures;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZTextureManager :: CZTextureManager()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZTextureManager :: ~CZTextureManager()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZTexture * CZTextureManager :: CreateTexture(const std::string & p_pFilePath)
{
	CZRessourceImage * pImage = CZRessourceImageManager::GetRessourceImage(p_pFilePath);

	if (pImage)
	{
		CZTexture * pNewTexture = new CZTexture();
		if (pNewTexture->LoadFromImage(pImage))
		{
			ms_vpTextures.insert(std::pair<std::string, CZTexture *>(p_pFilePath, pNewTexture));
			return pNewTexture;
		}
		else
		{
			delete pNewTexture;
		}
	}
	else
	{
		CZDebug::LogError("Cannot create texture from image: %s");
	}
	return nullptr;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZTexture * CZTextureManager :: CreateTexture(const CZRessourceImage * p_pImage)
{
	ZVALIDPOINTER(p_pImage);

	CZTexture * pNewTexture = new CZTexture();
	if (pNewTexture->LoadFromImage(p_pImage))
	{
		ms_vpTextures.insert(std::pair<std::string, CZTexture *>(p_pImage->GetFilePath(), pNewTexture));
		return pNewTexture;
	}
	else
	{
		delete pNewTexture;
	}
	return nullptr;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZTexture * CZTextureManager :: GetTexture(const std::string & p_pFilePath)
{
	//Check if texture exist
	std::map<std::string, CZTexture *>::const_iterator itTexture = ms_vpTextures.find(p_pFilePath);

	if (itTexture != ms_vpTextures.end())
	{
		return itTexture->second;
	}
	else
	{
		CZDebug::LogError("Texture: %s has not been created", p_pFilePath);
		ZASSERT(0);
		return nullptr;
	}
}