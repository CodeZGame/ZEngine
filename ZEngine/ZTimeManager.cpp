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
float CZTimeManager::ms_fTrueDeltaTime = 0.0f;
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

	//Apply scale on deltaTime
	ms_fDeltaTime = ms_fTrueDeltaTime * ms_fTimeScale;

	ms_fTotalTime += ms_fTrueDeltaTime;

	return ms_fTrueDeltaTime;
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
void CZTimeManager::SetTimeScale(float p_fTimeScale)
{
	ZASSERT(p_fTimeScale > -1.0f && p_fTimeScale < 1.0f);
	ms_fTimeScale = p_fTimeScale;
}