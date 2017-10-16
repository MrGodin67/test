#include "Player.h"

#include "Camera.h"
#include "Graphics.h"
Player::Player()
{
}

Player::Player(Animation::RenderDesc & desc)
	:GameObject2D_Dynamic(desc)
{
	
}

Player::Player(AnimationSequence::SequenceDesc & desc)
	: GameObject2D_Dynamic(desc)
{
}




Player::~Player()
{
}

