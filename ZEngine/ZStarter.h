//-----------------------------------------------------------
// ZStarter.h
//-----------------------------------------------------------

#pragma once

namespace ZEngine
{
	class CZStarter
	{
	private:
		void InternUpdate(void * p_pContext);		//Main LOOP
		bool LoopUpdate(void * p);					//Update game state at a fix rate
		void LoopSleep(int p_nTimeToSleep);			//Limit CPU usage (in milliseconds)

	protected:
		virtual bool Update(void * p_pContext) = 0;
		virtual bool UpdateAfterDraw(void * p_pContext);

	public:
		CZStarter();
		~CZStarter();

		virtual void InitEngine() final;
		void StartMainLoop(void * p_pContext = nullptr);
	};
}