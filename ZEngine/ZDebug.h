//-----------------------------------------------------------
// ZDebug.h
//-----------------------------------------------------------

#pragma once

#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Text.hpp>

#include "ZWindow.h"
#include "ZWindowManager.h"
#include "ZRenderer.h"
#include "Vector2D.hpp"
#include "ZFileHandler.h"
#include "ZColor.h"

#define ZENGINE_MAX_DEBUG_SHAPES	256
#define ZENGINE_MAX_DEBUG_TEXTS		512
#define ZENGINE_TEXT_BUFFER			512

namespace ZEngine
{
	class CZShape;
	class CZText;

	class CZDebug
	{
	protected:
		static CZFileHandler ms_LogFile;

		static CZShape ms_DebugCircleShapes[ZENGINE_MAX_DEBUG_SHAPES];
		static int ms_nNbDebugCircleShapes;

		static CZShape ms_DebugRectangleShapes[ZENGINE_MAX_DEBUG_SHAPES];
		static int ms_nNbDebugRectangleShapes;

		static CZText ms_DebugTexts[ZENGINE_MAX_DEBUG_TEXTS];
		static int ms_nNbDebugTexts;
		
		static char ms_pTextBuffer[ZENGINE_TEXT_BUFFER];
		static float ms_fCurrentHeight;

		static std::vector<int *> ms_pnDebugVars;
		static std::vector<float *> ms_pfDebugVars;

		CZDebug();

	public:
		~CZDebug();
		
		// Draw debug shapes
		static void DrawCircle(CVector2Df p_fPos, float p_fRadius, ZColor p_Color = ZColor::White());
		static void DrawRectangle(CVector2Df p_fPos, CVector2Df p_fSize = CVector2Df(10.0f, 10.0f), ZColor p_Color = ZColor::White());

		static void Init();

		static void Reset();

		// Draw debug texts
		static void AddText(const char * p_sText, ...);

		static void AddTextLog(const char * p_sText, ...);

		static void AddVar(const char * p_sText, int * p_pnVar);

		static void AddVar(const char * p_sText, float * p_pfVar);

		//Logs to file
		static void ChangeLogFile(const std::string & p_sFilePath);

		static void LogToFile(const char * p_sText, ...);

		static void LogError(const char * p_sText, ...);

		static void LogWarning(const char * p_sText, ...);


		// Friend zone
		friend void CZRenderer::ProcessDrawDebug();
	};

}