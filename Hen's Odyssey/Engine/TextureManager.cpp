
#include "TextureManager.h"
#include "Texture.h" 
#include "Engine.h"

namespace CS230 {
    Texture* TextureManager::Load(const std::filesystem::path& file_name) {
        if (textures.find(file_name) == textures.end())
        {
            textures.insert({ file_name, new Texture(file_name) });
            Engine::GetLogger().LogEvent("Loading Texture: " + file_name.string());
        }


        return textures[file_name];
    }

    void TextureManager::Unload() {

        for (auto pair = textures.begin(); pair != textures.end(); ++pair) {
            delete pair->second;
        }
        textures.clear();
        Engine::GetLogger().LogEvent("Clearing Textures");

    }
}