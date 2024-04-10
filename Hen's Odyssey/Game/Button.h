#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Vec2.h"
#include "..\Engine\Rect.h"

class Button {
public:
    void LoadXY();
    void LoadXZ();
    void DrawBaseXY();
    void DrawBaseXZ();
    Math::rect GiveCollisionRect();
    Math::vec2 GivePosition();
    Math::ivec2 GiveSize();
    void RectChange();
    bool IsButtonPushed();
    void GetButtonPushed(bool button);
    
private:
    CS230::Sprite sprite_button;
    Math::rect button_rect;
    bool pushed_button = false;
};
