//-----------------------------------------------------------
// ZInstance.h
//----------------------------------------------------------

#include "ZInstance.h"
#include "ZRenderer.h"
#include "ZEngineWindow.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//----------------------------------------------------------
ZInstance::ZInstance(CZEngineWindow & p_pWindowOwner)
	: m_bRessourceLoaded(false), m_bIsActive(false), m_pDrawable(nullptr)
{
	m_pfPos.Zero();
	m_pfScale.One();

	p_pWindowOwner.AddDrawableInstance(this);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
ZInstance :: ~ZInstance()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
void ZInstance::SetActive(bool p_bActive)
{
	ZInstance::m_bIsActive = p_bActive;
}



//-----------------------------------------------------------
//
//----------------------------------------------------------
void ZInstance::SetScale(CVector2D<float> p_pfScale)
{
	m_pfScale = p_pfScale;
}