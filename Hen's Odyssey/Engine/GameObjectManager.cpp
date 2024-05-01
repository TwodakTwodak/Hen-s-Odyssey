
#include "GameObjectManager.h"

namespace CS230 {
    void GameObjectManager::Add(GameObject* object) {
        objects.push_back(object);
    }

    void GameObjectManager::Unload() {
        for (auto& object : objects) {
            delete object;
        }
        objects.clear();
    }

    void GameObjectManager::UpdateAll(double dt) {
        for (auto& object : objects) {
            object->Update(dt);
        }
    }

    void GameObjectManager::DrawAll(Math::TransformationMatrix camera_matrix) {
        for (auto& object : objects) {
            object->Draw(camera_matrix);
        }
    }
}