//-----------------------------------------------------------
// ZActor.h
//-----------------------------------------------------------

#pragma once

#include <vector>
#include "ZTransformComponent.h"
#include "../ZStarter.h"

#define ACTORS_DEFAULT_SIZE		1024

namespace ZEngine
{
	class CZActor
	{
	public:
		CZActor();
		~CZActor();

		CZTransformComponent		m_Transform;

		//Unique Instance ID
		unsigned int				m_nID;

		//Next Actor instanciation will use tihs ID
		static unsigned int				ms_nNextID;

		//Vector of ALL actors
		static std::vector<CZActor*>	ms_Actors;

		static CZActor *				GetActor(unsigned int p_nID);

	private:
		static void InitActors();

		friend class CZStarter;
	};
}