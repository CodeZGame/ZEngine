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
		//Override this method which will be called every frame
		virtual bool Update(void * p_pContext = nullptr) = 0;
		virtual bool UpdateAfterDraw(void * p_pContext = nullptr);

	public:
		CZStarter();
		~CZStarter();

		//Call this at the beginning so the engine initialize everything needed
		void InitEngine();

		//Releases all ressources use by the engine
		//ONLY CALL AT PROGRAM EXIT
		void EngineReleaseRessources();

		//Call this to "start the game"
		virtual void StartMainLoop(void * p_pContext = nullptr);
	};
}