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
#include "ZMouseHandler.h"
#include "ZDebug.h"

namespace ZEngine
{
	class CZWindow
	{
	protected:
		sf::RenderWindow m_sfmlWindow;

		CVector2D<int> m_nWindowSize;
		CVector2D<int> m_nWindowPosition;
		CZView m_CurrentView;

		bool m_bIsActive;

		bool m_bVerticalSync;

		CZRenderer m_Renderer;

		//Hide Constructor
		CZWindow();
		CZWindow(const int p_nWith, const int p_nHeight, const char * p_tWindowName);

		//void Create();
		
		void Reset();

		bool ProcessEvents();
		void ProcessDraw();

		void UseDebugView();

	public:
		~CZWindow();

		void AddDrawableInstance(CZInstance * p_pZInstance);

		void RemoveDrawableInstance(CZInstance * p_pZInstance);

		//Getters
		bool HasFocus() const;
		bool IsOpen() const;
		CVector2D<int> GetPosition() const;
		CVector2D<int> GetSize() const;
		CZRenderer GetRenderer() { return m_Renderer; }
		CZView & GetCurrentView() { return m_CurrentView; };
		bool IsActive() const { return m_bIsActive; }

		//Setters
		void SetTitle(char * p_pTitle);
		void SetSize(int p_nWidth, int p_nHeight);
		void SetSize(CVector2D<int> & p_rSize);
		void SetPosition(int p_nPosX, int p_nPosY);
		void SetPosition(CVector2D<int> & p_rPos);
		void SetVerticalSync(bool p_bSync);
		void SetMouseVisible(bool p_bMouseVisible);
		void SetView(const CZView & view);
		
		void IsResizable(bool p_bIsResizable);
		
		void RequestFocus();

		//Friend zone
		friend void CZRenderer::Process();
		friend void CZRenderer::ProcessDrawDebug();
		friend CVector2Di CZMouseHandler::GetPosition(CZWindow & p_RelativeWindow);

		friend CZWindowManager;
	};

}