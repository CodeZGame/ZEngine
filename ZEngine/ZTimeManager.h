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

		//Last frame time (seconds)
		static float ms_fTrueDeltaTime;

		//Scale time applied to deltaTime only (seconds)
		static float ms_fTimeScale;

		CZTimeManager();

		static float UpdateDeltaTime();
		static void ResetDeltaTime();

	public:
		~CZTimeManager();

		//Last frame time (seconds)
		static float ms_fDeltaTime;

		//Time since the beggining (seconds)
		static float ms_fTotalTime;

		static float GetRealDeltaTime();

		//Getters
		static float GetTimeScale() { return ms_fTimeScale; }

		//Setters
		static void SetTimeScale(float p_fTimeScale);

		friend CZStarter;
	};
}