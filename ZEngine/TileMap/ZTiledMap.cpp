//-----------------------------------------------------------
// ZTiledMap.cpp
//-----------------------------------------------------------

#include "../Debug/ZAssert.h"
#include "../Ressources/ZRessourceImageManager.h"
#include "ZTiledMap.h"
#include "CZTiledMapManager.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZTiledMap :: CZTiledMap()
	: m_sMapName("DefaultMapName"), m_eType(ZTiledMapType::e_TiledType_Unknown),
	m_nMapSize(CVector2Di::Zero), m_nMapTileSize(CVector2Di::Zero)
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZTiledMap :: ~CZTiledMap()
{
	for (auto dataLayer : m_vDataLayers)
	{
		delete dataLayer;
		dataLayer = nullptr;
	}
	for (auto dataTileset : m_vDataTilesets)
	{
		delete dataTileset;
		dataTileset = nullptr;
	}
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZTiledMap :: CreateMap()
{
	//Load all tileset
	for (ZDataTileset * pTileSetData : m_vDataTilesets)
	{
		ZEngine::CZRessourceImage * img = CZRessourceImageManager::LoadImageRessourceFromPath(pTileSetData->m_sImageSource, "./");
	}
	return true;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZTiledMap :: SetName(const std::string & p_pMapName)
{
	m_sMapName = p_pMapName;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZTiledMap :: SetType(ZTiledMapType p_eType)
{
	m_eType = p_eType;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZTiledMap :: SetSize(const CVector2Di p_nMapSize)
{
	m_nMapSize = p_nMapSize;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZTiledMap :: SetTileSize(const CVector2Di p_nTileSize)
{
	m_nMapTileSize = p_nTileSize;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZTiledMap::AddNewLayer(ZDataLayer * p_pNewLayer)
{
	ZVALIDPOINTER(p_pNewLayer);
	m_vDataLayers.push_back(p_pNewLayer);
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZTiledMap :: AddNewTileset(ZDataTileset * p_pNewTileset)
{
	ZVALIDPOINTER(p_pNewTileset);
	m_vDataTilesets.push_back(p_pNewTileset);
}