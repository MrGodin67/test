#pragma once

#include "GameObject.h"

class EyeTotem : public GameObject2D_Dynamic
{
	
public:
	EyeTotem() = default;
	EyeTotem(AnimationSequence::SequenceDesc& desc);
	void  Update(const float& dt)override;
	
};
