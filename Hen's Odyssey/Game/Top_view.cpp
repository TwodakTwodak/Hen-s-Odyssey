 #pragma once
#include "Top_view.h"
#include "..\Engine\Engine.h"
#include "..\Engine\Sprite.h"
#include "..\Engine\Collision.h"
#include "..\Engine\Rect.h"
#include <iostream>

Hen_top::Hen_top(Math::vec2 start_position) :
    position(start_position)
{
}

void Hen_top::Load() {
    sprite.Load("Assets/Ship.png", { 0, 0});
    //position.x = sprite.GetTextureSize().x;
    //position.y = -sprite.GetTextureSize().y / 2 + Engine::GetWindow().GetSize().y / 2;
    velocity.x = 0;
    velocity.y = 0;
    
}

void Hen_top::Update(double dt) {
    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::D)) //3
    {
        current_new = 3;
        key[3] = 2;
    }
    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::A)) //1
    {
        current_new = 1;
        key[1] = 2;
    }
    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::W)) //0
    {
        current_new = 0;
        key[0] = 2;
    }
    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::S)) //2
    {
        current_new = 2;
        key[2] = 2;
    }

    if (Engine::GetInput().KeyDown(CS230::Input::Keys::D)) //3
    {
        if (key[3] == 2 && current_new != 3)
        {
            key[3] = 1;
        }

    }
    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::A))//1
    {
        if (key[1] == 2 && current_new != 1)
        {
            key[1] = 1;
        }
    }
    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::W)) //0
    {
        if (key[0] == 2 && current_new != 0)
        {
            key[0] = 1;
        }
    }
    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::S))//2
    {
        if (key[2] == 2 && current_new != 2)
        {
            key[2] = 1;
        }
    }
    else
    {
        current_new = -1;
        key[1] = 0;
        key[3] = 0;
        key[0] = 0;
        key[2] = 0;
    }
    
    if (current_new >= 0 && current_new < 4)
    {
        if (current_new % 2 == 0)
        {
            velocity.y = velocity_speed * -(current_new - 1);
            velocity.x = 0;
        }
        else
        {
            velocity.x = velocity_speed * (current_new - 2);
            velocity.y = 0;
        }
    }
    else
    {
        current_new = -1;
        velocity.x = 0;
        velocity.y = 0;
    }

    for (int i = 0; i <= 10; i++)
    {
        DrawLine(i * 100, 0, i * 100, 1000, WHITE);
        DrawLine(0, i*100, 1000, i*100, WHITE);
    }
    


    Engine::GetLogger().LogDebug("Velocity: " + std::to_string(velocity.x) + ", " + std::to_string(velocity.y));

    position += velocity * dt;
    
    if (position.x < -sprite.GetTextureSize().x)
    {
        position.x = sprite.GetTextureSize().x / 2 + Engine::GetWindow().GetSize().x;
    }
    if (position.x > sprite.GetTextureSize().x + Engine::GetWindow().GetSize().x)
    {
        position.x = -sprite.GetTextureSize().x / 2;
    }
    if (position.y < -sprite.GetTextureSize().y)
    {
        position.y = sprite.GetTextureSize().y / 2 + Engine::GetWindow().GetSize().y;
    }
    if (position.y > sprite.GetTextureSize().y+ Engine::GetWindow().GetSize().y)
    {
        position.y = -sprite.GetTextureSize().y / 2;
    }
    //Test for wrap, here
    Math::rect r1 = { {position.x+ sprite.GetTextureSize().x / 2, position.y- sprite.GetTextureSize().y / 2},
        {position.x - sprite.GetTextureSize().x / 2, position.y + sprite.GetTextureSize().y / 2}
    };
    Math::rect r2 = { {double(GetScreenWidth() / 10) + sprite.GetTextureSize().x / 2, double(GetScreenHeight() / 2) - sprite.GetTextureSize().y / 2},
        {double(GetScreenWidth() / 10) - sprite.GetTextureSize().x / 2, double(GetScreenHeight() / 2)  + sprite.GetTextureSize().y / 2}
    };
    if (collision.GetDistanceY(r1, r2)) Engine::GetLogger().LogDebug("\nCollision\n");

}

void Hen_top::Draw() {
    sprite.Draw({ position.x, position.y });
    sprite.Draw({ double(GetScreenWidth() / 10), double(GetScreenHeight() / 2) });
}