//-----------------------------------------------------------
// ZRenderer.cpp
//-----------------------------------------------------------

#include <assert.h>
#include "ZRenderer.h"
#include "ZInstance.h"
#include "ZEngineWindow.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRenderer::CZRenderer()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZRenderer :: CZRenderer(CZEngineWindow * p_pWindowOwner)
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
void CZRenderer::SetWindowOwner(CZEngineWindow * p_pWindowOwner)
{
	m_pWindowOwner = p_pWindowOwner;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRenderer :: AddDrawableInstance(ZInstance * p_pZInstance)
{
	m_pfDrawableInstances.push_back(p_pZInstance);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZRenderer :: RemoveInstanceFromDrawingProcess(ZInstance * p_pZInstance)
{
	//m_pfDrawableInstances.erase(std::find(m_pfDrawableInstances.begin, m_pfDrawableInstances.end, p_pZInstance));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void  CZRenderer :: Process()
{
	for (ZInstance * pInstance : m_pfDrawableInstances)
	{
		if (pInstance != nullptr && pInstance->m_bIsActive)// && pInstance->m_pDrawable != nullptr)
		{
			assert(pInstance->m_pDrawable != nullptr);
			m_pWindowOwner->m_Window.draw(*(pInstance->m_pDrawable));
		}
	}
}