//-----------------------------------------------------------
// ZEngineWindow.cpp
//----------------------------------------------------------

#include <string>
#include "SFML\Window\Event.hpp"
#include "ZEngineWindow.h"

using namespace ZEngine;


//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZEngineWindow :: CZEngineWindow()
{
	m_nWindowSize.x = 0;
	m_nWindowSize.y = 0;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZEngineWindow :: ~CZEngineWindow()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow::Create(const int p_nWith, const int p_nHeight, const char * p_tWindowName)
{
	m_Window.create(sf::VideoMode(p_nWith, p_nHeight), p_tWindowName);

	m_bVerticalSync = false;
	m_nWindowSize.x = p_nWith;
	m_nWindowSize.y = p_nHeight;
	sf::Vector2i pfPos = m_Window.getPosition();
	m_nWindowPosition.x = pfPos.x;
	m_nWindowPosition.y = pfPos.y;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: Process()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			m_Window.close();
	}

	m_Window.clear();

	m_Window.display();
}


//-----------------------------------------------------------
//
//----------------------------------------------------------
bool CZEngineWindow :: HasFocus() const
{
	return m_Window.hasFocus();
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
bool CZEngineWindow :: IsOpen() const
{
	return m_Window.isOpen();
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CVector2D<int> CZEngineWindow :: GetPosition() const
{
	return m_nWindowPosition;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CVector2D<int> CZEngineWindow :: GetSize() const
{
	return m_nWindowSize;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZEngineWindow :: RequestFocus()
{
	m_Window.requestFocus();
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: SetSize(CVector2D<int> & p_rSize)
{
	m_nWindowSize.x = p_rSize.x;
	m_nWindowSize.y = p_rSize.y;
	m_Window.setSize(sf::Vector2u(p_rSize.x, p_rSize.y));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: SetSize(int p_nWidth, int p_nHeight)
{
	m_nWindowSize.x = p_nWidth;
	m_nWindowSize.y = p_nHeight;
	m_Window.setSize(sf::Vector2u(p_nWidth, p_nHeight));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: SetPosition(int p_nPosX, int p_nPosY)
{
	m_nWindowPosition.x = p_nPosX;
	m_nWindowPosition.y = p_nPosY;
	m_Window.setPosition(sf::Vector2i(p_nPosX, p_nPosY));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: SetPosition(CVector2D<int> & p_rPos)
{
	m_nWindowPosition = p_rPos;
	m_Window.setPosition(sf::Vector2i(p_rPos.x, p_rPos.y));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: SetVerticalSync(bool p_bSync)
{
	m_Window.setVerticalSyncEnabled(p_bSync);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: SetMouseVisible(bool p_bMouseVisible)
{
	m_Window.setMouseCursorVisible(p_bMouseVisible);
}