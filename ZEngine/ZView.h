//-----------------------------------------------------------
// ZView.h
//----------------------------------------------------------

#pragma once

#include <SFML/Graphics/View.hpp>

#include "Vector2D.hpp"
#include "ZRect.hpp"

namespace ZEngine
{
	class CZWindow;

	class CZView
	{
	protected:
		sf::View m_sfmlView;

		//Cached info
		CVector2Df m_pfSize;
		CVector2Df m_pfCenter;
		float m_fAngle;
		float m_fZoomFactor;
		ZRectf m_fViewport;

		//Cache move offset
		CVector2Df m_pfCurrentOffset;

	public:
		CZView();
		CZView(const ZRectf & p_pfViewRect);
		//Copy construct
		~CZView();

		//Getters
		float GetRotation() const { return m_fAngle; }
		CVector2Df GetSize() const  { return m_pfSize; }
		CVector2Df GetCenter() const  { return m_pfCenter; }
		ZRectf GetViewport() const  { return m_fViewport; }
		float GetZoomFactor() const  { return m_fZoomFactor; }
		CVector2Df GetCurrentOffset() const { return m_pfCurrentOffset; }

		//Setters
		void Reset(ZRectf p_pfDefault);
		void ResetAll(ZRectf p_pfDefault);
		void SetViewport(ZRectf p_pfViewport);
		void SetCenter(CVector2Df p_pfCenter);
		void SetCenter(float p_fCenterX, float p_fCenterY);
		void SetSize(CVector2Df p_pfSize);
		void SetSize(float p_fWidth, float p_fHeight);
		void Rotate(float p_nAngle);
		void Zoom(float p_fFactor);
		void Move(CVector2Df p_pfOffset);
		void Move(float p_fOffsetX, float p_fOffsetY);

		friend CZWindow;
	};
}