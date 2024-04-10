#include "Stair.h"

int room = 1;
int floor_move = true;

void Stair::CheckRoom(int get_room)
{
	room = get_room;
}

void Stair::Update(double dt)
{
	if (floor_move)
	{
		floor_move = false;
		if (room == 1)
		{
			object.GetPosition({ 350, 250, 80 });
			hen.GetPosition({ 100, 300, 80 });
		}
		if (room == 2)
		{
			object.GetPosition({ 450, 300, 80 });
			hen.GetPosition({ 100, 300, 80 });
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
		object.GetObjectMovemence(false);
	}
	else if (get_room == 2 && room != 1)
	{
		room--;
		floor_move = true;
		object.GetObjectMovemence(true);
	}
}
