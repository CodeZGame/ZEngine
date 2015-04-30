//-----------------------------------------------------------
// ZMouseHandler.h
//-----------------------------------------------------------


#pragma once

#include <SFML\Window\Mouse.hpp>

#include "../ZEngine/Vector2D.hpp"

namespace ZEngine
{
	//Currently have to corresponds exactly to SFML enum sf::Mouse::Button
	enum class ZMouseButton
	{
		e_Mouse_Button_Left,
		e_Mouse_Button_Right,
		e_Mouse_Button_Middle,
		e_Mouse_Button_Extra1,
		e_Mouse_Button_Extra2,

		e_Mouse_Button_Number,
	};

	class CZMouseHandler
	{
	protected:
		CZMouseHandler();

	public:
		~CZMouseHandler();

		static CVector2Di GetPosition();
		static bool IsButtonPressed(ZMouseButton p_eButton);

		static void SetPosition(CVector2Di p_pfMousePos);
	};
}