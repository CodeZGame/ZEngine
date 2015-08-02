//-----------------------------------------------------------
// ZTransformComponent.cpp
//-----------------------------------------------------------

#pragma once

#include "../Types/Vector2D.hpp"
#include "ZBaseComponent.h"

//Basic Transform component
//Contain position and rotation of all Actors

namespace ZEngine
{
	class CZTransformComponent : public CZBaseComponent
	{
	public:
		//Public member, because will be accessed quite often
		//Don't need another indirection layer
		CVector2Df	m_position;
		float		m_rotation;
	};
}