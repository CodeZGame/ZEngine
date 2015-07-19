#pragma once
//-----------------------------------------------------------
// ZAnimator.h
//-----------------------------------------------------------

#pragma once

#include <string>
#include <vector>
#include <map>

class CZAnimation;

class CZAnimator
{
protected:

	//Contains all animation associated to this animator (itself associated to an instance)
	std::map<std::string, CZAnimation*> m_Animations;

	//Contain all animation assigned to layers
	//Therefore when a non loop animation has finished, it can fallback to the previous animation
	//Layer 0 is played first
	std::map<int, std::vector<std::string>> m_Layers;

	bool m_bIsPlaying;				//Is currently playing an animation ?

public:
	CZAnimator();
	~CZAnimator();

	bool PlayAnimOnceWithoutBlend(const std::string & p_sAnimName, int p_eLayer);
	bool PlayAnimOnceBlend(const std::string & p_sAnimName, int p_eLayer);
	
	bool PlayAnimLoopWithoutBlend(const std::string & p_sAnimName, int p_eLayer);
	bool PlayAnimLoopBlend(const std::string & p_sAnimName, int p_eLayer);

	//Stop an animation on the designated layer
	//The anim will be remove from the array, and the previous animation will be played (if any)
	// or will check for layer under to play anim
	void StopAnimation(const std::string & p_sAnimName, int p_eLayer);

	bool IsPlayingAnim() const;
	bool CurrentLayerPlaying() const;
	const std::string & CurrentAnimPlaying() const;

	void ResetLayer(int p_eLayer);
	void ResetAllLayer();
};

