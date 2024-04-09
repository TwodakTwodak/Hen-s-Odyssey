 /*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Asteroid.h
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Vec2.h"
#include "..\Engine\Rect.h"

class Hen {
public: 
    void GetVelocity(Math::vec2 get_velocity);
    Math::vec2 GiveVelocity();
    void GetPosition(Math::vec2 get_position);
    Math::vec2 GivePosition();
    void RectChange(Math::ivec2 hen_size);
    void PreRectChange(Math::ivec2 hen_size, double x, double y, double z);
    Math::rect GiveCollisionRect();
    Math::rect PreGiveCollisionRect();
private:
    CS230::Sprite sprite;
    Math::vec2 position = {100, 300, 80 };
    Math::vec2 velocity;
    Math::rect collision_rect;
    Math::rect pre_collision_rect;
};

