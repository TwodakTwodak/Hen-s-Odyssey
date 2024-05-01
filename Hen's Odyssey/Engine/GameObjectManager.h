
#pragma once
#include <vector>
#include "GameObject.h"
#include "Matrix.h"

namespace Math { class TransformationMatrix; }

namespace CS230 {
    class GameObjectManager {
    public:
        void Add(GameObject* object);
        void Unload();

        void UpdateAll(double dt);
        void DrawAll(Math::TransformationMatrix camera_matrix);
    private:
        std::vector<GameObject*> objects;
    };
}
