//-----------------------------------------------------------
// ZTiledMap.h
//-----------------------------------------------------------

#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics/VertexArray.hpp>
#include "Vector2D.hpp"

namespace ZEngine
{
	class CZTiledMapManager;

	enum class ZTiledMapType
	{
		e_TiledType_Unknown,
		e_TiledType_Orthogonal,
		e_TiledType_Isometric,
		e_TiledType_Hexagonal,

		e_TiledType_Number,
	};

	class CZTiledMap
	{
	protected:
		struct ZDataLayer
		{
			std::string m_sLayerName;
			std::string m_sTilesetName;

			CVector2Di m_nLayerSize;
			int * m_pData;
		};

		struct ZDataTileset
		{
			std::string m_sTilesetName;

			int m_nTilesetFirstGid;
			CVector2Di m_nTileSize;
			int m_nSpacing;
			int m_nMargin;

			std::string m_sImageSource;
			int m_nImageWidth;
			int m_nImageHeight;
		};

		std::vector<sf::VertexArray *> m_vVertexArray;

		std::string m_sMapName;

		ZTiledMapType m_eType;

		CVector2Di m_nMapSize;
		CVector2Di m_nMapTileSize;

		std::vector<ZDataLayer *> m_vDataLayers;
		std::vector<ZDataTileset *> m_vDataTilesets;

		CZTiledMap();

		bool CreateMap();

		//Setters
		void SetName(const std::string & p_pMapName);
		void SetType(ZTiledMapType p_eType);
		void SetSize(const CVector2Di p_nMapSize);
		void SetTileSize(const CVector2Di p_nTileSize);

		void AddNewLayer(ZDataLayer * p_pNewLayer);
		void AddNewTileset(ZDataTileset * p_pNewTileset);

	public:
		~CZTiledMap();

		//Getters
		const std::string & GetName() const { return m_sMapName; }

		//Friend Zone
		friend class CZTiledMapManager;
	};
}