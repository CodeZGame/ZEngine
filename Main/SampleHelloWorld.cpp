//-----------------------------------------------------------
// SampleHelloWorld.cpp
//-----------------------------------------------------------

/*
** This sample shows how the basics of the ZEngine
** Also shows how to display text in 2 different ways
*/

//Engine includes
#include "../ZEngine/Render/ZWindowManager.h"
#include "../ZEngine/Texts/ZText.h"
#include "../ZEngine/Debug/ZDebug.h"

//Project includes
#include "SampleHelloWorld.h"

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void SampleHelloWorld :: Init()
{
	//Call this first to ensure the engine is properly initialized
	ZEngine::CZStarter::InitEngine();

	//Create the actual "Hello World" text
	ZEngine::CZText * pText = ZEngine::CZText::Create("Hello World");

	//Set position of the text to x = 300 & y = 100
	pText->SetPosition(CVector2Df(300.0f, 100.0f));

	//Set the "Hello World" color to red
	pText->SetColor(ZColor::Red());

	//Make the text bigger
	pText->SetCharacterSize(25);

	//Initialize one window (you can have more if you want)
	ZEngine::CZWindowManager::InitWindow(0, 800, 600, "Sample HW");
}

//-----------------------------------------------------------
// Called every frame
//-----------------------------------------------------------
bool SampleHelloWorld :: Update(void * p_pContext)
{
	//The Debug class allow easy print in the top right corner
	//You can use printf format
	//Debug text has to be called every frame
	ZEngine::CZDebug::AddText("Hello World %s %s", "Debug", ";)");

	return true;
}