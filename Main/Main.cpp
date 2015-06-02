//-----------------------------------------------------------
// Main.cpp
//-----------------------------------------------------------

#include <tchar.h>
#include "Main.h"
#include "../ZEngine/ZRessourceImageManager.h"
#include "../ZEngine/ZTextureManager.h"
#include "../ZEngine/ZTexture.h"
#include "../ZEngine/ZSprite.h"
#include "../ZEngine/ZShape.h"
#include "../ZEngine/ZText.h"
#include "../ZEngine/ZWindowManager.h"
#include "../ZEngine/ZFontManager.h"
#include "../ZEngine/ZFileHandler.h"
#include "../ZEngine/ZDebug.h"
#include "../ZEngine/ZMouseHandler.h"
#include "../ZEngine/ZKeyboardHandler.h"
#include "../ZEngine/ZTimeManager.h"
#include "../ZEngine/CZTiledMapManager.h"
#include "../ZEngine/ZView.h"
#include "../ZEngine/ZGeneralOption.h"

//-----------------------------------------------------------
//
//-----------------------------------------------------------
Main :: Main()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
Main :: ~Main()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void Main :: Init()
{
	ZEngine::CZStarter::InitEngine();

	ZEngine::CZWindowManager::InitWindow(0, 800, 600, "Test engine");
	//ZEngine::CZWindowManager::InitWindow(1, 300, 300, "Window 2");
	//ZEngine::CZWindowManager::GetWindow(0).SetVerticalSync(true);

	//ZEngine::CZRessourceImage * img = ZEngine::CZRessourceImageManager::LoadImageRessource("Data/Images/blue_button11.png");

	//ZEngine::CZTexture * pNewtexture = ZEngine::CZTextureManager::CreateTexture(img);
	//pNewtexture->SetSmooth(true);

	//ZEngine::CZSprite testSprite(pNewtexture);
	//testSprite.SetPosition(CVector2Df(300.0f, 200.0f));
	//testSprite.SetUniformScale(4.5f);
	//testSprite.SetRotation(45);

	//TEST TILEMAPS
	{
			//Does not handle encoded tiledmap YET
			//ZEngine::CZTiledMapManager::ParseMapFromFile("Data/Maps/TestMap.tmx", "TestMap");
			//ZEngine::CZTiledMapManager::ParseMapFromFile("Data/Maps/Test2.tmx", "Test2");
			//ZEngine::CZTiledMap * testTiledMap = ZEngine::CZTiledMapManager::LoadMap("Test2");
	}

	ZEngine::CZDebug::AddTextLog("Before main loop\n");

	//ZEngine::CZStarter::StartMainLoop(&testSprite);
	ZEngine::CZStarter::StartMainLoop();
}

