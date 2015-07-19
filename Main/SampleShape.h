//-----------------------------------------------------------
// SampleShape.h
//-----------------------------------------------------------

#pragma once

#include "../ZEngine/ZStarter.h"

class SampleShape : public ZEngine::CZStarter
{
public:
	void Init();

	//Override this
	bool Update(void * p_pContext) override;
};

