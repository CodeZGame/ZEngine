//-----------------------------------------------------------
// ZWindow.h
//-----------------------------------------------------------

#pragma once

#include <string>
#include "SFML\Graphics\RenderWindow.hpp"
#include "SFML\System\Vector2.hpp"
#include "Vector2D.hpp"
#include "ZRenderer.h"
#include "ZWindowManager.h"
#include "ZDebug.h"

namespace ZEngine
{
	class CZWindow
	{
	protected:
		sf::RenderWindow m_sfmlWindow;
		CVector2D<int> m_nWindowSize;
		CVector2D<int> m_nWindowPosition;
		bool m_bVerticalSync;

		CZRenderer m_Renderer;

		//Hide Constructor
		CZWindow();
		CZWindow(const int p_nWith, const int p_nHeight, const char * p_tWindowName);

	public:
		~CZWindow();

		void Create();

		bool Process();

		void AddDrawableInstance(CZInstance * p_pZInstance);

		void RemoveDrawableInstance(CZInstance * p_pZInstance);

		//Getters
		bool HasFocus() const;
		bool IsOpen() const;
		CVector2D<int> GetPosition() const;
		CVector2D<int> GetSize() const;
		CZRenderer GetRenderer() { return m_Renderer; }

		//Setters
		void SetTitle(char * p_pTitle);
		void SetSize(int p_nWidth, int p_nHeight);
		void SetSize(CVector2D<int> & p_rSize);
		void SetPosition(int p_nPosX, int p_nPosY);
		void SetPosition(CVector2D<int> & p_rPos);
		void SetVerticalSync(bool p_bSync);
		void SetMouseVisible(bool p_bMouseVisible);
		
		void IsResizable(bool p_bIsResizable);
		
		void RequestFocus();

		//Friend zone
		friend void CZRenderer::Process();
		friend void CZRenderer::ProcessDrawDebug();

		friend CZWindowManager;
	};

}