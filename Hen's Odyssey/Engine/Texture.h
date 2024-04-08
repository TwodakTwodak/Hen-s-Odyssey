 /*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Texture.h
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once
#include "Vec2.h"
#include <filesystem>
#include <raylib.h>

namespace CS230 {
    class Texture {
    public:
        Texture();
        ~Texture();

        Texture(const Texture&) = delete;
        Texture& operator=(const Texture&) = delete;
        Texture(Texture&& temporary) noexcept;
        Texture& operator=(Texture&& temporary) noexcept;

        void Load(const std::filesystem::path& file_name);
        void DrawBaseXY(Math::vec2 location);
        void DrawBaseXZ(Math::vec2 location);
        void DrawCollisionScope(double x, double y, double width, double height);
        Math::ivec2 GetSize() const;

    private:
        Texture2D texture;
    };
}
