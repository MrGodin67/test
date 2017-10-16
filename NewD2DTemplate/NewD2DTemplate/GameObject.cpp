#include "GameObject.h"
#include "Graphics.h"
#include "Camera.h"
GameObject2D_Dynamic::GameObject2D_Dynamic(AnimationSequence::SequenceDesc& desc)
	:GameObject(desc)
{
	m_position = Vec2f(desc.desc.drawRect.left, desc.desc.drawRect.top);
	m_animation.SetPosition(m_position);
};
void GameObject2D_Dynamic::Draw(Graphics & gfx, Camera & cam)
{
	cam.Rasterize(m_animation.GetDrawable());

}

GameObject::GameObject(AnimationSequence::SequenceDesc& desc)
	:m_animation(desc)
{
}
