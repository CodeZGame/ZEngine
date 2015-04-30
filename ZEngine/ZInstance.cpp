//-----------------------------------------------------------
// ZInstance.h
//----------------------------------------------------------

#include "ZInstance.h"
#include "ZRenderer.h"
#include "ZWindow.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
CZInstance :: CZInstance(CZWindow & p_pWindowOwner)
	: m_bRessourceLoaded(false), m_bIsActive(false), m_psfmlDrawable(nullptr),
	m_WindowOwner(p_pWindowOwner), m_bIsDebug(false)
{
	m_pfPos.Zero();
	m_pfScale.One();
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