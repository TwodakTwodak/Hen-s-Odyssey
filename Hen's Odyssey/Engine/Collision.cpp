#include "Collision.h"

bool Collision::CollisionCheck(Math::rect r1, Math::rect r2)
{
	//if there is a error, change y pos
	if ((r1.bottom_left.x > r2.top_right.x && r1.top_right.x < r2.bottom_left.x) && r1.top_right.y>r2.bottom_left.y && r1.bottom_left.y<r2.top_right.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
double Collision::GetDistanceX(Math::rect r1, Math::rect r2)
{
	if (CollisionCheck(r1, r2))
	{
		if (r1.top_right.x < r2.top_right.x)
		{
			return(r2.bottom_left.x-r1.top_right.x);
		}
		else
		{
			return(r1.bottom_left.x-r2.top_right.x);
		}
	}
	else
	{
		return NULL;
	}
}
double Collision::GetDistanceY(Math::rect r1, Math::rect r2)
{
	if (CollisionCheck(r1, r2))
	{
		if (r1.top_right.y < r2.top_right.y)
		{
			return(r1.top_right.y-r2.bottom_left.y);
		}
		else
		{
			return(r2.top_right.y-r1.bottom_left.y);
		}
	}
	else
	{
		return NULL;
	}
}