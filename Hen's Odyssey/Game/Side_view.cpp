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
    sprite.Load("Assets/Cat.png", { 64, 0, 15 });
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
	position.x += velocity.x * dt;
	position.z += velocity.z * dt;
	hen.GetPosition(position);
	hen.GetVelocity(velocity);
	hen.RectChange(sprite.GetTextureSize());
	std::cout << position.z << std::endl;
}


void Hen_side::Draw() {
	sprite.DrawBaseXZ({ position});
}
