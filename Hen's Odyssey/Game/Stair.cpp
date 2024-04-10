#include "Stair.h"

int room = 1;
bool floor_move = true;
bool reset = false;

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
			object.GetPosition({ 450, 300, 80 });
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
	if (get_room == 1 && room != 2)
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
