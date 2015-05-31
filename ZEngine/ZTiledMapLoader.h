//-----------------------------------------------------------
// ZTiledMapLoader.h
//-----------------------------------------------------------

#pragma once

#include <string>
#include <map>

#include "ZTiledMap.h"

#include "..\..\tinyxml2-master\tinyxml2.h"

namespace ZEngine
{
	class CZTiledMapLoader
	{
	protected:
		static std::map<std::string, CZTiledMap *> ms_TileMaps;

		CZTiledMapLoader();

		static bool RetrieveMapInfo(tinyxml2::XMLElement * p_pMapRoot, CZTiledMap * p_pTiledMap);
		static bool RetrieveTilesetInfo(tinyxml2::XMLElement * p_pTilesetFirstElement, CZTiledMap * p_pTiledMap);
		static bool RetrieveData(tinyxml2::XMLElement * p_pDataElement, CZTiledMap::ZDataLayer * p_pDataLayer, int p_nbTiles);
		static bool RetrieveLayerInfo(tinyxml2::XMLElement * p_pLayerFirstElement, CZTiledMap * p_pTiledMap);

	public:
		~CZTiledMapLoader();

		static bool ParseMapFromFile(const std::string & p_pMapPath, const std::string & p_pMapName);

		static bool LoadMap(const std::string & p_pMapPath);
	};
}