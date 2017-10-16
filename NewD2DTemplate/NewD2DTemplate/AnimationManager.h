#pragma once
#include "AnimationSequence.h"
#include "EyeTotem.h"
class AnimationManager
{
	float imageSize = 64.0f;

	public:
		std::unique_ptr<EyeTotem> GetEyeTotem(Vec2f position);
		std::unique_ptr<GameObject2D_Dynamic> GetFirePit(Vec2f position);
		std::unique_ptr<GameObject2D_Dynamic> GetTumbleNet(Vec2f position);
		std::unique_ptr<GameObject2D_Dynamic> GetExplosion_1(Vec2f position);
		static AnimationSequence::SequenceDesc GetBody_1(Vec2f position, float imageSize)
		{
			AnimationSequence::SequenceDesc desc;
			
			desc.desc.image = Locator::ImageManager->GetImage("main_image")->GetTexture();
			desc.desc.drawRect = { position.x,position.y,position.x + imageSize,position.y + imageSize };
			desc.clipOffsets = { 1.0f,1.0f,-1.0f,-1.0f };
			desc.imageID = "main_image";
			int index = 64*31+1;
			TextureManager::ImageClip clip = Locator::ImageManager->GetClip("main_image", index);
			desc.desc.clipRect = clip.rect.ToD2D();
			desc.indices.push_back(index);
			desc.interval = 0.0f;
			desc.loop = false;
			return desc;
		}
		static AnimationSequence::SequenceDesc GetEmptySlot(Vec2f position,float imageSize)
		{
			AnimationSequence::SequenceDesc desc;
			desc.desc.image = Locator::ImageManager->GetImage("main_image")->GetTexture();
			desc.desc.drawRect = { position.x,position.y,position.x + imageSize,position.y + imageSize };
			desc.clipOffsets = { 1.0f,1.0f,-1.0f,-1.0f };
			desc.imageID = "main_image";
			int index = 12;
			desc.indices.push_back(index);
			desc.interval = 0.0f;
			desc.loop = false;
			return desc;
		}
		static AnimationSequence::SequenceDesc GetTotemEyeClosedDesc()
		{
			AnimationSequence::SequenceDesc desc;
			desc.desc.image = Locator::ImageManager->GetImage("main_image")->GetTexture();
			//desc.desc.drawRect = { position.x,position.y,position.x + imageSize,position.y + imageSize };
			desc.clipOffsets = { 1.0f,1.0f,-1.0f,-1.0f };
			desc.imageID = "main_image";
			int index = 64 * 7 + 25;
			for (int i = 0; i < 4; i++)
			{
				desc.indices.push_back(index + i);
			}
			desc.interval = 0.15f;
			desc.loop = true;
			return desc;
		}
		static AnimationSequence::SequenceDesc GetTotemEyeOpenDesc()
		{
			AnimationSequence::SequenceDesc desc;
			desc.desc.image = Locator::ImageManager->GetImage("main_image")->GetTexture();
			//desc.desc.drawRect = { position.x,position.y,position.x + imageSize,position.y + imageSize };
			desc.clipOffsets = { 1.0f,1.0f,-1.0f,-1.0f };
			desc.imageID = "main_image";
			int index = 64 * 7 + 29;
			for (int i = 0; i < 4; i++)
			{
				desc.indices.push_back(index + i);
			}
			desc.interval = 0.15f;
			desc.loop = true;
			return desc;
		}
};