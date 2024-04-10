 #pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"
#include "..\Engine\Rect.h"
#include "..\Engine\Collision.h"
#include "..\Engine\Window.h"
#include "Hen.h"
#include "Object.h"

class Hen_top {
public:
    Hen_top(Math::vec2 start_position);
    void Load();
    void Update(double dt);
    void Draw();
    void CheckRoom(int get_room);
private:
    CS230::Sprite sprite;
    Collision collision;
    CS230::Window window;
    Math::vec2 position;
    Math::vec2 velocity;
    Hen hen;
    //std::vector<Object> objects;
    Object object;

    static constexpr double velocity_speed = 200;

    bool key_down = false;

    int key[4] = { 0, 0, 0, 0};
    int current_new = -1;

    int room = 1;
};
