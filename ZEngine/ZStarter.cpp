//-----------------------------------------------------------
// ZStarter.h
//-----------------------------------------------------------

#include <cassert>
#include <chrono>
#include <thread>

#include "ZStarter.h"
#include "ZWindowManager.h"
#include "ZFontManager.h"
#include "ZFileHandler.h"
#include "ZDebug.h"
#include "ZTimeManager.h"
#include "ZMouseHandler.h"
#include "ZKeyboardHandler.h"
#include "ZGeneralOption.h"

#define SLEEP_PRECISION		900
#define MIN_THREAD_SLEEP	100

using namespace ZEngine;

//DEBUG
auto g_timeSleep = 0.0f;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZStarter::CZStarter()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZStarter :: ~CZStarter()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZStarter::InitEngine()
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

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZStarter::StartMainLoop(void * p_pContext)
{
	InternUpdate(p_pContext);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZStarter::InternUpdate(void * p_pContext)
{
	bool bKeepGoing = true;

	while (bKeepGoing)
	{
		//Process game mechanics
		bKeepGoing = LoopUpdate(p_pContext);

		if (!bKeepGoing)
			break;

		//Process windows draw
		ZEngine::CZWindowManager::ProcessAllWindowsDraw();

		//Process any operation needed after draw occured
		bKeepGoing = UpdateAfterDraw(p_pContext);

		//Limit CPU Usage (in milliseconds)
		if (!CZGeneralOption::GetNoSleep())
			LoopSleep(4000);
	}
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZStarter :: LoopUpdate(void * p)
{
	float dt = 0.0046f;

	bool bKeepGoing = true;

	float fRealDeltaTime = CZTimeManager::GetRealDeltaTime();

	while (fRealDeltaTime >= dt)
	{
		CZDebug::Reset();
		CZTimeManager::UpdateDeltaTime();

		//Update inputs
		CZMouseHandler::UpdateMouseInput();
		CZKeyboardHandler::UpdateKeyboardInput();

		//Process windows events
		bKeepGoing = ZEngine::CZWindowManager::ProcessAllWindowsEvents();

		if (!bKeepGoing)
			break;

		bKeepGoing = Update(p);

		if (!bKeepGoing)
			break;

		fRealDeltaTime -= dt;
	}
	return bKeepGoing;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZStarter::LoopSleep(int p_nTImeToSleep)
{
	//Time the thread will sleep (the thread will never sleep this exact time !)
	auto wantedSleep = std::chrono::microseconds(p_nTImeToSleep);

	//Approximative precision of sleep
	static auto sleepPrecision = std::chrono::microseconds(SLEEP_PRECISION);

	auto start = std::chrono::high_resolution_clock::now();
	auto end = start + wantedSleep;
	
	std::chrono::duration<double, std::micro> elapsed = std::chrono::high_resolution_clock::now() - start;
	static std::chrono::duration<double, std::micro> overTimeSleep = std::chrono::microseconds(0);

	auto timeLeft = end - start - overTimeSleep;
	auto deltaSleep = std::chrono::microseconds(MIN_THREAD_SLEEP);

	while (std::chrono::operator>(timeLeft, std::chrono::microseconds(0)))
	{
		if (std::chrono::operator>(timeLeft, sleepPrecision))
		{
			//CZDebug::LogToFile("  => Thread sleep");
			std::this_thread::sleep_for(deltaSleep);
			timeLeft = end - std::chrono::high_resolution_clock::now() - overTimeSleep;
		}
		else
		{
			timeLeft = std::chrono::microseconds(0);
		}
		//CZDebug::LogToFile("    => TIME left: %5.0f", timeLeft.count());
	}

	elapsed = std::chrono::high_resolution_clock::now() - start;
	overTimeSleep += elapsed - wantedSleep;

	//CZDebug::LogToFile("time sleep:						%5.0f", elapsed.count());
	//CZDebug::LogToFile("OVERTIME:		%5.0f", overTimeSleep.count());
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZStarter :: Update(void * p_pContext)
{
	return true;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZStarter::UpdateAfterDraw(void * p_pContext)
{
	return true;
}