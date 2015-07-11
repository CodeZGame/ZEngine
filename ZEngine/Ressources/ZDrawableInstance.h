//-----------------------------------------------------------
// ZDrawableInstance.h
//----------------------------------------------------------

#pragma once

#include "SFML\Graphics\Drawable.hpp"
#include "../Types/Vector2D.hpp"
#include "../Render/ZRenderer.h"
#include "../Render/ZWindowManager.h"

namespace ZEngine
{
	class CZWindow;

	class CZDrawableInstance
	{
	private:
		bool m_bIsActive;							//Instance active state (if not active, will not be rendered)

		bool m_bIsDebug;							//Is the current instance for debug purpose ? (will be drawn by CZDebug class)

	protected:
		sf::Drawable * m_psfmlDrawable;
	
		CZWindow & m_WindowOwner;

		bool m_bRessourceLoaded;

		CVector2D<float> m_pfPos;
		CVector2D<float> m_pfScale;
		float m_pfRotationAngle;

		virtual void Init() = 0;

		virtual void Reset() = 0;

	public:
		CZDrawableInstance(CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		~CZDrawableInstance();

		//Getters
		bool IsActive() const { return m_bIsActive; }

		CVector2D<float> GetPosition() const { return m_pfPos; }
		CVector2D<float> GetScale() const { return m_pfScale; }
		float GetRotation() const { return m_pfRotationAngle; }

		//Setters
		void SetDebug(bool p_bIsDebug);
		void SetActive(bool p_bActive);

		virtual void SetPosition(CVector2D<float> p_pfPos) = 0;
		virtual void SetScale(CVector2D<float> p_pfScale) = 0;
		virtual void SetUniformScale(float p_pfScale);
		virtual void SetRotation(float p_fRotationAngle);

		friend CZRenderer;
	};
}