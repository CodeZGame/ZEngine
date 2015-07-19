//-----------------------------------------------------------
// ZMouseHandler.cpp
//-----------------------------------------------------------

#include "ZMouseHandler.h"
#include "../Render/ZWindow.h"
#include "../Types/ZSFMLConvert.h"
#include "../ZMathUtils.h"

using namespace ZEngine;

//-----------------------------------------------------------
//Static
//---------------------------------------------------------
bool CZMouseHandler::ms_bButtonsCurrentStates[e_Mouse_Button_Number] = {false};
bool CZMouseHandler::ms_bButtonsFirstStates[e_Mouse_Button_Number] = {false};
bool CZMouseHandler::ms_bButtonsReleasedStates[e_Mouse_Button_Number] = {false};
int CZMouseHandler::ms_nDeltaScroll = 0;

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZMouseHandler :: CZMouseHandler()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZMouseHandler :: ~CZMouseHandler()
{
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CVector2Di CZMouseHandler::GetGlobalPosition()
{
	return SfVectorToZ(sf::Mouse::getPosition());
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CVector2Di CZMouseHandler :: GetPosition(CZWindow & p_RelativeWIndow)
{
	sf::Vector2i pfSfmlMousePos = sf::Mouse::getPosition(p_RelativeWIndow.m_sfmlWindow);

	sf::Vector2f pfRelativeMousePos = p_RelativeWIndow.m_sfmlWindow.mapPixelToCoords(pfSfmlMousePos);
	CVector2Di pMousePos;

	pMousePos.x = (int) pfRelativeMousePos.x;
	pMousePos.y = (int) pfRelativeMousePos.y;

	//CZDebug::AddText("Mouse float: %5.2f  %5.2f", pfRelativeMousePos.x, pfRelativeMousePos.y);
	//CZDebug::AddText("Mouse relative: %d  %d", pMousePos.x, pMousePos.y);

	/*pMousePos.x = Clamp(pMousePos.x, 0, p_RelativeWIndow.m_nWindowSize.x);
	pMousePos.y = Clamp(pMousePos.y, 0, p_RelativeWIndow.m_nWindowSize.y);*/
	return pMousePos;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZMouseHandler :: IsButtonPressed(ZMouseButton p_eButton)
{
	return ms_bButtonsCurrentStates[p_eButton];
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZMouseHandler :: IsButtonFirstPressed(ZMouseButton p_eButton)
{
	return ms_bButtonsFirstStates[p_eButton];
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZMouseHandler::IsButtonReleased(ZMouseButton p_eButton)
{
	return ms_bButtonsReleasedStates[p_eButton];
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
int CZMouseHandler :: GetScroll()
{
	return ms_nDeltaScroll;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZMouseHandler :: UpdateMouseInput()
{
	for (int i = 0; i < e_Mouse_Button_Number; ++i)
	{
		if (sf::Mouse::isButtonPressed((sf::Mouse::Button) i))
		{
			//	Is already first press ?				(button not pressed last frame?)
			if (ms_bButtonsFirstStates[i] == false && ms_bButtonsCurrentStates[i] == false)
			{
				ms_bButtonsFirstStates[i] = true;
			}
			else
			{
				ms_bButtonsFirstStates[i] = false;
			}

			ms_bButtonsReleasedStates[i] = false;
			ms_bButtonsCurrentStates[i] = true;
		}
		else
		{
			//Was button pressed last frame ?
			if (ms_bButtonsCurrentStates[i] == true)
			{
				ms_bButtonsReleasedStates[i] = true;
			}
			else
			{
				ms_bButtonsReleasedStates[i] = false;
			}
			ms_bButtonsCurrentStates[i] = false;
		}
	}

	ms_nDeltaScroll = 0;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZMouseHandler :: SetPosition(CVector2Di p_pfMousePos)
{
	sf::Mouse::setPosition(ZVectorToSf(p_pfMousePos));
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZMouseHandler :: UpdateMouseInputOnExternalLoop()
{
	//For now only necessary to call base method
	UpdateMouseInput();
}