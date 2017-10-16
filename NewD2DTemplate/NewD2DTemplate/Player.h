#pragma once

#include "GameObject.h"


class Player :
	public GameObject2D_Dynamic
{
public:
	Player();
	Player(Animation::RenderDesc& desc);
	Player(AnimationSequence::SequenceDesc& desc);
	virtual ~Player();
};