//-----------------------------------------------------------
// Called every frame
//-----------------------------------------------------------
bool Main :: Update(void * p_pContext)
{
	static ZEngine::CZView currentView;
	currentView = ZEngine::CZWindowManager::GetWindow(0).GetCurrentView();
	static float i = 100.0f;
	static float lastZoomFactor = 1.0f;

	ZEngine::CZDebug::AddText("frame (µs): %1.5f", ZEngine::CZTimeManager::ms_fDeltaTime);
	ZEngine::CZDebug::AddText("FPS : %07.2f", 1.0f / ZEngine::CZTimeManager::ms_fDeltaTime);
	ZEngine::CZDebug::AddText("time (ms): %.3f", ZEngine::CZTimeManager::ms_fTotalTime);

	ZEngine::CZDebug::DrawCircle(CVector2Df((float)ZEngine::CZMouseHandler::GetGlobalPosition().x, (float)ZEngine::CZMouseHandler::GetGlobalPosition().y), 50.0f, ZColor::Red());

	ZEngine::CZDebug::DrawRectangle(CVector2Df((float)ZEngine::CZMouseHandler::GetPosition().x, (float)ZEngine::CZMouseHandler::GetPosition().y), CVector2Df(150.0f, 100.0f), ZColor::Blue());

	ZEngine::CZDebug::AddText("Mouse Pos  X: %d  y: %d", ZEngine::CZMouseHandler::GetPosition().x, ZEngine::CZMouseHandler::GetPosition().y);
	
	ZEngine::CZSprite * pSprite = (ZEngine::CZSprite*)p_pContext;
	//pSprite->SetPosition(CVector2Df((float)ZEngine::CZMouseHandler::GetPosition().x, (float)ZEngine::CZMouseHandler::GetPosition().y));

	//if (ZEngine::CZMouseHandler::IsButtonFirstPressed(ZEngine::ZMouseButton::e_Mouse_Button_Left))
	if (ZEngine::CZKeyboardHandler::IsKeyFirstPressed(ZEngine::ZInputKey::e_InputKey_A))
	{
		pSprite->SetActive(!pSprite->IsActive());
	}

	ZEngine::CZDebug::AddText("Zoom factor: %f", currentView.GetZoomFactor());

	ZEngine::CZDebug::AddText("Viewport: %f %f %f %f", ZEngine::CZWindowManager::GetWindow(0).GetCurrentView().GetViewport().top, ZEngine::CZWindowManager::GetWindow(0).GetCurrentView().GetViewport().left,
							  ZEngine::CZWindowManager::GetWindow(0).GetCurrentView().GetViewport().width, ZEngine::CZWindowManager::GetWindow(0).GetCurrentView().GetViewport().height);

	if (ZEngine::CZKeyboardHandler::IsKeyFirstPressed(ZEngine::ZInputKey::e_InputKey_R))
	{
		ZEngine::CZWindow & currentWindow = ZEngine::CZWindowManager::GetWindow(0);
		currentView.Reset(ZRectf(0.0f, 0.0f, (float)currentWindow.GetSize().x, (float) currentWindow.GetSize().y));
		currentWindow.SetView(currentView);
	}

	//Move view left
	if (ZEngine::CZKeyboardHandler::IsKeyPressed(ZEngine::ZInputKey::e_InputKey_Left))
	{
		currentView.Move(100.0f * ZEngine::CZTimeManager::ms_fDeltaTime, 0.0f);
	}

	//Move view right
	if (ZEngine::CZKeyboardHandler::IsKeyPressed(ZEngine::ZInputKey::e_InputKey_Right))
	{
		currentView.Move(-100.0f * ZEngine::CZTimeManager::ms_fDeltaTime, 0.0f);
	}

	//Zoom Out
	if (ZEngine::CZKeyboardHandler::IsKeyFirstPressed(ZEngine::ZInputKey::e_InputKey_Up))
	//if (ZEngine::CZMouseHandler::IsButtonFirstPressed(ZEngine::ZMouseButton::e_))
	{
		currentView.Zoom(0.95f);
	}

	//Zoom In
	//if (ZEngine::CZKeyboardHandler::IsKeyFirstPressed(ZEngine::ZInputKey::e_InputKey_Down))
	if (ZEngine::CZMouseHandler::GetScroll() != 0)
	{
		currentView.Zoom(1.0f + 0.05f * ZEngine::CZMouseHandler::GetScroll());
	}

	//Rotate left
	//if (ZEngine::CZKeyboardHandler::IsKeyPressed(ZEngine::ZInputKey::e_InputKey_O))
	//{
	//	//currentView.Rotate(1.0f);
	//	currentView.SetCenter(CVector2Df(100.0f, 0.0f));
	//}

	//Set view
	ZEngine::CZWindow & currentWindow = ZEngine::CZWindowManager::GetWindow(0);
	currentWindow.SetView(currentView);

	return true;
}

//-----------------------------------------------------------
// program entrance
//-----------------------------------------------------------
int main()
{
	Main main;

	main.Init();
	return 0;
}
