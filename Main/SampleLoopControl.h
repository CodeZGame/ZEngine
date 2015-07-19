//-----------------------------------------------------------
// SampleLoopControl.h
//-----------------------------------------------------------

#pragma once

#include "../ZEngine/ZStarter.h"

class SampleLoopControl : public ZEngine::CZStarter
{
public:
	void Init();

	//Override this
	bool Update(void * p_pContext = nullptr) override;

	virtual void StartMainLoop(void * p_pContext = nullptr);
};

