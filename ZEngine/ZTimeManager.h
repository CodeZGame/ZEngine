//-----------------------------------------------------------
// ZTimeManager.h
//----------------------------------------------------------

#pragma once

#include <SFML\System\Clock.hpp>

#include "ZStarter.h"

namespace ZEngine
{
	class CZTimeManager
	{
	protected:
		static sf::Clock ms_sfmlCLock;
		static sf::Clock ms_sfmlRenderCLock;

		//Last frame (update) time (seconds)
		static float ms_fTrueDeltaTime;

		//Last frame (render) time (seconds)
		static float ms_fFrameTime;

		//Scale time applied to deltaTime only (seconds)
		static float ms_fTimeScale;

		CZTimeManager();

		static float UpdateDeltaTime();
		static void ResetFrameTime();
		static void ResetDeltaTime();

	public:
		~CZTimeManager();

		//Last frame time (seconds)
		static float ms_fDeltaTime;

		//Time since the beggining (seconds)
		static float ms_fTotalTime;

		static float GetRealDeltaTime();
		static float GetFrameRenderTime();

		//Getters
		static float GetTimeScale() { return ms_fTimeScale; }

		//Setters
		static void SetTimeScale(float p_fTimeScale);

		//ONLY CALL THIS WHEN OVERRIDING THE MAIN LOOP
		//CALL THIS ON THE MAIN LOOP BEFORE THE GENERAL UPDATE
		static float UpdateTimeOnExternalLoop();

		friend CZStarter;
	};
}