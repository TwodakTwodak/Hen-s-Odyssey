#pragma once

#pragma once
#include <filesystem>
#include <map>

namespace CS230 {
    class Texture;

    class TextureManager {
    public:
        Texture* Load(const std::filesystem::path& file_name);
        void Unload();

    private:
        std::map<std::filesystem::path, Texture*> textures;
    };
}