//-----------------------------------------------------------
// ZRessourceImageManager.cpp
//----------------------------------------------------------

#include <algorithm>

#include "ZAssert.h"
#include "ZRessourceImageManager.h"
#include "ZSFMLConvert.h"
#include "ZDebug.h"

using namespace ZEngine;


//-----------------------------------------------------------
// Static
//-----------------------------------------------------------
std::map<std::string , CZRessourceImage*> CZRessourceImageManager::ms_vpRessourceImage;
std::vector<const std::string> CZRessourceImageManager::ms_vpRessourcePaths;

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
CZRessourceImage * CZRessourceImageManager :: TryLoadFromAllDataPaths(const std::string & p_pFileName)
{
	CZRessourceImage * pImage = nullptr;
	
	for (const std::string & sPath : ms_vpRessourcePaths)
	{
		pImage = LoadImageRessourceFromPath(p_pFileName, sPath);

		if (pImage != nullptr)
			break;
	}
	return pImage;
}

//-----------------------------------------------------------
//Load ressource from specified path
//-----------------------------------------------------------
CZRessourceImage * CZRessourceImageManager :: DoLoadImageRessource(const std::string & p_pFilePath)
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
		CZDebug::LogError("Failed to load image from: %s", &p_pFilePath);
		delete pNewImage;
		return nullptr;
	}
}

//-----------------------------------------------------------
//Try to load image from current path, or try path set by user
//-----------------------------------------------------------
CZRessourceImage * CZRessourceImageManager :: LoadImageRessource(const std::string & p_pFilePath)
{
	CZRessourceImage * pNewImage = nullptr;

	pNewImage = DoLoadImageRessource(p_pFilePath);

	if (pNewImage == nullptr)
	{
		pNewImage = TryLoadFromAllDataPaths(p_pFilePath);
	}
	return pNewImage;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRessourceImage * CZRessourceImageManager :: LoadImageRessource(const std::string & p_pFilePath, CZRessourceImage * p_pRessourceImage)
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
// Load ressource from specified path (also try path without all sub folders in p_pFileName
//-----------------------------------------------------------
CZRessourceImage * CZRessourceImageManager :: LoadImageRessourceFromPath(const std::string & p_pFileName, const std::string & p_pPath)
{
	std::string sFullPath(p_pPath);

	if (!sFullPath.empty() && sFullPath[sFullPath.size() - 1] != '\\' && sFullPath[sFullPath.size() - 1] != '/')
	{
		sFullPath.append("\\");
	}

	sFullPath.append(p_pFileName);

	if (CZFileHandler::FileExists(sFullPath))
		return DoLoadImageRessource(sFullPath);
	else
	{
		//Try to remove all previous folder in the name
		size_t slashPos = sFullPath.find_last_of("/\\");

		if (slashPos != std::string::npos && slashPos != sFullPath.size())
		{
			sFullPath = sFullPath.substr(slashPos + 1);
			return DoLoadImageRessource(sFullPath);
		}
	}
	return nullptr;
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

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRessourceImageManager :: AddDataPath(const std::string & p_pDataPath)
{
	ZASSERT(!p_pDataPath.empty());
	ms_vpRessourcePaths.push_back(p_pDataPath);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRessourceImageManager :: RemoveDataPath(const std::string & p_pDataPath)
{
	auto itRemove = std::find(ms_vpRessourcePaths.begin(), ms_vpRessourcePaths.end(), p_pDataPath);

	if (itRemove != ms_vpRessourcePaths.end())
		ms_vpRessourcePaths.erase(itRemove);
}