//-----------------------------------------------------------
// ZTiledMapLoader.cpp
//-----------------------------------------------------------

#include "ZAssert.h"
#include "ZDebug.h"
#include "ZTiledMap.h"
#include "ZTiledMapLoader.h"

//XML MAP INFO
#define XML_MAP_ELEMENT_NAME			"map"
#define XML_ATTRIBUTE_MAP_ORIENTATION	"orientation"
#define XML_ATTRIBUTE_MAP_WIDTH			"width"
#define XML_ATTRIBUTE_MAP_HEIGHT		"height"
#define XML_ATTRIBUTE_MAP_TILEWIDTH		"tilewidth"
#define XML_ATTRIBUTE_MAP_TILEHEIGHT	"tileheight"

//XML TILESET INFO
#define XML_TILESET_ELEMENT_NAME			"tileset"
#define XML_ATTRIBUTE_TILESET_FIRSTGID		"firstgid"
#define XML_ATTRIBUTE_TILESET_NAME			"name"
#define XML_ATTRIBUTE_TILESET_TILEWIDTH		"tilewidth"
#define XML_ATTRIBUTE_TILESET_TILEHEIGHT	"tileheight"
#define XML_ATTRIBUTE_TILESET_SPACING		"spacing"
#define XML_ATTRIBUTE_TILESET_MARGIN		"margin"

//XML TILESET IMAGE INFO
#define XML_IMAGE_ELEMENT_NAME				"image"
#define XML_ATTRIBUTE_IMAGE_SOURCE			"source"
#define XML_ATTRIBUTE_IMAGE_WIDTH			"width"
#define XML_ATTRIBUTE_IMAGE_HEIGHT			"height"


//XML LAYER INFO
#define XML_LAYER_ELEMENT_NAME			"layer"
#define XML_ATTRIBUTE_LAYER_NAME		"name"
#define XML_ATTRIBUTE_LAYER_WIDTH		"width"
#define XML_ATTRIBUTE_LAYER_HEIGHT		"height"

//XML DATA INFO
#define XML_DATA_ELEMENT_NAME			"data"
#define XML_TILE_ELEMENT_NAME			"tile"
#define XML_ATTRIBUTE_TILE_GID			"gid"

using namespace ZEngine;

