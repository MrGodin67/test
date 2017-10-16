#include "EyeTotem.h"
#include "AnimationManager.h"
EyeTotem::EyeTotem(AnimationSequence::SequenceDesc& desc)
	:GameObject2D_Dynamic(desc)
{

}

void EyeTotem::Update(const float & dt)
{
	m_speed < m_maxSpeed ? m_speed += m_acceleration * dt :
		m_speed = m_maxSpeed;
	static bool hasTarget = false;
	AnimationSequence::SequenceDesc desc;
	if (m_target && !hasTarget)
	{
		desc = AnimationManager::GetTotemEyeOpenDesc();
		desc.desc.drawRect = RectF(m_position.x, m_position.y, m_position.x + 64.0f, m_position.y + 64.0f).ToD2D();
		m_animation.SetRenderDesc(desc);
		hasTarget = true;
		
	}
	else if (!m_target && hasTarget)
	{
		desc = AnimationManager::GetTotemEyeClosedDesc();
		desc.desc.drawRect = RectF(m_position.x, m_position.y, m_position.x + 64.0f, m_position.y + 64.0f).ToD2D();
		m_animation.SetRenderDesc(desc);
		hasTarget = false;
	}
	

	if (!m_wayPoints.completed && m_wayPoints.points.size() > 0)
	{

		if (m_wayPoints.moveAlong(m_position, m_velocity, m_speed, dt))
		{
			m_position += m_velocity * m_speed * dt;
			m_animation.SetPosition(m_position);
		};

	}
	else
	{
		m_speed = 0.0f;
	}
	m_animation.Update(dt);

}
