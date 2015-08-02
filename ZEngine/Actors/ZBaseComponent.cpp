//-----------------------------------------------------------
// ZBaseComponent.cpp
//-----------------------------------------------------------

#include "ZBaseComponent.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZBaseComponent :: GetActive() const
{
	return m_bIsActive;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZBaseComponent :: SetActive(bool p_bIsActive)
{
	m_bIsActive = p_bIsActive;
}
