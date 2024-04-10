#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"
#include "Hen.h"
#include "Object.h"
#include "..\Engine\Collision.h"
#include "Stair.h"
#include "Button.h"

class Hen_side {
public:
    Hen_side(Math::vec2 start_position);
    void Load();
    void Update(double dt);
    void Draw();
private:
    CS230::Sprite sprite;
    Math::vec2 start_position; 
    Math::vec2 position;
    Math::vec2 velocity;
    Collision collision;
    Hen hen;
    Object object;
    Stair stair;
    Button button;

    bool jumping = false;
    bool going_up = false;

    static constexpr double velocity_speed = 200;

    bool hen_move = true;
    bool object_move = true;
};
