#pragma once
#include "Engine.h"
#include "Rect.h"

class Collision
{
public:
	double GetDistanceX(Math::rect r1, Math::rect r2);
	double GetDistanceY(Math::rect r1, Math::rect r2);
	bool CollisionCheck(Math::rect r1, Math::rect r2);
private:

};