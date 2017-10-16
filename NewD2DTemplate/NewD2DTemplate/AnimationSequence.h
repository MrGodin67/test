#pragma once

#include "Animation.h"

#include "Locator.h"

class AnimationSequence : public Animation
{
protected:
	std::vector<int> m_seqIndices;
	RectF m_imageClipOffsets;
	float m_interval = 0.0f;
	float m_timer = 0.0f;
	int m_seqIndex = 0;
	std::string m_imageName;
	bool m_looping = false;
	bool m_done = false;
	
public:
	class SequenceDesc
	{
	public:
		std::vector<int> indices;
		float interval = 0.0f;
		std::string imageID = "";
		bool loop = false;
		RectF clipOffsets = { 0.0f,0.0f,0.0f,0.0f };
		Animation::RenderDesc desc;
		SequenceDesc() {}
		SequenceDesc(Animation::RenderDesc& desc,int startIndex, int numbSequence,
			float interval, std::string imageID, bool loop = false,
			RectF clipOffsets = { 0.0f,0.0f,0.0f,0.0f })
			:desc(desc),interval(interval), imageID(imageID),loop(loop), clipOffsets(clipOffsets)
		{
			for (int c = 0; c < numbSequence; c++)
				indices.push_back(startIndex + c);
		}

	};
public:
	AnimationSequence() {}
	AnimationSequence(SequenceDesc& in_desc)
	   :
	Animation(in_desc.desc),
	m_seqIndices(in_desc.indices),
	m_interval(in_desc.interval),
	m_imageName(in_desc.imageID),
	m_looping(in_desc.loop),
	m_imageClipOffsets(in_desc.clipOffsets)
	{}
	virtual ~AnimationSequence() {}
	virtual void Draw(class Camera& cam);
	virtual void Update(const float& dt);
	virtual bool Done();
	virtual bool Looping();
	virtual void SetRenderDesc(Animation::RenderDesc& desc);
	virtual void SetRenderDesc(SequenceDesc& in_desc);
};