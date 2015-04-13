//-----------------------------------------------------------
// Main.h
//-----------------------------------------------------------

#pragma once

#include "../SFMLEngine/ZEngineWindow.h"

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

