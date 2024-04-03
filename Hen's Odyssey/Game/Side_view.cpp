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

Hen_side::Hen_side(Math::vec2 start_position) :
    start_position(start_position),
    position(start_position)
{
	position.x = start_position.x;
	position.y = start_position.y;
}

void Hen_side::Load() {
    sprite.Load("Assets/Cat.png", { 64, 15 });
	velocity.x = 0;
	velocity.y = 0;
	jumping = false;
	going_up = false;
}


void Hen_side::Update(double dt) {
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
	position.y += velocity.y * dt;

}


void Hen_side::Draw() {
    sprite.Draw(position);
}
