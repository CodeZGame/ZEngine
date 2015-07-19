//-----------------------------------------------------------
// ZMouseHandler.h
//-----------------------------------------------------------


#pragma once

#include <SFML\Window\Mouse.hpp>

#include "../Types/Vector2D.hpp"
#include "../Render/ZWindowManager.h"

namespace ZEngine
{
	class CZWindow;
	class CZStarter;

	//Currently have to corresponds exactly to SFML enum sf::Mouse::Button
	enum ZMouseButton
	{
		e_Mouse_Button_Left,
		e_Mouse_Button_Right,
		e_Mouse_Button_Middle,
		e_Mouse_Button_Extra1,
		e_Mouse_Button_Extra2,

		e_Mouse_Button_Number,
	};

	enum ZMouseScroll
	{
		e_Mouse_Scroll_Up,
		e_Mouse_Scroll_Down,

		e_Mouse_Scroll_Number,
	};

	class CZMouseHandler
	{
	protected:
		static bool ms_bButtonsCurrentStates[e_Mouse_Button_Number];			//Is button pressed ?
		static bool ms_bButtonsFirstStates[e_Mouse_Button_Number];				//Is first press on button ?
		static bool ms_bButtonsReleasedStates[e_Mouse_Button_Number];			// Has button been released after being pressed ?
		static int ms_nDeltaScroll;

		CZMouseHandler();

		static void UpdateMouseInput();

	public:
		~CZMouseHandler();

		static CVector2Di GetGlobalPosition();
		static CVector2Di GetPosition(CZWindow & p_RelativeWindow = CZWindowManager::GetWindow(0));
		static bool IsButtonPressed(ZMouseButton p_eButton);
		static bool IsButtonFirstPressed(ZMouseButton p_eButton);
		static bool IsButtonReleased(ZMouseButton p_eButton);
		static int GetScroll();

		//Setters
		static void SetPosition(CVector2Di p_pfMousePos);

		//ONLY CALL THIS WHEN OVERRIDING THE MAIN LOOP
		//CALL THIS ON THE MAIN LOOP BEFORE THE GENERAL UPDATE
		static void UpdateMouseInputOnExternalLoop();

		friend class CZStarter;
		friend class CZWindow;
	};
}