//-----------------------------------------------------------
// ZEngineWindow.h
//-----------------------------------------------------------

#pragma once

#include <string>
#include "SFML\Graphics\RenderWindow.hpp"
#include "SFML\System\Vector2.hpp"
#include "Vector2D.hpp"
#include "ZRenderer.h"

namespace ZEngine
{
	class CZEngineWindow
	{
	protected:
		sf::RenderWindow m_Window;
		CVector2D<int> m_nWindowSize;
		CVector2D<int> m_nWindowPosition;
		bool m_bVerticalSync;

		CZRenderer m_Renderer;

	public:
		static CZEngineWindow ms_Current;
		CZEngineWindow();
		~CZEngineWindow();

		void Create(const int p_nWith, const int p_nHeight, const char * p_tWindowName);

		bool Process();

		void AddDrawableInstance(ZInstance * p_pZInstance);

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
		
		
		void RequestFocus();

		friend void CZRenderer::Process();
	};

}