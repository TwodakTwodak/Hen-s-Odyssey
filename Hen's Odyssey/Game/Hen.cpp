#pragma once
#include "Hen.h"
#include "../Engine/Engine.h"
#include "Mode1.h"


Hen::Hen(Math::vec2 start_position) :
    start_position(start_position),
    position(start_position)
{}

void Hen::Load() {
    sprite .Load("Assets/Asteroid.png", { 70, 3 });
    position.x = start_position.x;
    position.y = start_position.y;
    velocity.x = 0;
    velocity.y = 0; 
}

void Hen::Draw() {
    sprite.Draw(position);
}

void Hen::Update(double dt) {
    velocity.y -= Mode1::gravity * dt;
    position += velocity * dt;

    if (position.y < Mode1::floor) {
        position.y = Mode1::floor;
        velocity.y = bounce_velocity;
    }
}
