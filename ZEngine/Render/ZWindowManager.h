//-----------------------------------------------------------
// ZWindowManager.h
//----------------------------------------------------------

#pragma once

#define ZENGINE_MAX_WINDOW	2

#include "../ZView.h"

namespace ZEngine
{
	class CZWindow;

	class CZWindowManager
	{
	private:
		static CZWindow ms_pWindows[ZENGINE_MAX_WINDOW];

		static unsigned int ms_uNbWindowActive;

		CZWindowManager();
		~CZWindowManager();

	public:

		static CZWindow & GetWindow(unsigned int p_uWindowIndex);

		static void InitWindow(unsigned int p_uWindowIndex, const int p_nWith, const int p_nHeight, const char * p_tWindowName = "ZEngine");

		static bool ProcessAllWindowsEvents();
		static void ProcessAllWindowsDraw();

		//static bool ProcessWindow(unsigned int p_uWindowIndex);
	};
}