//-----------------------------------------------------------
// Main.cpp
//-----------------------------------------------------------

#include <tchar.h>
#include "Main.h"
#include "../ZEngine/ZInit.h"
#include "../ZEngine/ZShape.h"
#include "../ZEngine/ZText.h"
#include "../ZEngine/ZWindowManager.h"
#include "../ZEngine/ZFontManager.h"
#include "../ZEngine/ZFileHandler.h"
#include "../ZEngine/ZDebug.h"
#include "../ZEngine/ZMouseHandler.h"

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
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void Main :: Start()
{
	ZEngine::InitEngine();

	ZEngine::CZWindowManager::InitWindow(0, 800, 600, "Test engine");
	ZEngine::CZWindowManager::GetWindow(0).SetVerticalSync(true);

	/*ZEngine::CZShape * circle = ZEngine::CZShape::CreateCircleShape(CVector2Df(10.0f, 10.0f), 5.0f);
	circle->SetOutterColor(ZColor::White());
	circle->SetThickness(1.0f);*/


	//ZEngine::CZShape * rectangle = ZEngine::CZShape::CreateRectangleShape(CVector2Df(100.0f, 50.0f), CVector2Df(10.0f, 10.0f));
	//rectangle->SetOutterColor(ZColor::White());

	//ZEngine::CZShape * convex = ZEngine::CZShape::CreateConvexShape(CVector2Df(100.0f, 50.0f));
	//convex->SetPointCount(3);
	//convex->SetPoint(0, CVector2Df(10.0f, 20.0f));
	//convex->SetPoint(1, CVector2Df(20.0f, 50.0f));
	//convex->SetPoint(2, CVector2Df(30.0f, 60.0f));
	//convex->SetOutterColor(ZColor::White());
	//convex->SetInnerColor(ZColor::White());

	ZEngine::CZText * text = ZEngine::CZText::Create("Hello Wolrd !", "arial");
	text->SetPosition(CVector2Df(50.0f, 100.0f));


	//ZEngine::CZFileHandler logFile("log.txt", ZEngine::FileOpenFlag::e_OpenFlag_Write);
	//logFile.Write("Test log");

	static float i = 100.0f;

	ZEngine::CZDebug::AddTextLog("Before main loop\n");

	while (1)
	{
		ZEngine::CZDebug::DrawCircle(CVector2Df(150.0f, 50.0f), 50.0f, ZColor::Red());

		ZEngine::CZDebug::DrawRectangle(CVector2Df(250.0f, 150.0f), CVector2Df(20.0f, 10.0f), ZColor::Blue());
		 
		ZEngine::CZDebug::AddText("Test  %s  %f  %d", "KDO", ++i, 42);
		ZEngine::CZDebug::AddText("Test5");
		ZEngine::CZDebug::AddText("Mouse Pos  X: %d  y: %d", ZEngine::CZMouseHandler::GetPosition().x, ZEngine::CZMouseHandler::GetPosition().y);

		if (!ZEngine::CZWindowManager::ProcessAllWindows())
		{
			ZEngine::CZDebug::LogError("Test warning\n");
			ZEngine::CZDebug::AddTextLog("Exit \n----- log END ----");
			return;
		}
	}
}

//-----------------------------------------------------------
// program entrance
//-----------------------------------------------------------
int main()
{
	Main main;

	main.Init();
	main.Start();
	return 0;
}
