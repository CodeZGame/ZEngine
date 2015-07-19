//-----------------------------------------------------------
// SampleHelloWorld.h
//-----------------------------------------------------------

#pragma once

#include "../ZEngine/ZStarter.h"

//Inherit from CZStarter in order to start the engine afterwards
class SampleHelloWorld : public ZEngine::CZStarter
{
public:
	void Init();

	bool Update(void * p_pContext) override;
};

