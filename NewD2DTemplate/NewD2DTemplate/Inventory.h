#pragma once

#include "includes.h"
#include "Rect.h"
#include "Vec2.h"
#include "AnimationSequence.h"
class GUI_Inventory
{
	RectF windowFrame;
	std::unordered_map<std::string,AnimationSequence> m_animations;
	
public:
	GUI_Inventory();
	void Draw(class Camera& cam);
};