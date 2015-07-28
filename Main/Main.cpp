//-----------------------------------------------------------
// Main.cpp
//-----------------------------------------------------------

//#define LEAK_DETECT

//Visual Leak Detector
#if defined _DEBUG && defined LEAK_DETECT
#include <vld.h>
#endif

//Samples
#include "SampleHelloWorld.h"
#include "SampleAnimation.h"
#include "SampleShape.h"
#include "SampleLoopControl.h"

#include "GameMain.h"

//-----------------------------------------------------------
// program entrance
//-----------------------------------------------------------
int main()
{
//------- SAMPLES ----------
	//SampleHelloWorld sample;
	SampleShape sample;
	//SampleAnimation sample;
	//SampleLoopControl sample;

	sample.Init();

	sample.StartMainLoop();
//--------------------------


//------- ACTUAL MAIN GAME -------
	//CGameMain gameMain;

	//gameMain.Init();

	//gameMain.StartMainLoop();
//--------------------------------

	return 0;
}
