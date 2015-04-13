//-----------------------------------------------------------
// ZEngineWindow.cpp
//----------------------------------------------------------

#include <string>
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
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: Process()
{
	if (m_Window.isOpen())
	{
		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				m_Window.close();
		}
	}
}


//-----------------------------------------------------------
//
//-----------------------------------------------------------
template<typename T>
void CZEngineWindow :: SetSize(CVector2D<T> & p_rSize)
{
	m_nWindowSize.x = p_rSize.x;
	m_nWindowSize.y = p_rSize.y;
	m_Window.setSize(m_nWindowSize);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: SetSize(int p_nWidth, int p_nHeight)
{
	m_nWindowSize.x = p_nWidth;
	m_nWindowSize.y = p_nHeight;
	m_Window.setSize(m_nWindowSize);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZEngineWindow :: SetPosition(int p_nPosX, int p_nPosY)
{
	m_nWindowPosition.x = p_nPosX;
	m_nWindowPosition.y = p_nPosY;
	m_Window.setPosition(m_nWindowPosition);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
template<typename T>
void CZEngineWindow :: SetPosition(CVector2D<T> & p_rPos)
{
	m_nWindowPosition.x = p_rPos.x;
	m_nWindowPosition.y = p_rPos.y;
	m_Window.setPosition(m_nWindowPosition);
}