//-----------------------------------------------------------
//Static
//---------------------------------------------------------
std::map<std::string, CZTiledMap *> CZTiledMapLoader::ms_TileMaps;

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZTiledMapLoader :: CZTiledMapLoader()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZTiledMapLoader :: ~CZTiledMapLoader()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZTiledMapLoader :: ParseMapFromFile(const std::string & p_pMapPath, const std::string & p_pMapName)
{
	tinyxml2::XMLDocument xmlMap;

	tinyxml2::XMLError eResult = xmlMap.LoadFile(p_pMapPath.c_str());

	if (eResult != tinyxml2::XML_SUCCESS)
	{
		CZDebug::LogError("TiledMapLoader failed to load map from file: %s", p_pMapPath);
		return false;
	}

	//Retrieve map element
	tinyxml2::XMLElement *pRoot = xmlMap.FirstChildElement(XML_MAP_ELEMENT_NAME);

	if (pRoot == nullptr)
	{
		CZDebug::LogError("TiledMapLoader failed to load first child from file: %s", p_pMapPath);
		return false;
	}

	CZTiledMap * pTiledMap = new CZTiledMap();

	pTiledMap->SetName(p_pMapName);

	if (!RetrieveMapInfo(pRoot, pTiledMap))
	{
		CZDebug::LogError("Failed to retrieve map info for map: %s", p_pMapPath);
		delete pTiledMap;
		return false;
	}

	tinyxml2::XMLElement *pTilesetRoot = pRoot->FirstChildElement(XML_TILESET_ELEMENT_NAME);

	if (!RetrieveTilesetInfo(pTilesetRoot, pTiledMap))
	{
		CZDebug::LogError("Failed to retrieve tileset info for map: %s", p_pMapPath);
		delete pTiledMap;
		return false;
	}

	tinyxml2::XMLElement *pLayerRoot = pRoot->FirstChildElement(XML_LAYER_ELEMENT_NAME);

	if (!RetrieveLayerInfo(pLayerRoot, pTiledMap))
	{
		CZDebug::LogError("Failed to retrieve layer info for map: %s", p_pMapPath);
		delete pTiledMap;
		return false;
	}

	ms_TileMaps.insert(std::pair<std::string, CZTiledMap *>(p_pMapName, pTiledMap));
	return true;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZTiledMapLoader :: RetrieveMapInfo(tinyxml2::XMLElement * p_pMapRoot, CZTiledMap * p_pTiledMap)
{
	const char * sMapOrientation = p_pMapRoot->Attribute(XML_ATTRIBUTE_MAP_ORIENTATION);

	if (sMapOrientation == nullptr)
		return false;
	else if (strcmp(sMapOrientation, "orthogonal") == 0)
		p_pTiledMap->SetType(ZTiledMapType::e_TiledType_Orthogonal);
	else if (strcmp(sMapOrientation, "isometric") == 0)
		p_pTiledMap->SetType(ZTiledMapType::e_TiledType_Isometric);
	else if (strcmp(sMapOrientation, "hexagonal") == 0)
		p_pTiledMap->SetType(ZTiledMapType::e_TiledType_Hexagonal);
	else
		p_pTiledMap->SetType(ZTiledMapType::e_TiledType_Unknown);

	int nMapWidth, nMapHeight;
	tinyxml2::XMLError eResult;
	
	//Retrieve map size
	eResult = p_pMapRoot->QueryIntAttribute(XML_ATTRIBUTE_MAP_WIDTH, &nMapWidth);
	if (eResult != tinyxml2::XML_SUCCESS)
		return false;

	eResult = p_pMapRoot->QueryIntAttribute(XML_ATTRIBUTE_MAP_HEIGHT, &nMapHeight);
	if (eResult != tinyxml2::XML_SUCCESS)
		return false;

	p_pTiledMap->SetSize(CVector2Di(nMapWidth, nMapHeight));

	//Retrieve tile size
	eResult = p_pMapRoot->QueryIntAttribute(XML_ATTRIBUTE_MAP_TILEWIDTH, &nMapWidth);
	if (eResult != tinyxml2::XML_SUCCESS)
		return false;

	eResult = p_pMapRoot->QueryIntAttribute(XML_ATTRIBUTE_MAP_TILEHEIGHT, &nMapHeight);
	if (eResult != tinyxml2::XML_SUCCESS)
		return false;

	p_pTiledMap->SetTileSize(CVector2Di(nMapWidth, nMapHeight));

	return true;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZTiledMapLoader :: RetrieveTilesetInfo(tinyxml2::XMLElement * p_pTilesetFirstElement, CZTiledMap * p_pTiledMap)
{
	ZVALIDPOINTER(p_pTilesetFirstElement);
	ZVALIDPOINTER(p_pTiledMap);

	tinyxml2::XMLError eResult;

	CZTiledMap::ZDataTileset * pTilesetInfo = new CZTiledMap::ZDataTileset();

	eResult = p_pTilesetFirstElement->QueryIntAttribute(XML_ATTRIBUTE_TILESET_FIRSTGID, &pTilesetInfo->m_nTilesetFirstGid);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pTilesetInfo;
		return false;
	}

	const char * sTilesetName = p_pTilesetFirstElement->Attribute(XML_ATTRIBUTE_TILESET_NAME);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pTilesetInfo;
		return false;
	}
	pTilesetInfo->m_sTilesetName = sTilesetName;

	eResult = p_pTilesetFirstElement->QueryIntAttribute(XML_ATTRIBUTE_TILESET_TILEWIDTH, &pTilesetInfo->m_nTileSize.x);
	if (eResult != tinyxml2::XML_SUCCESS)
		return false;

	eResult = p_pTilesetFirstElement->QueryIntAttribute(XML_ATTRIBUTE_TILESET_TILEHEIGHT, &pTilesetInfo->m_nTileSize.y);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pTilesetInfo;
		return false;
	}

	eResult = p_pTilesetFirstElement->QueryIntAttribute(XML_ATTRIBUTE_TILESET_SPACING, &pTilesetInfo->m_nSpacing);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pTilesetInfo;
		return false;
	}

	eResult = p_pTilesetFirstElement->QueryIntAttribute(XML_ATTRIBUTE_TILESET_MARGIN, &pTilesetInfo->m_nMargin);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pTilesetInfo;
		return false;
	}

	//Retrieve tileset image info
	tinyxml2::XMLElement *pImageRoot = p_pTilesetFirstElement->FirstChildElement(XML_IMAGE_ELEMENT_NAME);
	if (pImageRoot == nullptr)
	{
		delete pTilesetInfo;
		return false;
	}

	const char * sTilesetImageSource = pImageRoot->Attribute(XML_ATTRIBUTE_IMAGE_SOURCE);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pTilesetInfo;
		return false;
	}
	pTilesetInfo->m_sImageSource = sTilesetImageSource;

	eResult = pImageRoot->QueryIntAttribute(XML_ATTRIBUTE_IMAGE_WIDTH, &pTilesetInfo->m_nImageWidth);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pTilesetInfo;
		return false;
	}

	eResult = pImageRoot->QueryIntAttribute(XML_ATTRIBUTE_IMAGE_HEIGHT, &pTilesetInfo->m_nImageHeight);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pTilesetInfo;
		return false;
	}

	p_pTiledMap->AddNewTileset(pTilesetInfo);

	//Get recursively next tileset elements
	tinyxml2::XMLElement *pNextTilesetElem = p_pTilesetFirstElement->NextSiblingElement(XML_TILESET_ELEMENT_NAME);
	if (pNextTilesetElem != NULL)
	{
		if (!RetrieveTilesetInfo(pNextTilesetElem, p_pTiledMap))
		{
			delete pTilesetInfo;
			return false;
		}
	}

	return true;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZTiledMapLoader :: RetrieveLayerInfo(tinyxml2::XMLElement * p_pLayerFirstElement, CZTiledMap * p_pTiledMap)
{
	ZVALIDPOINTER(p_pLayerFirstElement);
	ZVALIDPOINTER(p_pTiledMap);

	tinyxml2::XMLError eResult;

	CZTiledMap::ZDataLayer * pLayerInfo = new CZTiledMap::ZDataLayer();

	const char * sLayerName = p_pLayerFirstElement->Attribute(XML_ATTRIBUTE_LAYER_NAME);
	if (sLayerName == nullptr)
	{
		delete pLayerInfo;
		return false;
	}
	pLayerInfo->m_sTilesetName = sLayerName;

	eResult = p_pLayerFirstElement->QueryIntAttribute(XML_ATTRIBUTE_IMAGE_WIDTH, &pLayerInfo->m_nLayerSize.x);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pLayerInfo;
		return false;
	}

	eResult = p_pLayerFirstElement->QueryIntAttribute(XML_ATTRIBUTE_IMAGE_HEIGHT, &pLayerInfo->m_nLayerSize.y);
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		delete pLayerInfo;
		return false;
	}

	//Retrieve data
	tinyxml2::XMLElement *pDataRoot = p_pLayerFirstElement->FirstChildElement(XML_DATA_ELEMENT_NAME);
	if (pDataRoot == nullptr)
	{
		delete pLayerInfo;
		return false;
	}

	pLayerInfo->m_pData = new int[pLayerInfo->m_nLayerSize.x * pLayerInfo->m_nLayerSize.y];

	if (!RetrieveData(pDataRoot, pLayerInfo, pLayerInfo->m_nLayerSize.x * pLayerInfo->m_nLayerSize.y))
	{
		delete pLayerInfo->m_pData;
		delete pLayerInfo;
		return false;
	}

	//Get recursively next layer elements
	tinyxml2::XMLElement *pNextLayerElem = p_pLayerFirstElement->NextSiblingElement(XML_LAYER_ELEMENT_NAME);
	if (pNextLayerElem != NULL)
	{
		if (!RetrieveLayerInfo(pNextLayerElem, p_pTiledMap))
		{
			delete pLayerInfo->m_pData;
			delete pLayerInfo;
			return false;
		}
	}
	return true;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZTiledMapLoader::RetrieveData(tinyxml2::XMLElement * p_pDataElement, CZTiledMap::ZDataLayer * p_pDataLayer, int p_nbTiles)
{
	tinyxml2::XMLError eResult;

	tinyxml2::XMLElement * pTile = p_pDataElement->FirstChildElement(XML_TILE_ELEMENT_NAME);
	if (pTile == nullptr)
		return false;

	//Check Encodage

	//Data not encoded
	int nbParsedTiles = 0;

	do
	{
		eResult = pTile->QueryIntAttribute(XML_ATTRIBUTE_TILE_GID, &p_pDataLayer->m_pData[nbParsedTiles]);
		if (eResult != tinyxml2::XML_SUCCESS)
			return false;

		++nbParsedTiles;
	} while ((pTile = pTile->NextSiblingElement(XML_TILE_ELEMENT_NAME)) != nullptr && nbParsedTiles < p_nbTiles);

	if (nbParsedTiles != p_nbTiles)
	{
		CZDebug::LogWarning("Incorrect number of tiles in layer %s", p_pDataLayer->m_sLayerName);
	}
	return true;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZTiledMapLoader :: LoadMap(const std::string & p_pMapPath)
{
	return true;
}