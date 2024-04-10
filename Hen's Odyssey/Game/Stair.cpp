#include "Stair.h"

int room = 1;
bool floor_move = true;
bool reset = false;
Math::vec2 stair_position = { 1200, 300, 80 };

void Stair::Load() {
	sprite.Load("Assets/Object.png", { 0, 0, 0 });
}

void Stair::CheckRoom(int get_room)
{
	room = get_room;
}

void Stair::Update(double dt)
{
	if (floor_move||reset)
	{
		floor_move = false;
		reset = false;
		if (room == 1)
		{
			object.GetPosition({ 350, 250, 80 });
			hen.GetPosition({ 100, 300, 80 });
			object.GetObjectMovemence(true);
		}
		if (room == 2)
		{
			object.GetPosition({ 650, 300, 80 });
			hen.GetPosition({ 100, 300, 80 });
			object.GetObjectMovemence(false);
		}
		if (room == 3)
		{
			object.GetPosition({ -100, -100, 100});
			hen.GetPosition({ 100, 300, 80 });
			object.GetObjectMovemence(false);
		}
	}
	
}

int Stair::GiveRoom()
{
	return room;
}

void Stair::RoomChange(int get_room)
{
	if (get_room == 1 && room != 3)
	{
		room++;
		floor_move = true;
	}
	else if (get_room == 2 && room != 1)
	{
		room--;
		floor_move = true;
	}
}

void Stair::Reset()
{
	reset = true;
}

void Stair::RectChange() {
	pre_collision_rect = { {stair_position.x + sprite.GetTextureSize().x, Engine::GetWindow().GetSize().y - (stair_position.y + sprite.GetTextureSize().y), Engine::GetWindow().GetSize().y - (stair_position.z + sprite.GetTextureSize().y) },
		{stair_position.x, Engine::GetWindow().GetSize().y - stair_position.y, Engine::GetWindow().GetSize().y - stair_position.z}
	};
}

void Stair::DrawBaseXY() {
	sprite.DrawBaseXY(stair_position);
	sprite.DrawCollisionScope(stair_position.x, Engine::GetWindow().GetSize().y - (stair_position.y), sprite.GetTextureSize().x, -sprite.GetTextureSize().y);
}

void Stair::DrawBaseXZ() {
	sprite.DrawBaseXZ(stair_position);
	sprite.DrawCollisionScope(stair_position.x, Engine::GetWindow().GetSize().y - (stair_position.z), sprite.GetTextureSize().x, -sprite.GetTextureSize().y);
}

Math::rect Stair::GiveCollisionRect()
{
	return pre_collision_rect;
}