//-----------------------------------------------------------
// ZAnimation.h
//-----------------------------------------------------------

#pragma once

#include <string>

class CZAnimation
{
public:

	enum class EAnimCreationType
	{
		e_AnimCreationType_SingleSpriteSheet,
		e_AnimCreationType_SeveralImages,

		e_AnimCreationType_Nb
	};

	CZAnimation();
	~CZAnimation();

	//Create the animation from a single sprite sheet
	//Image will played one after the other without need of timing
	static CZAnimation * CreateFromSingleSpriteSheet(const std::string & p_sSpriteSheetFileName);

	//Create the animation by specifying several images
	//Image will played one after the other without need of timing
	static CZAnimation * CreateFromSeveralImages(const char * const p_psImages[], int p_nNbImages);

	//Play the animation
	void Play();

	//Pause the animation, so it can be resumed later by calling play again
	void Pause();

	//Stop the animation and reset to the beginning for later use
	void Stop();
};

