//-----------------------------------------------------------
// ZEngineWindow.h
//-----------------------------------------------------------

#pragma once

#include "SFML\Graphics\CircleShape.hpp"
#include "SFML\Graphics\RectangleShape.hpp"
#include "SFML\Graphics\Text.hpp"

namespace ZEngine
{
	class CZengineDebug
	{
	protected:
		static CZengineDebug ms_pCurrent;

	public:
		CZengineDebug();
		~CZengineDebug();

		void Process();

		// Draw debug shapes
		void DrawCircle();
		void DrawRectangle();

		// Draw debug texts
		void AddText();
	};

}