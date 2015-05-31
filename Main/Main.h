//-----------------------------------------------------------
// Main.h
//-----------------------------------------------------------

#pragma once

#include "../ZEngine/ZStarter.h"

class Main : ZEngine::CZStarter
{
public:
	Main();
	~Main();

	void Init();

	bool Update(void * p_pContext) override;
};

