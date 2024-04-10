#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"
#include "Hen.h"
#include "Object.h"
#include "..\Engine\Collision.h"
#include "..\Engine\Rect.h"

class Stair {
public:
    void Load();
    void Update(double dt);
    void DrawBaseXY();
    void DrawBaseXZ();
    void CheckRoom(int get_room);
    int GiveRoom();
    void RoomChange(int get_room);
    void Reset();
    void RectChange();
    Math::rect GiveCollisionRect();
private:
    CS230::Sprite sprite;
    Collision collision;
    Hen hen;
    Object object;
    Math::rect pre_collision_rect;
    
};
