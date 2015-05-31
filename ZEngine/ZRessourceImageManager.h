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
		static std::map<std::string, CZRessourceImage *> ms_vpRessourceImage;				//For now use a map (if need better perf, could use vector)

		CZRessourceImageManager();

	public:
		~CZRessourceImageManager();

		static CZRessourceImage * LoadImageRessource(const std::string & p_pFilePath);
		static CZRessourceImage * LoadImageRessource(const std::string & p_pFilePath, CZRessourceImage * p_pRessourceImage);

		static CZRessourceImage * GetRessourceImage(const std::string & p_pFilePath);
	};
}