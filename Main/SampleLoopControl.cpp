//-----------------------------------------------------------
// SampleLoopControl.cpp
//-----------------------------------------------------------

/*
** This sample shows how to externalize the main loop outside
** the engine in case you need more control over your game ;)
*/

//Engine includes
#include "../ZEngine/Render/ZWindowManager.h"
#include "../ZEngine/ZTimeManager.h"
#include "../ZEngine/Debug/ZDebug.h"
#include "../ZEngine/Input/ZKeyboardHandler.h"
#include "../ZEngine/Input/ZMouseHandler.h"
#include "../ZEngine/Ressources/ZShape.h"
#include "../ZEngine/Types/Vector2D.hpp"
#include "../ZEngine/Types/ZColor.h"

//Project includes
#include "SampleLoopControl.h"

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void SampleLoopControl :: Init()
{
	//Call this first to ensure the engine is properly initialized
	ZEngine::CZStarter::InitEngine();

	//Create the actual circle shape
	ZEngine::CZShape * pCircle = ZEngine::CZShape::CreateCircleShape(CVector2Df(350.0f, 50.0f), 20.0f);
	pCircle->SetInnerColor(ZColor::Blue());

	//Initialize one window (you can have more if you want)
	ZEngine::CZWindow * window = ZEngine::CZWindowManager::InitWindow(0, 800, 600, "Sample Shape");

	//Set frame limit to 60
	window->SetFrameLimit(60);
}

//-----------------------------------------------------------
// Override the main loop
//-----------------------------------------------------------
void SampleLoopControl  :: StartMainLoop(void * p_pContext)
{
	bool bContinue = true;

	while (bContinue)
	{
		ZEngine::CZDebug::Reset();
		
		//Update the time for the game (like deltaTime, ...)
		ZEngine::CZTimeManager::UpdateTimeOnExternalLoop();
		
		//Update inputs
		ZEngine::CZMouseHandler::UpdateMouseInputOnExternalLoop();
		ZEngine::CZKeyboardHandler::UpdateKeyboardInputOnExternalLoop();

		//Process windows events
		bContinue = ZEngine::CZWindowManager::ProcessAllWindowsEvents();

		//If user close the window, false will be returned to quit properly
		if (!bContinue)
			break;

		bContinue = Update();

		//Process windows draw
		ZEngine::CZWindowManager::ProcessAllWindowsDraw();
	}

}

//-----------------------------------------------------------
// Called every frame
//-----------------------------------------------------------
bool SampleLoopControl :: Update(void * p_pContext)
{
	//Some common debug print
	ZEngine::CZDebug::AddText("frame (µs): %1.5f", ZEngine::CZTimeManager::GetFrameRenderTime());
	ZEngine::CZDebug::AddText("FPS : %07.2f", 1.0f / ZEngine::CZTimeManager::GetFrameRenderTime());
	ZEngine::CZDebug::AddText("time (ms): %.3f", ZEngine::CZTimeManager::ms_fTotalTime);

	return true;
}

