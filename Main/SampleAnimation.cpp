//-----------------------------------------------------------
// SampleAnimation.cpp
//-----------------------------------------------------------

//Engine includes
#include "../ZEngine/Render/ZWindowManager.h"
#include "../ZEngine/Texts/ZText.h"

//Project includes
#include "SampleAnimation.h"

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void SampleAnimation::Init()
{
	//Call this first to ensure the engine is properly initialized
	ZEngine::CZStarter::InitEngine();

	//Create the actual "Hello World" text
	ZEngine::CZText::Create("Hello World");

	//Initialize one window (you can have more if you want)
	ZEngine::CZWindowManager::InitWindow(0, 800, 600, "Sample Animation");
}

//-----------------------------------------------------------
// Called every frame
//-----------------------------------------------------------
bool SampleAnimation::Update(void * p_pContext)
{
	return true;
}