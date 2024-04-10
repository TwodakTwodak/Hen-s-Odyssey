 /*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Cat.h
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"
#include "Hen.h"
#include "Object.h"
#include "..\Engine\Collision.h"

class Hen_side {
public:
    Hen_side(Math::vec2 start_position);
    void Load();
    void Update(double dt);
    void Draw();
    void CheckRoom(int get_room);
private:
    CS230::Sprite sprite;
    Math::vec2 start_position; 
    Math::vec2 position;
    Math::vec2 velocity;
    Collision collision;
    Hen hen;
    Object object;

    bool jumping = false;
    bool going_up = false;

    static constexpr double velocity_speed = 200;

    int room = 1;
};
