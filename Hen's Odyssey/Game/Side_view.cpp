 /*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Cat.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once
#include "Side_view.h"
#include "../Engine/Engine.h"
#include "Mode1.h"
#include "iostream"

//x, z

Hen_side::Hen_side(Math::vec2 start_position) :
    start_position(start_position),
    position(start_position), object()
{
	position.x = hen.GivePosition().x;
	position.z = start_position.z;
}

void Hen_side::Load() {
    sprite.Load("Assets/SideHen.png", { 0, 0, 0 });
	object.Load();
	stair.Load();
	button.Load();
	velocity.x = 0;
	velocity.y = 0;
	velocity.z = 0;
	jumping = false;
	going_up = false;
}


void Hen_side::Update(double dt) {
	hen_move = true;
	if (stair.GiveRoom() == 1) object.GetObjectMovemence(false);
	if (stair.GiveRoom() == 2) object.GetObjectMovemence(true);
	position.x = hen.GivePosition().x;
	position.z = hen.GivePosition().z;
	velocity = hen.GiveVelocity();
	hen.RectChange(sprite.GetTextureSize());
	object.RectChange();
	stair.RectChange();
	if (Engine::GetInput().KeyDown(CS230::Input::Keys::D)) {
		velocity.x = velocity_speed;
	}
	else if(Engine::GetInput().KeyDown(CS230::Input::Keys::A))
	{
		velocity.x = -velocity_speed;
	}
	else
	{
		velocity.x = 0;
	}

	double vx = velocity.x * dt;
	double vz = velocity.z * dt;

	if (position.x + vx < 0)
	{
		position.x = 0;
		hen_move = false;
	}
	if (position.x + vx + sprite.GetTextureSize().x > Engine::GetWindow().GetSize().x)
	{
		position.x = Engine::GetWindow().GetSize().x - sprite.GetTextureSize().x;
		hen_move = false;
	}
	if (position.z + vz < 0)
	{
		position.z = 0;
		hen_move = false;
	}
	if (position.z + vz + sprite.GetTextureSize().y > Engine::GetWindow().GetSize().y)
	{
		position.z = Engine::GetWindow().GetSize().y - sprite.GetTextureSize().y;
		hen_move = false;
	}
	
	hen.PreRectChange(sprite.GetTextureSize(), velocity.x * dt, 0, velocity.z * dt);
	if (collision.CollisionCheck(hen.PreGiveCollisionRect(), object.GiveCollisionRect()))
	{
		Engine::GetLogger().LogDebug("\nCollision\n");
		if (object.GiveObjectMovemence())
		{
			if (object_move)
			{
				position.x += velocity.x * dt;
				position.z += velocity.z * dt;
			}
			
			if (velocity.x > 0)
			{
				object.GetPosition({ position.x + sprite.GetTextureSize().x, object.GivePosition().y , object.GivePosition().z });
			}
			else if(velocity.x < 0)
			{
				object.GetPosition({ position.x - object.GiveSize().x, object.GivePosition().y , object.GivePosition().z });
			}
			else
			{
				if (position.x + sprite.GetTextureSize().x < object.GivePosition().x + object.GiveSize().x / 2)
				{
					object.GetPosition({ position.x + sprite.GetTextureSize().x, object.GivePosition().y , object.GivePosition().z });
				}
				else
				{
					object.GetPosition({ position.x - object.GiveSize().x, object.GivePosition().y , object.GivePosition().z });
				}
			}
			
			object.RectChange();
		}
		else
		{
			if (position.x + sprite.GetTextureSize().x < object.GivePosition().x + object.GiveSize().x / 2)
			{
				position.x = object.GivePosition().x - sprite.GetTextureSize().x;
			}
			else
			{
				position.x = object.GivePosition().x + object.GiveSize().x;
			}
		}
		hen_move = false;
	}

	if (object.GivePosition().x + vx < 0 && position.x <= object.GivePosition().x + object.GiveSize().x)
	{
		object.GetPosition({ 0, object.GivePosition().y, object.GivePosition().z });
		position.x = object.GivePosition().x + object.GiveSize().x;
		hen_move = false;
	}
	if (object.GivePosition().x + vx + object.GiveSize().x > Engine::GetWindow().GetSize().x && position.x+sprite.GetTextureSize().x >= object.GivePosition().x)
	{
		object.GetPosition({ double(Engine::GetWindow().GetSize().x - object.GiveSize().x), object.GivePosition().y, object.GivePosition().z });
		position.x = Engine::GetWindow().GetSize().x - object.GiveSize().x-sprite.GetTextureSize().x;
		hen_move = false;
	}

	if (object.GivePosition().z + vz < 0 && position.z <= object.GivePosition().z + object.GiveSize().y)
	{
		object.GetPosition({ 0, object.GivePosition().y, object.GivePosition().z });
		position.z = object.GivePosition().z + object.GiveSize().y;
		hen_move = false;
	}
	if (object.GivePosition().z + vz + object.GiveSize().y > Engine::GetWindow().GetSize().y && position.z + sprite.GetTextureSize().y >= object.GivePosition().z)
	{
		object.GetPosition({ double(Engine::GetWindow().GetSize().y - object.GiveSize().y), object.GivePosition().y, object.GivePosition().z });
		position.z = Engine::GetWindow().GetSize().y - object.GiveSize().y - sprite.GetTextureSize().y;
		hen_move = false;
	}
	if(hen_move)
	{
		position.x += velocity.x * dt;
		position.z += velocity.z * dt;
	}
	
	if (collision.CollisionCheck(hen.PreGiveCollisionRect(), stair.GiveCollisionRect()))
	{
		stair.RoomChange(1);
	}
	
	hen.GetPosition(position);
	hen.GetVelocity(velocity);
	hen.RectChange(sprite.GetTextureSize());
}

void Hen_side::Draw() {
	if (stair.GiveRoom() != 3)
	{
		object.DrawBaseXZ();
	}
	sprite.DrawBaseXZ(position);
	sprite.DrawCollisionScope(position.x, Engine::GetWindow().GetSize().y - (position.z), sprite.GetTextureSize().x, -sprite.GetTextureSize().y);
}


