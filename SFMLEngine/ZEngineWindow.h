//-----------------------------------------------------------
// Main.h
//-----------------------------------------------------------

#pragma once

#include <string>
#include "SFML\Window.hpp"
#include "SFML\System\Vector2.hpp"
#include "Vector2D.h"

namespace ZEngine
{

	class CZEngineWindow
	{
	protected:
		sf::Window m_Window;
		sf::Vector2u m_nWindowSize;
		sf::Vector2i m_nWindowPosition;

	public:
		CZEngineWindow();
		~CZEngineWindow();

		void Create(const int p_nWith, const int p_nHeight, const char * p_tWindowName);

		void Process();

		//Getters

		//Setters
		void SetTitle(char * p_pTitle);
		void SetSize(int p_nWidth, int p_nHeight);
		void SetPosition(int p_nPosX, int p_nPosY);

		//Templated setters
		template<typename T>
		void SetSize(CVector2D<T> & p_rSize);
		template<typename T>
		void SetPosition(CVector2D<T> & p_rPos);
	};

}