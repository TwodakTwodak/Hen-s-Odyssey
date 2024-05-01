 #include "Engine.h"
#include "Sprite.h"
#include <iostream>
#include "TextureManager.h" 

CS230::Sprite::Sprite():hotspot(0, 0, 0) { }

void CS230::Sprite::Load(const std::filesystem::path& texture_path) {
    texture.Load(texture_path);
}

void CS230::Sprite::Load(const std::filesystem::path& texture_path, Math::ivec2 hotspot_position) {
    texture.Load(texture_path.string().c_str());
    hotspot.x = hotspot_position.x;
    hotspot.y = hotspot_position.y;
    hotspot.z = hotspot_position.z;
}

void CS230::Sprite::DrawBaseXY(Math::vec2 position) {
    position.x -= hotspot.x;
    position.y -= hotspot.y; 
    texture.DrawBaseXY(position);
}

void CS230::Sprite::DrawBaseXZ(Math::vec2 position) {
    position.x -= hotspot.x;
    position.z -= hotspot.z;
    texture.DrawBaseXZ(position);
}

void CS230::Sprite::DrawCollisionScope(double x, double y, double width, double height) {
    texture.DrawCollisionScope(x, y, width, height);
}


Math::ivec2 CS230::Sprite::GetTextureSize() {
    return { texture.GetSize().x, texture.GetSize().y, texture.GetSize().z };
}
void CS230::Sprite::Draw(Math::TransformationMatrix display_matrix) {
    texture->Draw(display_matrix * Math::TranslationMatrix(-GetHotSpot(0)), GetFrameTexel(animations[current_animation]->CurrentFrame()), GetFrameSize());
}