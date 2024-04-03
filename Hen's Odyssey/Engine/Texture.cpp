 /*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Texture.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#include "Texture.h"
#include "Engine.h"



void CS230::Texture::Load(const std::filesystem::path& file_name) {
    Image image = LoadImage(file_name.string().c_str());

    // �̹����� �ʺ�� ���� ��������
    texture.width = image.width;
    texture.height = image.height;
   
    texture = LoadTextureFromImage(image);
    SetTextureWrap(texture, TEXTURE_WRAP_CLAMP);
}

Math::ivec2 CS230::Texture::GetSize() const {
    
    return { texture.width, texture.height };
}

void CS230::Texture::Draw(Math::vec2 location) {
    location.y *= -1;
    location.y += Engine::GetWindow().GetSize().y - texture.height;
    DrawTexture(texture, int(location.x), int(location.y), WHITE);
}

CS230::Texture::Texture() { }

CS230::Texture::~Texture() {
    UnloadTexture(texture);
}

CS230::Texture::Texture(Texture&& temporary) noexcept : texture(temporary.texture) {
    temporary.texture.id = 0;
    temporary.texture.width = 0;
    temporary.texture.height = 0;
    temporary.texture.mipmaps = 0;
    temporary.texture.format = 0;
}

CS230::Texture& CS230::Texture::operator=(Texture&& temporary) noexcept {
    std::swap(texture.id, temporary.texture.id);
    std::swap(texture.width, temporary.texture.width);
    std::swap(texture.height, temporary.texture.height);
    std::swap(texture.mipmaps, temporary.texture.mipmaps);
    std::swap(texture.format, temporary.texture.format);
    return *this;
}
