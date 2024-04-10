#include "Button.h"
#include "..\Engine\Engine.h"
#include "..\Engine\Sprite.h"
#include "..\Engine\Collision.h"
#include "..\Engine\Rect.h"
#include "iostream"

Math::vec2 button_position = { 700, 50, 80 };

void Button::LoadXY() {
    sprite_button.Load("Assets/TopButton.png", { 0, 0, 0 });
}

void Button::LoadXZ() {
    sprite_button.Load("Assets/SideButton.png", { 0, 0, 0 });
}

void Button::RectChange() {
    button_rect = { {button_position.x + sprite_button.GetTextureSize().x, Engine::GetWindow().GetSize().y - (button_position.y + sprite_button.GetTextureSize().y), Engine::GetWindow().GetSize().y - (button_position.z + sprite_button.GetTextureSize().y) },
        {button_position.x, Engine::GetWindow().GetSize().y - button_position.y, Engine::GetWindow().GetSize().y - button_position.z}
    };
}

void Button::DrawBaseXY() {
    sprite_button.DrawBaseXY({ button_position });
    sprite_button.DrawCollisionScope(button_position.x, Engine::GetWindow().GetSize().y - button_position.y, sprite_button.GetTextureSize().x, -sprite_button.GetTextureSize().y);
}

void Button::DrawBaseXZ() {
    sprite_button.DrawBaseXZ({ button_position });
    sprite_button.DrawCollisionScope(button_position.x, Engine::GetWindow().GetSize().y - button_position.z, sprite_button.GetTextureSize().x, -sprite_button.GetTextureSize().y);
}
Math::rect Button::GiveCollisionRect()
{
    return button_rect;
}

Math::vec2 Button::GivePosition()
{
    return button_position;
}

Math::ivec2 Button::GiveSize()
{
    return sprite_button.GetTextureSize();
}

bool Button::IsButtonPushed()
{
    return pushed_button;
}

void Button::GetButtonPushed(bool button)
{
    pushed_button = button;
}