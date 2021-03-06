//-----------------------------------------------------------
// ZDebug.h
//-----------------------------------------------------------

#pragma once

//Must be included before windows.h
#include "../Tinyformat/tinyformat.h"

#if defined _WIN32 || defined _WIN64
#include <windows.h>
#endif

#include <sstream>

#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Text.hpp>

#include "../Render/ZWindow.h"
#include "../ZStarter.h"
#include "../Render/ZWindowManager.h"
#include "../Render/ZRenderer.h"
#include "../Types/Vector2D.hpp"
#include "../File/ZFileHandler.h"
#include "../Texts/ZText.h"
#include "../Types/ZColor.h"

#define ZENGINE_MAX_DEBUG_SHAPES	256
#define ZENGINE_MAX_DEBUG_TEXTS		512
#define ZENGINE_TEXT_BUFFER			512

namespace ZEngine
{
	class CZShape;

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

		static void FreeRessources();

		CZDebug();

	public:
		~CZDebug();
		
		// Draw debug shapes
		static void DrawCircle(CVector2Df p_fPos, float p_fRadius, ZColor p_Color = ZColor::White());
		static void DrawRectangle(CVector2Df p_fPos, CVector2Df p_fSize = CVector2Df(10.0f, 10.0f), ZColor p_Color = ZColor::White());

		static void Init();

		static void Reset();

		static void AddVar(const char * p_sText, int * p_pnVar);
		static void AddVar(const char * p_sText, float * p_pfVar);

		// Draw debug texts
		//-----------------------------------------------------------
		//
		//-----------------------------------------------------------
		template<typename... Args>
		static void AddText(const char * p_sText, Args... args)
		{
			assert(ms_nNbDebugTexts < ZENGINE_MAX_DEBUG_TEXTS && "Max debug texts limit reached");

			ms_DebugTexts[ms_nNbDebugTexts].Reset();

			ms_DebugTexts[ms_nNbDebugTexts].SetText(tfm::format(p_sText, args...));

			ms_DebugTexts[ms_nNbDebugTexts].SetPosition(CVector2Df(0.0f, ms_fCurrentHeight));
			ms_fCurrentHeight += ms_DebugTexts[ms_nNbDebugTexts].m_psfmlText->getLocalBounds().height * 1.1f;
			++ms_nNbDebugTexts;
		}

		//-----------------------------------------------------------
		//
		//-----------------------------------------------------------
		template<typename... Args>
		static void AddTextLog(const char * p_sText, Args... args)
		{
			//For now simply log to file
			//Will need to log to "second" debug screen

			std::string tmp = tfm::format(p_sText, args...);
			ms_LogFile.Write(tmp);
		}



		//-----------------------------------------------------------
		//
		//-----------------------------------------------------------
		template<typename... Args>
		static void LogToFile(const char * p_sText, Args... args)
		{
			std::string tmp = tfm::format(p_sText, args...);
			ms_LogFile.Write(tmp);
		}

		//-----------------------------------------------------------
		//
		//-----------------------------------------------------------
		template<typename... Args>
		static void LogWarning(const char * p_sText, Args... args)
		{
			std::string tmp("Warning: ");
			tmp.append(tfm::format(p_sText, args...));
			ms_LogFile.Write(tmp);

#if defined _WIN32 || defined _WIN64
			std::wstring sTemp = std::wstring(tmp.begin(), tmp.end());
			OutputDebugString(sTemp.c_str());
#endif
		}

		//-----------------------------------------------------------
		//
		//-----------------------------------------------------------
		template<typename... Args>
		static void LogError(const char * p_sText, Args... args)
		{
			std::string tmp("----------- ERROR -----------\n");
			tmp.append(tfm::format(p_sText, args...));
			tmp.append("-----------------------------\n");
			ms_LogFile.Write(tmp);

#if defined _WIN32 || defined _WIN64
			std::wstring sTemp = std::wstring(tmp.begin(), tmp.end());
			OutputDebugString(sTemp.c_str());
#endif
		}

		//Logs to file
		static void ChangeLogFile(const std::string & p_sFilePath);

		// Friend zone
		friend void CZRenderer::ProcessDrawDebug();
		friend void CZStarter::EngineReleaseRessources();
	};

}