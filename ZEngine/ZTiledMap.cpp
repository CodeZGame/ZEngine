//-----------------------------------------------------------
// ZTiledMap.cpp
//-----------------------------------------------------------

#include "ZAssert.h"
#include "ZTiledMap.h"
#include "ZTiledMapLoader.h"

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
	for (auto ptr : m_vDataLayers)
		delete ptr;
	for (auto ptr : m_vDataTilesets)
		delete ptr;
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