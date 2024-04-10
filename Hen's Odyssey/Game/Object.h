#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Vec2.h"
#include "..\Engine\Rect.h"

class Object {
public:
    void Load();
    void Update(double dt);
    void DrawBaseXY();
    void DrawBaseXZ();
    Math::rect GiveCollisionRect();
    Math::vec2 GivePosition();
    void GetPosition(Math::vec2 get_position);
    Math::ivec2 GiveSize();
    void GetObjectMovemence(bool characteristic);
    void RectChange();
    bool GiveObjectMovemence();
    
private:
    CS230::Sprite sprite;
    Math::rect object_rect;
    bool moving_object = false;
};
