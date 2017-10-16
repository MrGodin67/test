#pragma once
#include "includes.h"
#include "Vec2.h"
#include "Rect.h"
struct nodeData
{
	Vec2f position;
};
struct _WAYPTS
{
	std::vector<nodeData> points;
	int  index = 0;
	bool completed = false;
	_WAYPTS() = default;
	_WAYPTS(std::vector<nodeData> pts, int _index = 1, bool _completed = false)
		:points(pts), index(_index), completed(_completed)
	{}
	bool moveAlong(const Vec2f& pos, Vec2f& vel, float speed, float dt)
	{
		if (!completed)
		{
			Vec2f p1 = points[index].position;

			Vec2f result = p1 - pos;
			if (result.LenSq() < (speed * speed) * (dt * dt))
			{
				index++;
				if (index >= points.size())
				{
					completed = true;
					return false;
				}
				else
				{
					p1 = points[index].position;
					vel = (p1 - pos).Normalize();
				}
			}
		}
		return true;
	}
};




