//-----------------------------------------------------------
// ZWindow.cpp
//----------------------------------------------------------

#include <string>
#include <SFML\Window\Event.hpp>

#include "../Debug/ZAssert.h"
#include "ZWindow.h"
#include "ZRenderer.h"
#include "../Types/ZSFMLConvert.h"

using namespace ZEngine;

#define DEFAULT_WINDOW_WIDTH		800
#define DEFAULT_WINDOW_HEIGHT		600

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZWindow::CZWindow()
	:	m_bVerticalSync(false),
		m_bIsActive(false)
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZWindow::CZWindow(const int p_nWith, const int p_nHeight, const char * p_tWindowName)
	:	m_nWindowSize(p_nWith, p_nHeight),
		m_sfmlWindow(sf::VideoMode(p_nWith, p_nHeight), p_tWindowName),
		m_bIsActive(true)
{
	m_Renderer.SetWindowOwner(this);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZWindow :: ~CZWindow()
{
}

////-----------------------------------------------------------
////
////-----------------------------------------------------------
//void CZWindow::Create(const int p_nWith, const int p_nHeight, const char * p_tWindowName)
//{
//	m_sfmlWindow.create(sf::VideoMode(p_nWith, p_nHeight), p_tWindowName);
//
//	m_bVerticalSync = false;
//	m_nWindowSize.x = p_nWith;
//	m_nWindowSize.y = p_nHeight;
//	sf::Vector2i pfPos = m_sfmlWindow.getPosition();
//	m_nWindowPosition.x = pfPos.x;
//	m_nWindowPosition.y = pfPos.y;
//}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: Reset()
{
	m_bIsActive = false;
	m_bVerticalSync = false;
	m_nWindowSize = CVector2Di::Zero;
	m_nWindowPosition = CVector2Di::Zero;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZWindow :: ProcessEvents()
{
	sf::Event event;
	while (m_sfmlWindow.pollEvent(event))
	{
		switch (event.type)
		{
			//Enlarge the view on resize event
			case sf::Event::Resized:
			{
				//Update window size
				m_nWindowSize.x = event.size.width;
				m_nWindowSize.y = event.size.height;

				//Update view so it just show "more" (instead of shrinking/fitting screen)
				CZView & currentView = GetCurrentView();
				currentView.Reset(ZRectf(0.0f, 0.0f, (float)event.size.width, (float)event.size.height));
				SetView(currentView);
			}
			break;

			// "close requested" event: we close the window
			case sf::Event::Closed:
			{
				m_sfmlWindow.close();
				Reset();
				return false;
			}

			//Handle mouse scroll
			//case sf::Event::MouseWheelScrolled:
			case sf::Event::MouseWheelMoved:
			{
				//Handle only vertical wheel
				//if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
				{
					//CZMouseHandler::ms_nDeltaScroll += event.mouseWheelScroll.delta;
					CZMouseHandler::ms_nDeltaScroll += event.mouseWheel.delta;
				}
			}
		}
	}
	return true;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: ProcessDraw()
{
	// Clear WHITE
	m_sfmlWindow.clear();

	// Clear BLACK
	//m_sfmlWindow.clear(sf::Color(255, 255, 255));

	m_Renderer.Process();

	m_sfmlWindow.display();
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZWindow :: AddDrawableInstance(CZDrawableInstance * p_pZInstance)
{
	m_Renderer.AddDrawableInstance(p_pZInstance);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZWindow :: RemoveDrawableInstance(CZDrawableInstance * p_pZInstance)
{
	m_Renderer.RemoveDrawableInstance(p_pZInstance);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
bool CZWindow :: HasFocus() const
{
	return m_sfmlWindow.hasFocus();
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
bool CZWindow :: IsOpen() const
{
	return m_sfmlWindow.isOpen();
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CVector2D<int> CZWindow :: GetPosition() const
{
	return m_nWindowPosition;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CVector2D<int> CZWindow :: GetSize() const
{
	return m_nWindowSize;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZWindow :: RequestFocus()
{
	m_sfmlWindow.requestFocus();
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: SetSize(CVector2Di & p_rSize)
{
	m_nWindowSize.x = p_rSize.x;
	m_nWindowSize.y = p_rSize.y;
	m_sfmlWindow.setSize(ZVectorToSfu(p_rSize));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: SetSize(int p_nWidth, int p_nHeight)
{
	m_nWindowSize.x = p_nWidth;
	m_nWindowSize.y = p_nHeight;
	m_sfmlWindow.setSize(sf::Vector2u(p_nWidth, p_nHeight));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: SetPosition(int p_nPosX, int p_nPosY)
{
	m_nWindowPosition.x = p_nPosX;
	m_nWindowPosition.y = p_nPosY;
	m_sfmlWindow.setPosition(sf::Vector2i(p_nPosX, p_nPosY));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: SetPosition(CVector2D<int> & p_rPos)
{
	m_nWindowPosition = p_rPos;
	m_sfmlWindow.setPosition(sf::Vector2i(p_rPos.x, p_rPos.y));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: SetVerticalSync(bool p_bSync)
{
	m_sfmlWindow.setVerticalSyncEnabled(p_bSync);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: SetFrameLimit(int p_nFrameLimit)
{
	ZASSERT(p_nFrameLimit > 0);
	m_sfmlWindow.setFramerateLimit(p_nFrameLimit);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: SetMouseVisible(bool p_bMouseVisible)
{
	m_sfmlWindow.setMouseCursorVisible(p_bMouseVisible);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: SetView(const CZView & p_View)
{
	m_CurrentView = p_View;
	m_sfmlWindow.setView(p_View.m_sfmlView);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZWindow :: UseDebugView()
{
	sf::View debugView(sf::FloatRect(0.0f, 0.0f, (float)m_sfmlWindow.getSize().x, (float)m_sfmlWindow.getSize().y));
	m_sfmlWindow.setView(debugView);

	//m_sfmlWindow.setView(_sfmlWindow.getDefaultView());
}