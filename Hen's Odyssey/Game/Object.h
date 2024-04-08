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
    void RectChange();
private:
    CS230::Sprite sprite;
    Math::vec2 start_position;
    Math::vec2 position;
    Math::vec2 velocity;
    Math::rect object_rect;
};
