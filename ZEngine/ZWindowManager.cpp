//-----------------------------------------------------------
// ZText.h
//----------------------------------------------------------

#include <assert.h>
#include "ZWindow.h"
#include "ZWindowManager.h"

using namespace ZEngine;

//-----------------------------------------------------------
// Static
//-----------------------------------------------------------
CZWindow CZWindowManager::ms_pWindows[ZENGINE_MAX_WINDOW];
unsigned int CZWindowManager::ms_uNbWindowActive = 0;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZWindowManager::CZWindowManager()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZWindowManager::~CZWindowManager()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZWindow & CZWindowManager :: GetWindow(unsigned int p_uWindowIndex)
{
	assert(p_uWindowIndex >= 0 && p_uWindowIndex < ZENGINE_MAX_WINDOW);
	return CZWindowManager::ms_pWindows[p_uWindowIndex];
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZWindowManager :: InitWindow(unsigned int p_uWindowIndex, const int p_nWith, const int p_nHeight, const char * p_tWindowName)
{
	assert(p_uWindowIndex >= 0 && p_uWindowIndex < ZENGINE_MAX_WINDOW);

	ms_pWindows[p_uWindowIndex].m_sfmlWindow.create(sf::VideoMode(p_nWith, p_nHeight), p_tWindowName, sf::Style::Close);

	ms_pWindows[p_uWindowIndex].m_bVerticalSync = false;
	ms_pWindows[p_uWindowIndex].m_nWindowSize.x = p_nWith;
	ms_pWindows[p_uWindowIndex].m_nWindowSize.y = p_nHeight;
	sf::Vector2i pfPos = ms_pWindows[p_uWindowIndex].m_sfmlWindow.getPosition();
	ms_pWindows[p_uWindowIndex].m_nWindowPosition.x = pfPos.x;
	ms_pWindows[p_uWindowIndex].m_nWindowPosition.y = pfPos.y;

	ms_pWindows[p_uWindowIndex].m_Renderer.SetWindowOwner(&ms_pWindows[p_uWindowIndex]);

	//One More window active
	++ms_uNbWindowActive;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZWindowManager :: ProcessAllWindows()
{
	bool bStillActive = false;
	bool bWindowState;

	for (int i = 0; i < ZENGINE_MAX_WINDOW && i < (int) ms_uNbWindowActive; ++i)
	{
		bWindowState = ms_pWindows[i].Process();

		//Window closed
		if (bWindowState == false)
		{
			--ms_uNbWindowActive;
		}
		//Window still "alive"
		else
		{
			bStillActive = true;
		}
	}

	return bStillActive;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZWindowManager :: ProcessWindow(unsigned int p_uWindowIndex)
{
	assert(p_uWindowIndex >= 0 && p_uWindowIndex < ZENGINE_MAX_WINDOW);

	return ms_pWindows[p_uWindowIndex].Process();
}