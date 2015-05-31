//-----------------------------------------------------------
// ZInstance.h
//----------------------------------------------------------

#include "ZInstance.h"
#include "ZRenderer.h"
#include "ZWindow.h"
#include "ZSFMLConvert.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZInstance :: CZInstance(CZWindow & p_pWindowOwner)
	: m_bRessourceLoaded(false), m_bIsActive(false), m_psfmlDrawable(nullptr),
	m_WindowOwner(p_pWindowOwner), m_bIsDebug(false)
{
	m_pfPos = CVector2Df::Zero;
	m_pfScale = CVector2Df::One;
	m_pfRotationAngle = 0.0f;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZInstance :: ~CZInstance()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZInstance::SetDebug(bool p_bIsDebug)
{
	m_bIsDebug = p_bIsDebug;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZInstance :: SetActive(bool p_bActive)
{
	if (!m_bIsDebug)
	{
		if (p_bActive)
		{
			m_WindowOwner.AddDrawableInstance(this);
		}
		else
		{
			m_WindowOwner.RemoveDrawableInstance(this);
		}
	}
	m_bIsActive = p_bActive;
}


//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZInstance :: SetScale(CVector2D<float> p_pfScale)
{
	m_pfScale = p_pfScale;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZInstance :: SetUniformScale(float p_pfScale)
{
	m_pfScale.x = p_pfScale;
	m_pfScale.y = p_pfScale;
	dynamic_cast<sf::Transformable *>(m_psfmlDrawable)->setScale(ZVectorToSf(m_pfScale));
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void CZInstance :: SetRotation(float p_fRotationAngle)
{
	m_pfRotationAngle = p_fRotationAngle;
}