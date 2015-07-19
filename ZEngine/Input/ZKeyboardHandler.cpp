//-----------------------------------------------------------
// ZKeyboardHandler.cpp
//-----------------------------------------------------------

#include "ZKeyboardHandler.h"

using namespace ZEngine;
//-----------------------------------------------------------
//Static
//---------------------------------------------------------
bool CZKeyboardHandler::ms_bKeyCurrentStates[e_InputKey_KeyCount] = {false};
bool CZKeyboardHandler::ms_bKeyFirstStates[e_InputKey_KeyCount] = {false};
bool CZKeyboardHandler::ms_bKeyReleasedStates[e_InputKey_KeyCount] = {false};

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZKeyboardHandler :: CZKeyboardHandler()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZKeyboardHandler :: ~CZKeyboardHandler()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZKeyboardHandler :: IsKeyPressed(ZInputKey p_eButton)
{
	return ms_bKeyCurrentStates[p_eButton];
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZKeyboardHandler :: IsKeyFirstPressed(ZInputKey p_eButton)
{
	return ms_bKeyFirstStates[p_eButton];
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZKeyboardHandler :: IsKeyReleased(ZInputKey p_eButton)
{
	return ms_bKeyReleasedStates[p_eButton];
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZKeyboardHandler :: UpdateKeyboardInput()
{
	for (int i = 0; i < e_InputKey_KeyCount; ++i)
	{
		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) i))
		{
			//	Is already first press ?				(key not pressed last frame?)
			if (ms_bKeyFirstStates[i] == false && ms_bKeyCurrentStates[i] == false)
			{
				ms_bKeyFirstStates[i] = true;
			}
			else
			{
				ms_bKeyFirstStates[i] = false;
			}

			ms_bKeyReleasedStates[i] = false;
			ms_bKeyCurrentStates[i] = true;
		}
		else
		{
			ms_bKeyFirstStates[i] = false;

			//Was key pressed last frame ?
			if (ms_bKeyCurrentStates[i] == true)
			{
				ms_bKeyReleasedStates[i] = true;
			}
			else
			{
				ms_bKeyReleasedStates[i] = false;
			}
			ms_bKeyCurrentStates[i] = false;
		}
	}
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZKeyboardHandler :: UpdateKeyboardInputOnExternalLoop()
{
	//For now only necessary to call base method
	UpdateKeyboardInput();
}