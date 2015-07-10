//-----------------------------------------------------------
// ZSprite.h
//----------------------------------------------------------

#pragma once

#include <SFML\Graphics\Sprite.hpp>

#include "../Ressources/ZInstance.h"
#include "ZTexture.h"
#include "../Types/ZColor.h"

namespace ZEngine
{
	class CZSprite : public CZInstance
	{
	protected:
		sf::Sprite m_sfmlSprite;

		const CZTexture * m_pTexture;

		ZColor m_Color;

	public:
		CZSprite(CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		CZSprite(const CZTexture * p_pTexture, CZWindow & p_pWindowOwner = CZWindowManager::GetWindow(0));
		~CZSprite();

		virtual void Init() override;

		virtual void Reset() override;

		//Getters
		const CZTexture * GetTexture() const;
		ZColor GetColor() const;


		//Setters
		void SetTexture(const CZTexture * p_pTexture);
		void SetColor(ZColor p_Color);

		virtual void SetPosition(CVector2D<float> p_pfPos);
		virtual void Move(CVector2D<float> p_pfPos);
		virtual void SetScale(CVector2D<float> p_pfScale);
		virtual void SetRotation(float p_fRotationAngle);
	};
}