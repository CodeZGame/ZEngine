//-----------------------------------------------------------
// Main.h
//-----------------------------------------------------------

#pragma once

#include "../ZEngine/ZEngineWindow.h"

class Main
{
protected:
	ZEngine::CZEngineWindow m_ZEngineWindow;

public:
	Main();
	~Main();

	void Init();
	void Start();
};

