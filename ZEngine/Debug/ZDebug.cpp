//-----------------------------------------------------------
// ZDebug.cpp
//-----------------------------------------------------------

#include <cstdio>
#include <cstdarg>
#include <assert.h>
#include "../Types/Vector2D.hpp"
#include "../Debug/ZDebug.h"
#include "../Ressources/ZShape.h"
#include "../Texts/ZText.h"
#include "../Texts/ZFontManager.h"


using namespace ZEngine;

#define DEBUG_LOG_FILE_NAME		"Zlog.txt"

//-----------------------------------------------------------
// Static
//-----------------------------------------------------------
CZShape CZDebug::ms_DebugCircleShapes[ZENGINE_MAX_DEBUG_SHAPES];
CZShape CZDebug::ms_DebugRectangleShapes[ZENGINE_MAX_DEBUG_SHAPES];
CZText CZDebug::ms_DebugTexts[ZENGINE_MAX_DEBUG_TEXTS];

int CZDebug::ms_nNbDebugCircleShapes = 0;
int CZDebug::ms_nNbDebugRectangleShapes = 0;
int CZDebug::ms_nNbDebugTexts = 0;

char CZDebug::ms_pTextBuffer[ZENGINE_TEXT_BUFFER];
float CZDebug::ms_fCurrentHeight = 0.0f;

std::vector<int *> CZDebug::ms_pnDebugVars;
std::vector<float *> CZDebug::ms_pfDebugVars;

CZFileHandler CZDebug::ms_LogFile(DEBUG_LOG_FILE_NAME, FileOpenFlag::e_OpenFlag_Write);

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZDebug :: CZDebug()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZDebug :: ~CZDebug()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZDebug :: Init()
{
	int i;

	for (i = 0; i < ZENGINE_MAX_DEBUG_SHAPES; ++i)
	{
		ms_DebugCircleShapes[i].SetDebug(true);
		ms_DebugCircleShapes[i].m_psfmlShape = new sf::CircleShape(5.0f);
		ms_DebugCircleShapes[i].m_psfmlDrawable = static_cast<sf::Shape *>(ms_DebugCircleShapes[i].m_psfmlShape);

		ms_DebugRectangleShapes[i].SetDebug(true);
		ms_DebugRectangleShapes[i].m_psfmlShape = new sf::RectangleShape(sf::Vector2f(0.0f, 0.0f));
		ms_DebugRectangleShapes[i].m_psfmlDrawable = static_cast<sf::Shape *>(ms_DebugRectangleShapes[i].m_psfmlShape);
	}

	for (i = 0; i < ZENGINE_MAX_DEBUG_SHAPES; ++i)
	{
		ms_DebugTexts[i].m_psfmlText = new sf::Text();
		ms_DebugTexts[i].m_psfmlDrawable = ms_DebugTexts[i].m_psfmlText;
	}

	Reset();
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZDebug :: Reset()
{
	int i;

	for (i = 0; i < ZENGINE_MAX_DEBUG_SHAPES; ++i)
	{
		ms_DebugRectangleShapes[i].SetActive(false);
		ms_DebugCircleShapes[i].SetActive(false);
	}

	sf::Font * pDebugFont = CZFontManager::GetFontByName("arial");

	for (i = 0; i < ZENGINE_MAX_DEBUG_TEXTS; ++i)
	{
		ms_DebugTexts[i].SetDebug(true);
		ms_DebugTexts[i].SetActive(false);
		ms_DebugTexts[i].SetFont(pDebugFont);
	}

	ms_nNbDebugCircleShapes = 0;
	ms_nNbDebugRectangleShapes = 0;
	ms_nNbDebugTexts = 0;
	ms_fCurrentHeight = 0;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZDebug :: DrawCircle(CVector2Df p_fPos, float p_fRadius, ZColor p_Color)
{
	assert(ms_nNbDebugCircleShapes < ZENGINE_MAX_DEBUG_SHAPES && "Max debug circle shapes limit reached");
	ms_DebugCircleShapes[ms_nNbDebugCircleShapes].SetDebug(true);

	ms_DebugCircleShapes[ms_nNbDebugCircleShapes].Reset();
	ms_DebugCircleShapes[ms_nNbDebugCircleShapes].SetShapeType(ZShapeType::e_Shape_Circle);

	ms_DebugCircleShapes[ms_nNbDebugCircleShapes].SetPosition(p_fPos);
	ms_DebugCircleShapes[ms_nNbDebugCircleShapes].SetShapeInfo(p_fRadius);
	ms_DebugCircleShapes[ms_nNbDebugCircleShapes].SetThickness(1.0f);
	ms_DebugCircleShapes[ms_nNbDebugCircleShapes].SetOutterColor(p_Color);

	p_Color.a = 0;
	ms_DebugCircleShapes[ms_nNbDebugCircleShapes].SetInnerColor(p_Color);
	++ms_nNbDebugCircleShapes;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZDebug :: DrawRectangle(CVector2Df p_fPos, CVector2Df p_fSize, ZColor p_Color)
{
	assert(ms_nNbDebugRectangleShapes < ZENGINE_MAX_DEBUG_SHAPES && "Max debug rectangle shapes limit reached");
	ms_DebugRectangleShapes[ms_nNbDebugRectangleShapes].SetDebug(true);

	ms_DebugRectangleShapes[ms_nNbDebugRectangleShapes].Reset();
	ms_DebugRectangleShapes[ms_nNbDebugRectangleShapes].SetShapeType(ZShapeType::e_Shape_Rectangle);

	ms_DebugRectangleShapes[ms_nNbDebugRectangleShapes].SetPosition(p_fPos);
	ms_DebugRectangleShapes[ms_nNbDebugRectangleShapes].SetShapeInfo(p_fSize);
	
	ms_DebugRectangleShapes[ms_nNbDebugRectangleShapes].SetThickness(1.0f);
	ms_DebugRectangleShapes[ms_nNbDebugRectangleShapes].SetOutterColor(p_Color);
	p_Color.a = 0;
	ms_DebugRectangleShapes[ms_nNbDebugRectangleShapes].SetInnerColor(p_Color);
	++ms_nNbDebugRectangleShapes;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZDebug :: AddVar(const char * p_sText, int * p_pnVar)
{
	ms_pnDebugVars.push_back(p_pnVar);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZDebug :: AddVar(const char * p_sText, float * p_pfVar)
{
	ms_pfDebugVars.push_back(p_pfVar);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZDebug :: ChangeLogFile(const std::string & p_sFilePath)
{

}