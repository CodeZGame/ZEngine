//-----------------------------------------------------------
// ZInit.cpp
//----------------------------------------------------------

#include <cassert>
#include "ZInit.h"
#include "ZFileHandler.h"
#include "ZDebug.h"
#include "ZFontManager.h"

using namespace ZEngine;

void ZEngine::InitEngine()
{
	if (!CZFileHandler::FileExists("arial.ttf"))
	{
		assert(0 && "Missing default font file");
	}
	else
	{
		ZEngine::CZFontManager::LoadFromFile("arial.ttf");
	}

	CZDebug::Init();
}