//-----------------------------------------------------------
// ZInstance.h
//----------------------------------------------------------

#pragma once

#include "SFML\Graphics\Drawable.hpp"
#include "Vector2D.hpp"
#include "ZRenderer.h"

namespace ZEngine
{
	class ZInstance
	{
	protected:
		sf::Drawable * m_pDrawable;

		bool m_bRessourceLoaded;
		bool m_bIsActive;							//Instance active state (if not active, will not be rendered)

		CVector2D<float> m_pfPos;
		CVector2D<float> m_pfScale;

		virtual void Init() = 0;

		virtual void Reset() = 0;

	public:
		ZInstance(CZEngineWindow & p_pWindowOwner);
		~ZInstance();

		//Getters
		bool IsActive() const { return m_bIsActive; }

		CVector2D<float> GetPosition() { return m_pfPos; }
		CVector2D<float> GetScale() { return m_pfScale; }

		//Setters
		void SetActive(bool p_bActive);

		virtual void SetPosition(CVector2D<float> p_pfPos) = 0;
		virtual void SetScale(CVector2D<float> p_pfScale) = 0;

		friend CZRenderer;
	};
}