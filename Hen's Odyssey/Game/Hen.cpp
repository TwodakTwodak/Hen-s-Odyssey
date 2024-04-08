#include "Hen.h"
#include "iostream"
Math::vec2 hen_position = { 100, 300, 80 };
Math::vec2 hen_velocity = { 0, 0, 0 };

void Hen::GetVelocity(Math::vec2 get_velocity)
{
	hen_velocity = get_velocity;
}

Math::vec2 Hen::GiveVelocity()
{
	return hen_velocity;
}

void Hen::GetPosition(Math::vec2 get_position)
{
	hen_position = get_position;
}

Math::vec2 Hen::GivePosition()
{
	return hen_position;
}

void Hen::RectChange(Math::ivec2 hen_size)
{
	collision_rect = { 
		{hen_position.x + hen_size.x / 2, 600 - (hen_position.y+ hen_size.y / 2), 600 - (hen_position.z + hen_size.z / 2) },
		{hen_position.x - hen_size.x / 2, 600 - (hen_position.y - hen_size.y / 2), 600 - (hen_position.z - hen_size.z / 2)},
	};
}



Math::rect Hen::GiveCollisionRect()
{
	return collision_rect;
}
