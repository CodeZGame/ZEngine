//-----------------------------------------------------------
// SampleShape.cpp
//-----------------------------------------------------------

/*
** This sample shows how to use the shape of the engines
** It shows the creation and configuration of the 3 different
** shapes available
*/

//Engine includes
#include "../ZEngine/Render/ZWindowManager.h"
#include "../ZEngine/Ressources/ZShape.h"
#include "../ZEngine/Types/Vector2D.hpp"
#include "../ZEngine/Types/ZColor.h"

//Project includes
#include "SampleShape.h"

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void SampleShape :: Init()
{
	//Call this first to ensure the engine is properly initialized
	ZEngine::CZStarter::InitEngine();

	//Create the actual circle shape
	ZEngine::CZShape * pCircle = ZEngine::CZShape::CreateCircleShape(CVector2Df(350.0f, 50.0f), 20.0f);

	//Set the color of the circle to blue
	pCircle->SetInnerColor(ZColor::Blue());

	//Add a green border to the circle
	pCircle->SetThickness(2.0f);
	pCircle->SetOutterColor(ZColor::Green());

	//Create a rectangle shape
	ZEngine::CZShape * pRectangle = ZEngine::CZShape::CreateRectangleShape(CVector2Df(200.0f, 200.0f), CVector2Df(45.0f, 35.0f));

	//Create a convex shape
	ZEngine::CZShape * pConvex = ZEngine::CZShape::CreateConvexShape(CVector2Df(400.0f, 200.0f));
	pConvex->SetPointCount(4);

	//Set the points for the convex shape
	pConvex->SetPoint(0, CVector2Df(0.0f, 0.0f));
	pConvex->SetPoint(1, CVector2Df(30.0f, 20.0f));
	pConvex->SetPoint(2, CVector2Df(100.0f, 0.0f));
	pConvex->SetPoint(3, CVector2Df(30.0f, -20.0f));

	//Initialize one window (you can have more if you want)
	ZEngine::CZWindowManager::InitWindow(0, 800, 600, "Sample Shape");
}

//-----------------------------------------------------------
// Called every frame
//-----------------------------------------------------------
bool SampleShape :: Update(void * p_pContext)
{
	//Not necessary for this sample to do something in Update
	return true;
}
