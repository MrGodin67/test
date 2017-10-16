#pragma once
#include "GameObject.h"

class Actor : public GameObject2D_Dynamic
{
	std::unordered_map<std::string, std::unique_ptr<GameObject2D_Dynamic>> m_equippedItems;
	std::unordered_map<std::string,std::vector<GameObject2D_Dynamic>> m_inventory;


public:
	Actor(AnimationSequence::SequenceDesc& basic_image);
};