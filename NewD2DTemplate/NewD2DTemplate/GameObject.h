#pragma once
#include "AnimationSequence.h"
#include "structs.h"
class GameObject
{
protected:
	AnimationSequence m_animation;
	Vec2f m_position;

public:
	GameObject() = default;
	GameObject(AnimationSequence::SequenceDesc& desc);
	virtual ~GameObject() {}
	virtual void Draw(class Graphics& gfx, class Camera& cam) {};
	virtual AnimationSequence* GetAnimationSeq() { return &m_animation; }
	virtual void Update(const float& dt) {}
	virtual Vec2f GetPosition() { return m_position; }
	virtual void SetPosition(Vec2f pos) 
	{ 
		m_position = pos;
		m_animation.SetPosition(pos);
	}
};

class GameObject2D_Dynamic : public GameObject
{
protected:
	Vec2f m_velocity = Vec2f(1.0f, 0.0f);
	float m_acceleration = 12.1f;
	float m_maxSpeed = 72.0f;
	float m_speed = 0.0f;;
	_WAYPTS m_wayPoints;
	GameObject* m_target = nullptr;
public:
	GameObject2D_Dynamic() {}
	GameObject2D_Dynamic(Animation::RenderDesc& desc)
	{
		m_animation.SetRenderDesc(desc);
	};
	GameObject2D_Dynamic(AnimationSequence::SequenceDesc& desc);
	void SetTarget(GameObject* obj) { m_target = obj; }
	virtual void Draw(class Graphics& gfx, class Camera& cam)override;
	virtual void Update(const float& dt)override
	{
		m_speed < m_maxSpeed ? m_speed += m_acceleration * dt :
			m_speed = m_maxSpeed;



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


	};
	virtual void SetWaypoints(std::vector<nodeData> pts)
	{
		m_wayPoints = _WAYPTS(pts);
		m_wayPoints.index = 0;
		m_wayPoints.completed = false;
		m_speed = 0.0f;
		m_velocity = (m_wayPoints.points[m_wayPoints.index].position - m_position).Normalize();

	}
};