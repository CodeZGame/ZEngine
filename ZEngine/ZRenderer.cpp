//-----------------------------------------------------------
// ZRenderer.cpp
//-----------------------------------------------------------

#include <assert.h>
#include "ZRenderer.h"
#include "ZInstance.h"
#include "ZWindow.h"
#include "ZDebug.h"
#include "ZShape.h"
#include "ZText.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRenderer::CZRenderer()
	: m_uNbInstances(0)
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRenderer :: CZRenderer(CZWindow * p_pWindowOwner)
	: m_pWindowOwner(p_pWindowOwner)//, m_pfDrawableInstances(MAX_DRAWABLE_INSTANCES)
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRenderer :: ~CZRenderer()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRenderer::SetWindowOwner(CZWindow * p_pWindowOwner)
{
	m_pWindowOwner = p_pWindowOwner;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRenderer :: AddDrawableInstance(CZInstance * p_pZInstance)
{
	assert(m_uNbInstances < MAX_DRAWABLE_INSTANCES && "Max drawable instances is not enough !");
	m_pfDrawableInstances.push_back(p_pZInstance);
	++m_uNbInstances;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRenderer :: RemoveDrawableInstance(CZInstance * p_pZInstance)
{
	//m_pfDrawableInstances.erase(std::find(m_pfDrawableInstances.begin, m_pfDrawableInstances.end, p_pZInstance));
	//--m_uNbInstances;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void  CZRenderer :: Process()
{
	for (CZInstance * pInstance : m_pfDrawableInstances)
	{
		if (pInstance != nullptr && pInstance->m_bIsActive)// && pInstance->m_pDrawable != nullptr)
		{
			assert(pInstance->m_psfmlDrawable != nullptr);
			m_pWindowOwner->m_sfmlWindow.draw(*(pInstance->m_psfmlDrawable));
		}
	}

	ProcessDrawDebug();

	CZDebug::Reset();
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void  CZRenderer :: ProcessDrawDebug()
{
	int i;
	CZInstance * pInstance;

	//Draw debug Rectangle shapes
	for (i = 0; i < CZDebug::ms_nNbDebugRectangleShapes && i < ZENGINE_MAX_DEBUG_SHAPES; ++i)
	{
		pInstance = &CZDebug::ms_DebugRectangleShapes[i];
		if (pInstance->m_bIsActive)
		{
			assert(pInstance->m_psfmlDrawable != nullptr);
			m_pWindowOwner->m_sfmlWindow.draw(*(pInstance->m_psfmlDrawable));
		}
	}

	//Draw debug Circle shapes
	for (i = 0; i < CZDebug::ms_nNbDebugCircleShapes && i < ZENGINE_MAX_DEBUG_SHAPES; ++i)
	{
		pInstance = &CZDebug::ms_DebugCircleShapes[i];
		if (pInstance->m_bIsActive)
		{
			assert(pInstance->m_psfmlDrawable != nullptr);
			m_pWindowOwner->m_sfmlWindow.draw(*(pInstance->m_psfmlDrawable));
		}
	}

	//Draw debug texts
	for (i = 0; i < CZDebug::ms_nNbDebugTexts && i < ZENGINE_MAX_DEBUG_TEXTS; ++i)
	{
		pInstance = &CZDebug::ms_DebugTexts[i];
		if (pInstance->m_bIsActive)
		{
			assert(pInstance->m_psfmlDrawable != nullptr);
			m_pWindowOwner->m_sfmlWindow.draw(*(pInstance->m_psfmlDrawable));
		}
	}
}