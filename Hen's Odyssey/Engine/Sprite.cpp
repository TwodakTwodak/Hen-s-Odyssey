 #include "Engine.h"
#include "Sprite.h"
#include <iostream>

CS230::Sprite::Sprite():hotspot(0, 0) { }

void CS230::Sprite::Load(const std::filesystem::path& texture_path) {
    texture.Load(texture_path);
}

void CS230::Sprite::Load(const std::filesystem::path& texture_path, Math::ivec2 hotspot_position) {
    texture.Load(texture_path.string().c_str());
    hotspot.x = hotspot_position.x;
    hotspot.y = hotspot_position.y;
}

void CS230::Sprite::Draw(Math::vec2 position) {
    position.x -= hotspot.x;
    position.y -= hotspot.y; 
    texture.Draw(position);
}




Math::ivec2 CS230::Sprite::GetTextureSize() {
    return { texture.GetSize().x, texture.GetSize().y };
}