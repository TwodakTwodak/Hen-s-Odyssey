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
#include "Rect.h"


void CS230::Texture::Load(const std::filesystem::path& file_name) {
    Image image = LoadImage(file_name.string().c_str());

    // 이미지의 너비와 높이 가져오기
    texture.width = image.width;
    texture.height = image.height;
   
    texture = LoadTextureFromImage(image);
    SetTextureWrap(texture, TEXTURE_WRAP_CLAMP);
}

Math::ivec2 CS230::Texture::GetSize() const {
    
    return { texture.width, texture.height, 0 };
}

void CS230::Texture::DrawBaseXY(Math::vec2 location) {
    location.y *= -1;
    location.y += Engine::GetWindow().GetSize().y - texture.height;
    DrawTexture(texture, int(location.x), int(location.y), WHITE);
}

void CS230::Texture::DrawBaseXZ(Math::vec2 location) {
    location.z *= -1;
    location.z += Engine::GetWindow().GetSize().y - texture.height;
    DrawTexture(texture, int(location.x), int(location.z), WHITE);
}


void CS230::Texture::DrawCollisionScope(double x, double y, double width, double height) {
    DrawRectangleLines(x, y, width, height, WHITE);
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
/*#include "Texture.h"
#include "Engine.h"

CS230::Texture::Texture(const std::filesystem::path& file_name) {
    texture = LoadTexture(file_name.string().c_str());
    SetTextureWrap(texture, TEXTURE_WRAP_CLAMP);
}


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

Math::ivec2 CS230::Texture::GetSize() const {
    return { texture.width, texture.height };
}

void CS230::Texture::Draw(Math::TransformationMatrix display_matrix, Math::vec3 position, Math::vec3 scale) {
    Math::vec3 bottom_left = position + scale * Math::vec3{ -0.5f, -0.5f, 0.0f };
    Math::vec3 bottom_right = position + scale * Math::vec3{ 0.5f, -0.5f, 0.0f };
    Math::vec3 top_left = position + scale * Math::vec3{ -0.5f, 0.5f, 0.0f };
    Math::vec3 top_right = position + scale * Math::vec3{ 0.5f, 0.5f, 0.0f };

    bottom_left = display_matrix * bottom_left;
    bottom_right = display_matrix * bottom_right;
    top_left = display_matrix * top_left;
    top_right = display_matrix * top_right;

    const double H = Engine::GetWindow().GetSize().y;

    constexpr Color tint = WHITE;

    rlSetTexture(texture.id);
    rlBegin(RL_QUADS);
    rlColor4ub(tint.r, tint.g, tint.b, tint.a);
    rlNormal3f(0.0f, 0.0f, 1.0f);
    rlTexCoord2f(0, 0);
    rlVertex3f(bottom_left.x, bottom_left.y, bottom_left.z);
    rlTexCoord2f(0, 1);
    rlVertex3f(top_left.x, top_left.y, top_left.z);
    rlTexCoord2f(1, 1);
    rlVertex3f(top_right.x, top_right.y, top_right.z);
    rlTexCoord2f(1, 0);
    rlVertex3f(bottom_right.x, bottom_right.y, bottom_right.z);
    rlEnd();
    rlSetTexture(0);
}

void CS230::Texture::Draw(Math::TransformationMatrix display_matrix, Math::vec3 position, Math::vec3 scale, Math::vec3 rotation_axis, float rotation_angle) {
    Math::vec3 bottom_left = position + scale * Math::vec3{ -0.5f, -0.5f, 0.0f };
    Math::vec3 bottom_right = position + scale * Math::vec3{ 0.5f, -0.5f, 0.0f };
    Math::vec3 top_left = position + scale * Math::vec3{ -0.5f, 0.5f, 0.0f };
    Math::vec3 top_right = position + scale * Math::vec3{ 0.5f, 0.5f, 0.0f };

    // Apply rotation
    Math::quat rotation_quaternion = Math::quat::FromAxisAngle(rotation_axis, rotation_angle);
    bottom_left = rotation_quaternion * bottom_left;
    bottom_right = rotation_quaternion * bottom_right;
    top_left = rotation_quaternion * top_left;
    top_right = rotation_quaternion * top_right;

    // Apply transformation matrix
    bottom_left = display_matrix * bottom_left;
    bottom_right = display_matrix * bottom_right;
    top_left = display_matrix * top_left;
    top_right = display_matrix * top_right;

    const double H = Engine::GetWindow().GetSize().y;

    constexpr Color tint = WHITE;

    rlSetTexture(texture.id);
    rlBegin(RL_QUADS);
    rlColor4ub(tint.r, tint.g, tint.b, tint.a);
    rlNormal3f(0.0f, 0.0f, 1.0f);
    rlTexCoord2f(0, 0);
    rlVertex3f(bottom_left.x, bottom_left.y, bottom_left.z);
    rlTexCoord2f(0, 1);
    rlVertex3f(top_left.x, top_left.y, top_left.z);
    rlTexCoord2f(1, 1);
    rlVertex3f(top_right.x, top_right.y, top_right.z);
    rlTexCoord2f(1, 0);
    rlVertex3f(bottom_right.x, bottom_right.y, bottom_right.z);
    rlEnd();
    rlSetTexture(0);
}
*/
