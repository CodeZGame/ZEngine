//-----------------------------------------------------------
// ZRessourceImageManager.cpp
//----------------------------------------------------------

#include "ZAssert.h"
#include "ZRessourceImageManager.h"
#include "ZSFMLConvert.h"
#include "ZDebug.h"

using namespace ZEngine;

//-----------------------------------------------------------
// Static
//-----------------------------------------------------------
std::map<std::string , CZRessourceImage*> CZRessourceImageManager::ms_vpRessourceImage;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRessourceImageManager::CZRessourceImageManager()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRessourceImageManager::~CZRessourceImageManager()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRessourceImage * CZRessourceImageManager :: LoadImageRessource(const std::string & p_pFilePath)
{
	CZRessourceImage * pNewImage = new CZRessourceImage();

	ZMEMORYASSERT(pNewImage);

	bool bRes = pNewImage->m_sfmlImage.loadFromFile(p_pFilePath);

	if (bRes)
	{
		pNewImage->m_nImageSize = SfuVectorToZ(pNewImage->m_sfmlImage.getSize());
		ms_vpRessourceImage.insert(std::pair<std::string, CZRessourceImage *>(p_pFilePath, pNewImage));
		return pNewImage;
	}
	else
	{
		CZDebug::LogError("Failed to load image from: %s", p_pFilePath);
		delete pNewImage;
		return nullptr;
	}
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRessourceImage * CZRessourceImageManager::LoadImageRessource(const std::string & p_pFilePath, CZRessourceImage * p_pRessourceImage)
{
	ZVALIDPOINTER(p_pRessourceImage);

	bool bRes = p_pRessourceImage->m_sfmlImage.loadFromFile(p_pFilePath);

	if (bRes)
	{
		p_pRessourceImage->m_nImageSize = SfuVectorToZ(p_pRessourceImage->m_sfmlImage.getSize());
		ms_vpRessourceImage.insert(std::pair<std::string, CZRessourceImage *>(p_pFilePath, p_pRessourceImage));
	}
	else
	{
		CZDebug::LogError("Failed to load image from: %s", p_pFilePath);
	}

	return p_pRessourceImage;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRessourceImage * CZRessourceImageManager :: GetRessourceImage(const std::string & p_pFilePath)
{
	//Check if ressource has been loaded
	std::map<std::string, CZRessourceImage* >::const_iterator itImage = ms_vpRessourceImage.find(p_pFilePath);

	if (itImage != ms_vpRessourceImage.end())
	{
		return itImage->second;
	}
	else
	{
		CZDebug::LogError("RessourceImage: %s has not been loaded", p_pFilePath);
		ZASSERT(0);
		return nullptr;
	}
}