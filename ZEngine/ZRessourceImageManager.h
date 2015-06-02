//-----------------------------------------------------------
// ZRessourceImageManager.h
//---------------------------------------------------------

#pragma once

#include <vector>
#include <map>

#include "ZRessourceImage.h"

namespace ZEngine
{
	class CZRessourceImageManager
	{
	protected:
		//static std::vector<CZRessourceImage *> ms_vpRessourceImage;
		static std::map<std::string, CZRessourceImage *> ms_vpRessourceImage;

		static std::vector<const std::string> ms_vpRessourcePaths;								//Store all possible data path for image loading

		CZRessourceImageManager();

		static CZRessourceImage * TryLoadFromAllDataPaths(const std::string & p_pFileName);

		static CZRessourceImage * DoLoadImageRessource(const std::string & p_pFilePath);

	public:
		~CZRessourceImageManager();

		static CZRessourceImage * LoadImageRessource(const std::string & p_pFilePath);
		static CZRessourceImage * LoadImageRessource(const std::string & p_pFilePath, CZRessourceImage * p_pRessourceImage);

		static CZRessourceImage * LoadImageRessourceFromPath(const std::string & p_pFileName, const std::string & p_pPath);

		static CZRessourceImage * GetRessourceImage(const std::string & p_pFilePath);

		static void AddDataPath(const std::string & p_pDataPath);

		static void RemoveDataPath(const std::string & p_pDataPath);
	};
}