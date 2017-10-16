#include "AnimationSequence.h"
#include "Camera.h"



void AnimationSequence::Draw(Camera & cam)
{
	
	
	cam.Rasterize(GetDrawable());
}

void AnimationSequence::Update(const float & dt)
{
	if (!m_done)
	{
		if ((m_timer += dt) > m_interval)
		{
			m_seqIndex++;
			m_timer = 0.0f;
			if (m_seqIndex >= m_seqIndices.size())
			{
				if (m_looping)
					m_seqIndex = 0;
				else
				{
					m_done = true;
					return;
				}
			}
			m_renderDesc.clipRect = Locator::ImageManager->GetImage(m_imageName)->GetClippedImage(m_seqIndices[m_seqIndex], m_imageClipOffsets).ToD2D();
		}
	}
}

bool AnimationSequence::Done()
{
	return m_done;
}

bool AnimationSequence::Looping()
{
	return m_looping;
}

void AnimationSequence::SetRenderDesc(Animation::RenderDesc & desc)
{
	m_renderDesc = desc;
}

void AnimationSequence::SetRenderDesc(AnimationSequence::SequenceDesc& in_desc )
{
	m_renderDesc = in_desc.desc;
	m_imageClipOffsets = in_desc.clipOffsets;
	m_done = false;
	m_interval = in_desc.interval;
	m_imageName = in_desc.imageID;
	m_seqIndices = in_desc.indices;
	m_seqIndex = 0;
	m_timer = in_desc.interval;
}
