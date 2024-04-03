 #pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"
#include "..\Engine\Rect.h"
#include "..\Engine\Collision.h"

class Hen_top {
public:
    Hen_top(Math::vec2 start_position);
    void Load();
    void Update(double dt);
    void Draw();

private:
    Math::vec2 start_position = {0, 0};
    CS230::Sprite sprite;
    Math::vec2 position = { 0, 0};
    Collision collision;

    Math::vec2 velocity;

    static constexpr double velocity_speed = 200;

    bool key_down = false;

    int key[4] = { 0, 0, 0, 0};
    int current_new = -1;
};
