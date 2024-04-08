#include "Object.h"
#include "..\Engine\Engine.h"
#include "..\Engine\Sprite.h"
#include "..\Engine\Collision.h"
#include "..\Engine\Rect.h"
#include "iostream"

void Object::Load() {
    sprite.Load("Assets/Object.png", { 0, 0, 0 });
    velocity.x = 0;
    velocity.y = 0;

}

void Object::Update(double dt) {
}

void Object::RectChange(){
    //std::cout << position.x - sprite.GetTextureSize().x/2 << " " << position.y - sprite.GetTextureSize().y/2 << std::endl;
    object_rect = { {position.x + sprite.GetTextureSize().x/2, 600 - (position.y + sprite.GetTextureSize().y / 2), 600 - (position.z + sprite.GetTextureSize().z / 2) },
        {position.x - sprite.GetTextureSize().x / 2, 600 - (position.y - sprite.GetTextureSize().y / 2), 600 - (position.z - sprite.GetTextureSize().z / 2)}
    };
}

void Object::DrawBaseXY(){
    sprite.DrawBaseXY({ position.x, position.y, position.y });
    sprite.DrawCollisionScope(position.x, 600 - (position.y + sprite.GetTextureSize().y), sprite.GetTextureSize().x, sprite.GetTextureSize().y);
}

void Object::DrawBaseXZ() {
    sprite.DrawBaseXZ({ position.x, position.y, position.y });
    sprite.DrawCollisionScope(position.x, 600 - (position.z + sprite.GetTextureSize().z), sprite.GetTextureSize().x, sprite.GetTextureSize().z);
}
Math::rect Object::GiveCollisionRect()
{
    return object_rect;
}

Math::vec2 Object::GivePosition()
{
    return position;
}
void Object::GetPosition(Math::vec2 get_position)
{
    position = get_position;
}