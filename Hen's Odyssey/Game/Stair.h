#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"
#include "Hen.h"
#include "Object.h"
#include "..\Engine\Collision.h"

class Stair {
public:
    void Load();
    void Update(double dt);
    void Draw();
    void CheckRoom(int get_room);
    int GiveRoom();
    void RoomChange(int get_room);
private:
    CS230::Sprite sprite;
    Math::vec2 start_position;
    Math::vec2 position;
    Math::vec2 velocity;
    Collision collision;
    Hen hen;
    Object object;

    
};
