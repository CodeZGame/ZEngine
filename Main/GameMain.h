//-----------------------------------------------------------
// GameMain.h
//-----------------------------------------------------------

#pragma once

#include "../ZEngine/ZStarter.h"

class CGameMain : public ZEngine::CZStarter
{
public:
	CGameMain();
	~CGameMain();

	void Init();

	bool Update(void * p_pContext = nullptr) override;
};

