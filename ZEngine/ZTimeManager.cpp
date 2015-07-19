//-----------------------------------------------------------
// ZTimeManager.cpp
//----------------------------------------------------------

#include "Debug/ZAssert.h"
#include "ZTimeManager.h"

using namespace ZEngine;

//-----------------------------------------------------------
// Statics
//-----------------------------------------------------------
sf::Clock CZTimeManager::ms_sfmlCLock;
sf::Clock CZTimeManager::ms_sfmlRenderCLock;
float CZTimeManager::ms_fTrueDeltaTime = 0.0f;
float CZTimeManager::ms_fFrameTime = 0.0f;
float CZTimeManager::ms_fDeltaTime = 0.0f;
float CZTimeManager::ms_fTotalTime = 0.0f;
float CZTimeManager::ms_fTimeScale = 1.0f;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZTimeManager::CZTimeManager()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZTimeManager::~CZTimeManager()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZTimeManager :: ResetDeltaTime()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
float CZTimeManager :: UpdateDeltaTime()
{
	ms_fTrueDeltaTime = (float)ms_sfmlCLock.restart().asSeconds();

	//Add delta time to frame time
	ms_fFrameTime += ms_fTrueDeltaTime;

	//Apply scale on deltaTime
	ms_fDeltaTime = ms_fTrueDeltaTime * ms_fTimeScale;

	ms_fTotalTime += ms_fTrueDeltaTime;

	return ms_fTrueDeltaTime;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZTimeManager::ResetFrameTime()
{
	ms_fFrameTime = 0;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
float CZTimeManager::GetRealDeltaTime()
{
	return (float)ms_sfmlCLock.getElapsedTime().asSeconds();
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
float CZTimeManager::GetFrameRenderTime()
{
	return ms_fFrameTime;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZTimeManager::SetTimeScale(float p_fTimeScale)
{
	ZASSERT(p_fTimeScale > -1.0f && p_fTimeScale < 1.0f);
	ms_fTimeScale = p_fTimeScale;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
float CZTimeManager :: UpdateTimeOnExternalLoop()
{
	ResetFrameTime();
	
	float fCurrentDeltaTime = UpdateDeltaTime();

	return fCurrentDeltaTime;
}