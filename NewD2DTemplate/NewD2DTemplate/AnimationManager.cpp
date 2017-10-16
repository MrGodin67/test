#include "AnimationManager.h"
#include "Locator.h"
std::unique_ptr<EyeTotem> AnimationManager::GetEyeTotem(Vec2f position)
{
	AnimationSequence::SequenceDesc desc;
	desc.desc.image = Locator::ImageManager->GetImage("main_image")->GetTexture();
	desc.desc.drawRect = { position.x,position.y,position.x + imageSize,position.y + imageSize };
	desc.clipOffsets = { 1.0f,1.0f,-1.0f,-1.0f };
	desc.imageID = "main_image";
	int index = 64 * 7 + 25;
	for (int i = 0; i < 4; i++)
	{
		desc.indices.push_back(index + i);
	}
	desc.interval = 0.15f;
	desc.loop = true;
	
	return std::make_unique<EyeTotem>(desc);
}

std::unique_ptr<GameObject2D_Dynamic> AnimationManager::GetFirePit(Vec2f position)
{
	AnimationSequence::SequenceDesc desc;
	desc.desc.image = Locator::ImageManager->GetImage("main_image")->GetTexture();
	desc.desc.drawRect = { position.x,position.y,position.x + imageSize,position.y + imageSize };
	desc.clipOffsets = { 1.0f,1.0f,-1.0f,-1.0f };
	desc.imageID = "main_image";
	int index = 64 * 12 + 13;
	for (int i = 0; i < 8; i++)
	{
		desc.indices.push_back(index + i);
	}
	desc.interval = 0.15f;
	desc.loop = true;

	return std::make_unique<GameObject2D_Dynamic>(desc);
}

std::unique_ptr<GameObject2D_Dynamic> AnimationManager::GetTumbleNet(Vec2f position)
{
	AnimationSequence::SequenceDesc desc;
	desc.desc.image = Locator::ImageManager->GetImage("main_image")->GetTexture();
	desc.desc.drawRect = { position.x,position.y,position.x + 32.0f,position.y + 32.0f };
	desc.clipOffsets = { 1.0f,1.0f,-1.0f,-1.0f };
	desc.imageID = "main_image";
	int index = 64 * 11 + 10;
	for (int i = 0; i < 8; i++)
	{
		desc.indices.push_back(index + i);
	}
	desc.interval = 0.09f;
	desc.loop = true;

	return std::make_unique<GameObject2D_Dynamic>(desc);
}

std::unique_ptr<GameObject2D_Dynamic> AnimationManager::GetExplosion_1(Vec2f position)
{
	AnimationSequence::SequenceDesc desc;
	desc.desc.image = Locator::ImageManager->GetImage("main_image")->GetTexture();
	desc.desc.drawRect = { position.x,position.y,position.x + 32.0f,position.y + 32.0f };
	desc.clipOffsets = { 1.0f,1.0f,-1.0f,-1.0f };
	desc.imageID = "main_image";
	int index = 64 * 10 + 20;
	desc.indices.push_back(index + 0);
	desc.indices.push_back(index + 1);
	desc.indices.push_back(index + 2);
	desc.indices.push_back(index + 2);
	desc.indices.push_back(index + 1);
	desc.indices.push_back(index + 0);
	
	desc.interval = 0.09f;
	desc.loop = true;

	return std::make_unique<GameObject2D_Dynamic>(desc);
}
