//-----------------------------------------------------------
// Main.cpp
//-----------------------------------------------------------

#include <tchar.h>
#include "Main.h"
#include "../ZEngine/ZShape.h"

//-----------------------------------------------------------
//
//-----------------------------------------------------------
Main :: Main()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
Main :: ~Main()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void Main :: Init()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void Main :: Start()
{
	m_ZEngineWindow.Create(800, 600, "My Window");

	ZEngine::CZShape * circle = ZEngine::CZShape::Create(ZEngine::ZShapeType::e_Shape_Circle, m_ZEngineWindow, CVector2Df(50.0f, 50.0f));

	circle->SetInnerColor(ZColor::Transparent());
	circle->SetOutterColor(ZColor::White());
	circle->SetThickness(1.0f);

	while (1)
	{
		if (!m_ZEngineWindow.Process())
			return;
	}
}

//-----------------------------------------------------------
// program entrance
//-----------------------------------------------------------
int main()
{
	Main main;

	main.Init();
	main.Start();
	return 0;
}
