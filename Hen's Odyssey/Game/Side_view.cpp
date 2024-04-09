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
    sprite.Load("Assets/Cat.png", { 0, 0, 0 });
	object.Load();
	velocity.x = 0;
	velocity.y = 0;
	velocity.z = 0;
	jumping = false;
	going_up = false;
}


void Hen_side::Update(double dt) {
	position.x = hen.GivePosition().x;
	position.z = hen.GivePosition().z;
	velocity = hen.GiveVelocity();
	hen.RectChange(sprite.GetTextureSize());
	object.RectChange();
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
	
	hen.PreRectChange(sprite.GetTextureSize(), velocity.x * dt, 0, velocity.z * dt);
	//std::cout << position.x << " " << object.GivePosition().x << " " << sprite.GetTextureSize().x << std::endl;
	//std::cout << position.z << " " << object.GivePosition().z << " " << sprite.GetTextureSize().y << std::endl;
	if (collision.CollisionCheck(hen.PreGiveCollisionRect(), object.GiveCollisionRect()))
	{
		Engine::GetLogger().LogDebug("\nCollision\n");
		if (position.x+ sprite.GetTextureSize().x < object.GivePosition().x+object.GiveSize().x/2 )
		{
			position.x = object.GivePosition().x -sprite.GetTextureSize().x;
			
		}
		else
		{
			position.x = object.GivePosition().x + object.GiveSize().x;
		}
	}
	else
	{
		position.x += velocity.x * dt;
		position.z += velocity.z * dt;
	}
	
	
	hen.GetPosition(position);
	hen.GetVelocity(velocity);
	hen.RectChange(sprite.GetTextureSize());
}

void Hen_side::Draw() {
	object.DrawBaseXZ();
	sprite.DrawBaseXZ(position);
	sprite.DrawCollisionScope(position.x, 600 - (position.z), sprite.GetTextureSize().x, -sprite.GetTextureSize().y);
}
