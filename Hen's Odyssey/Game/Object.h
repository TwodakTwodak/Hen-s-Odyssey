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
    void RectChange();
private:
    CS230::Sprite sprite;
    Math::vec2 position= { 350, 250, 80 };
    Math::vec2 velocity;
    Math::rect object_rect;
};
