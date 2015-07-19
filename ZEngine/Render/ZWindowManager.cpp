//-----------------------------------------------------------
// ZText.h
//----------------------------------------------------------

#include "ZWindow.h"
#include "ZWindowManager.h"
#include "../Debug/ZAssert.h"
#include "../Types/ZSFMLConvert.h"

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
	ZASSERT(p_uWindowIndex >= 0 && p_uWindowIndex < ZENGINE_MAX_WINDOW);
	return CZWindowManager::ms_pWindows[p_uWindowIndex];
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
CZWindow * CZWindowManager :: InitWindow(unsigned int p_uWindowIndex, const int p_nWith, const int p_nHeight, const char * p_tWindowName)
{
	ZASSERT(p_uWindowIndex >= 0 && p_uWindowIndex < ZENGINE_MAX_WINDOW);

	//Default AA for now
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	ms_pWindows[p_uWindowIndex].m_sfmlWindow.create(sf::VideoMode(p_nWith, p_nHeight), p_tWindowName, sf::Style::Default, settings);

	//Set default view
	sf::View defaultView = ms_pWindows[p_uWindowIndex].m_sfmlWindow.getView();
	ms_pWindows[p_uWindowIndex].m_CurrentView.Reset(ZRectf(0.0f, 0.0f, (float) p_nWith, (float) p_nHeight));
	ms_pWindows[p_uWindowIndex].m_CurrentView.SetCenter(SfVectorToZ(defaultView.getCenter()));
	ms_pWindows[p_uWindowIndex].m_CurrentView.SetSize(SfVectorToZ(defaultView.getSize()));
	ms_pWindows[p_uWindowIndex].m_CurrentView.Rotate(defaultView.getRotation());
	ms_pWindows[p_uWindowIndex].m_CurrentView.SetViewport(SfRectToZ(defaultView.getViewport()));


	ms_pWindows[p_uWindowIndex].m_bIsActive = true;
	ms_pWindows[p_uWindowIndex].m_bVerticalSync = false;
	ms_pWindows[p_uWindowIndex].m_nWindowSize.x = p_nWith;
	ms_pWindows[p_uWindowIndex].m_nWindowSize.y = p_nHeight;
	sf::Vector2i pfPos = ms_pWindows[p_uWindowIndex].m_sfmlWindow.getPosition();
	ms_pWindows[p_uWindowIndex].m_nWindowPosition.x = pfPos.x;
	ms_pWindows[p_uWindowIndex].m_nWindowPosition.y = pfPos.y;

	ms_pWindows[p_uWindowIndex].m_Renderer.SetWindowOwner(&ms_pWindows[p_uWindowIndex]);

	//One More window active
	++ms_uNbWindowActive;

	return &ms_pWindows[p_uWindowIndex];
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
bool CZWindowManager :: ProcessAllWindowsEvents()
{
	bool bStillActive = false;
	bool bWindowState;

	for (int i = 0; i < ZENGINE_MAX_WINDOW; ++i)
	{
		if (ms_pWindows[i].IsActive())
		{
			bWindowState = ms_pWindows[i].ProcessEvents();

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
	}

	return bStillActive;
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
void CZWindowManager::ProcessAllWindowsDraw()
{
	for (int i = 0; i < ZENGINE_MAX_WINDOW; ++i)
	{
		if (ms_pWindows[i].IsActive())
		{
			ms_pWindows[i].ProcessDraw();
		}
	}
}

//-----------------------------------------------------------
//
//---------------------------------------------------------
//bool CZWindowManager :: ProcessWindow(unsigned int p_uWindowIndex)
//{
//	assert(p_uWindowIndex >= 0 && p_uWindowIndex < ZENGINE_MAX_WINDOW);
//
//	return ms_pWindows[p_uWindowIndex].Process();
//}