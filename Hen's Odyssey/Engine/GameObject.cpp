
#include "GameObject.h"
#include "Vec2.h"
#include "Matrix.h"


CS230::GameObject::GameObject(Math::vec2 position) :
    GameObject(position, 0, { 1, 1, 1 })
{
    current_state = &state_none;

}

CS230::GameObject::GameObject(Math::vec2 position, double rotation, Math::vec2 scale) :
    velocity({ 0,0,0 }),
    position(position),
    scale(scale),
    rotation(rotation)

{
    current_state = &state_none;
    matrix_outdated = true;
}

void CS230::GameObject::Update(double dt) {
    current_state->Update(this, dt);
   // sprite.Update(dt);
    if (velocity.x != 0 || velocity.y != 0) {
        UpdatePosition(velocity * dt);
    }
    current_state->CheckExit(this);
}

void CS230::GameObject::change_state(State* new_state) {
    current_state = new_state;
    current_state->Enter(this);
}



void CS230::GameObject::Draw(Math::TransformationMatrix camera_matrix) {

  //  sprite.Draw(camera_matrix * GetMatrix());

}

const Math::TransformationMatrix& CS230::GameObject::GetMatrix() {
    if (matrix_outdated = true) {
        object_matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(rotation) * Math::ScaleMatrix(scale);
        matrix_outdated = false;
    }
    return object_matrix;
}
const Math::vec2& CS230::GameObject::GetPosition() const {
    return position;
}
const Math::vec2& CS230::GameObject::GetVelocity() const {
    return velocity;
}

void CS230::GameObject::SetPosition(Math::vec2 new_position) {
    position = new_position;
    matrix_outdated = true;
}

void CS230::GameObject::UpdatePosition(Math::vec2 delta) {
    position += delta;
    matrix_outdated = true;
}


const Math::vec2& CS230::GameObject::GetScale() const {
    return scale;
}

double CS230::GameObject::GetRotation() const {
    return rotation;
}

void CS230::GameObject::SetVelocity(Math::vec2 new_velocity) {
    velocity = new_velocity;
}

void CS230::GameObject::UpdateVelocity(Math::vec2 delta) {
    velocity += delta;
}

void CS230::GameObject::SetScale(Math::vec2 new_scale) {
    scale = new_scale;
    matrix_outdated = true;
}

void CS230::GameObject::UpdateScale(Math::vec2 delta) {
    scale += delta;
    matrix_outdated = true;
}

void CS230::GameObject::SetRotation(double new_rotation) {
    rotation = new_rotation;
    matrix_outdated = true;
}

void CS230::GameObject::UpdateRotation(double delta) {
    rotation += delta;
    matrix_outdated = true;
}