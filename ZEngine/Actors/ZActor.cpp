//-----------------------------------------------------------
// ZActor.h
//-----------------------------------------------------------

#include <limits>
#include "../Debug/ZAssert.h"
#include "ZActor.h"

using namespace ZEngine;

//-----------------------------------------------------------
//Static
//-----------------------------------------------------------
unsigned int CZActor::ms_nNextID = 0;
std::vector<CZActor*> CZActor::ms_Actors;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZActor :: CZActor()
{
	ZASSERT(ms_nNextID < UINT_MAX && "increase ID size");
	//Associate ID with this instance
	m_nID = ms_nNextID;

	//Increase ID for next instanciation
	++ms_nNextID;

	//Add this actor to the list of actors
	ms_Actors.push_back(this);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZActor :: ~CZActor()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZActor::InitActors()
{
	//Reserve space for actors vector
	ms_Actors.reserve(ACTORS_DEFAULT_SIZE);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZActor * CZActor::GetActor(unsigned int p_nID)
{
	ZASSERT(p_nID < ms_nNextID);
	return ms_Actors[p_nID];
}
