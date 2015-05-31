//-----------------------------------------------------------
// ZStarter.h
//-----------------------------------------------------------

#pragma once

namespace ZEngine
{
	class CZGeneralOption
	{
	protected:
		CZGeneralOption();

		//Will the engine sleep to limit CPU usage ?
		static bool ms_bNoSleep;

	public:
		~CZGeneralOption();

		//Getters
		static bool GetNoSleep() { return ms_bNoSleep; }

		//Setters
		static void SetNoSleep(bool p_bNoSleep) { ms_bNoSleep = p_bNoSleep; }
	};
}