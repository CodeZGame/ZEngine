//-----------------------------------------------------------
// SampleAnimation.h
//-----------------------------------------------------------

#pragma once

#include "../ZEngine/ZStarter.h"

class SampleAnimation : public ZEngine::CZStarter
{
public:
	void Init();

	//Override this
	bool Update(void * p_pContext) override;
};

