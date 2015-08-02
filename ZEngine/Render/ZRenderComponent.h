//-----------------------------------------------------------
// ZRenderComponent.h
//-----------------------------------------------------------

#pragma once
#include <SFML/Graphics/Drawable.hpp>

#include "../Actors/ZActor.h"
#include "../Actors/ZBaseComponent.h"
#include "../Render/ZWindowManager.h"
#include "../Render/ZRenderer.h"

namespace ZEngine
{
	class CZRenderComponent : public CZBaseComponent
	{
	public:
		CZRenderComponent(CZActor & p_pOwner, sf::Drawable & p_pDrawable, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		~CZRenderComponent();

		//Update position based on transform component
		//Will be called by renderer before rendering Actor
		virtual void UpdatePosition() = 0;

	protected:
		sf::Drawable &	m_pSfmlDrawable;
		CZActor	&		m_pOwner;
		CZWindow &		m_pWindowOwner;

		friend class CZRenderer;
	};
}