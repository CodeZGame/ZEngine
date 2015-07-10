//-----------------------------------------------------------
// ZView.h
//----------------------------------------------------------

#include "ZView.h"
#include "Types/ZSFMLConvert.h"
#include "Debug/ZDebug.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZView :: CZView()
	:	m_fZoomFactor(1.0f),
		m_fAngle(0.0f),
		m_pfCurrentOffset(0.0f, 0.0f)
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZView :: CZView(const ZRectf & p_pViewRect)
	:	m_fZoomFactor(1.0f),
		m_fAngle(0.0f),
		m_pfCurrentOffset(0.0f, 0.0f),
		m_sfmlView(ZRectToSf(p_pViewRect))
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZView :: ~CZView()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: Reset(ZRectf p_pfDefault)
{
	m_pfCurrentOffset = CVector2Df::Zero;
	m_sfmlView.reset(ZRectToSf(p_pfDefault));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: ResetAll(ZRectf p_pfDefault)
{
	m_pfCurrentOffset = CVector2Df::Zero;
	m_fZoomFactor = 1.0f;
	m_sfmlView.zoom(m_fZoomFactor);
	m_sfmlView.reset(ZRectToSf(p_pfDefault));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: SetViewport(ZRectf p_pfViewport)
{
	m_fViewport = p_pfViewport;
	m_sfmlView.setViewport(ZRectToSf(m_fViewport));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: SetCenter(CVector2Df p_pfCenter)
{
	m_pfCenter = p_pfCenter;
	m_sfmlView.setCenter(ZVectorToSf(m_pfCenter));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: SetCenter(float p_fCenterX, float p_fCenterY)
{
	m_pfCenter.x = p_fCenterX;
	m_pfCenter.y = p_fCenterY;
	m_sfmlView.setCenter(ZVectorToSf(m_pfCenter));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: SetSize(CVector2Df p_pfSize)
{
	m_pfSize = p_pfSize;
	m_sfmlView.setSize(ZVectorToSf(m_pfSize));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: SetSize(float p_fWidth, float p_fHeight)
{
	m_pfSize.x = p_fWidth;
	m_pfSize.y = p_fHeight;
	m_sfmlView.setSize(ZVectorToSf(m_pfSize));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: Rotate(float p_fAngle)
{
	m_fAngle = p_fAngle;
	m_sfmlView.rotate(m_fAngle);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: Zoom(float p_fFactor)
{
	m_fZoomFactor = p_fFactor;
	m_sfmlView.zoom(m_fZoomFactor);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: Move(CVector2Df p_pfOffset)
{
	m_pfCurrentOffset = m_pfCurrentOffset + p_pfOffset;

	m_sfmlView.move(ZVectorToSf(p_pfOffset));
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZView :: Move(float p_fOffsetX, float p_fOffsetY)
{
	m_pfCurrentOffset.x += p_fOffsetX;
	m_pfCurrentOffset.y += p_fOffsetY;

	m_sfmlView.move(sf::Vector2f(p_fOffsetX, p_fOffsetY));
}