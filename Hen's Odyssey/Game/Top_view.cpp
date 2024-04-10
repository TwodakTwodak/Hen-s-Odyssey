 #pragma once
#include "Top_view.h"
#include "..\Engine\Engine.h"
#include "..\Engine\Sprite.h"
#include "..\Engine\Collision.h"
#include "..\Engine\Rect.h"
#include <iostream>

//x, y

Hen_top::Hen_top(Math::vec2 start_position) :
    position(start_position), object()
{
}

void Hen_top::Load() {
    sprite.Load("Assets/Ship.png", { 0, 0, 0});
    position = hen.GivePosition();
    object.Load();
}

void Hen_top::Update(double dt) {
    hen_move = true;
    if (room == 1) object.GetObjectMovemence(false);
    if (room == 2) object.GetObjectMovemence(true);
    position.x=hen.GivePosition().x;
    position.y = hen.GivePosition().y;
    velocity=hen.GiveVelocity();
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

    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::D)) //3
    {
        current_new = -1;
        key[3] = 0;
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::A)) //1
    {
        current_new = -1;
        key[1] = 0;
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::W)) //0
    {
        current_new = -1;
        key[0] = 0;
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::S)) //2
    {
        current_new = -1;
        key[2] = 0;
    }
    if (current_new == -1)
    {
        if ((key[0] == 1 && key[2] == 1)|| (key[1] == 1 && key[3] == 1))
        {
            current_new = -1;
        }
        else
        {
            if (key[3] == 1) current_new = 3;
            if (key[1] == 1) current_new = 1;
            if (key[0] == 1) current_new = 0;
            if (key[2] == 1) current_new = 2;

        }
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

    for (int i = 0; i <= 800 /100; i++)
    {
        DrawLine(i * 100, 0, i * 100, 600, WHITE);
    }
    for (int j = 0; j <= 600 / 100; j++)
    {
        DrawLine(0, j * 100, 800, j * 100, WHITE);
    }
    
    double vx = velocity.x * dt;
    double vy = velocity.y * dt;

    Engine::GetLogger().LogDebug("Velocity: " + std::to_string(velocity.x) + ", " + std::to_string(velocity.y));

    
    
    if (position.x+vx < 0)
    {
        position.x = 0;
        hen_move = false;
    }
    if (position.x+vx+ sprite.GetTextureSize().x > Engine::GetWindow().GetSize().x)
    {
        position.x = Engine::GetWindow().GetSize().x - sprite.GetTextureSize().x;
        hen_move = false;
    }
    if (position.y+vy < 0)
    {
        position.y = 0;
        hen_move = false;
    }
    if (position.y+vy + sprite.GetTextureSize().y > Engine::GetWindow().GetSize().y)
    {
        position.y = Engine::GetWindow().GetSize().y - sprite.GetTextureSize().y;
        hen_move = false;
    }
    //Test for wrap, here
    hen.PreRectChange(sprite.GetTextureSize(), velocity.x* dt, velocity.y* dt, 0);
    if (collision.CollisionCheck(hen.PreGiveCollisionRect(), object.GiveCollisionRect()))
    {
        if (object.GiveObjectMovemence())
        {
            position += velocity * dt;
            if (current_new == 1 || current_new == 3)
            {
                if (velocity.x > 0)
                {
                    object.GetPosition({ position.x + sprite.GetTextureSize().x, object.GivePosition().y , object.GivePosition().z });
                }
                else if (velocity.x < 0)
                {
                    object.GetPosition({ position.x - object.GiveSize().x, object.GivePosition().y , object.GivePosition().z });
                }
                else
                {
                    if (position.x + sprite.GetTextureSize().x < object.GivePosition().x + object.GiveSize().x / 2)
                    {
                        object.GetPosition({ position.x + sprite.GetTextureSize().x, object.GivePosition().y , object.GivePosition().z });

                    }
                    else
                    {
                        object.GetPosition({ position.x - object.GiveSize().x, object.GivePosition().y , object.GivePosition().z });
                    }
                }
            }
            else if (current_new == 0 || current_new == 2)
            {
                if (velocity.y > 0)
                {
                    object.GetPosition({ object.GivePosition().x, position.y + sprite.GetTextureSize().y , object.GivePosition().z });
                }
                else if(velocity.y < 0)
                {
                    object.GetPosition({ object.GivePosition().x , position.y - object.GiveSize().y , object.GivePosition().z });
                }
                else
                {
                    if (position.y + sprite.GetTextureSize().y < object.GivePosition().y + object.GiveSize().y / 2)
                    {
                        object.GetPosition({ object.GivePosition().x, position.y + sprite.GetTextureSize().y , object.GivePosition().z });
                    }
                    else
                    {
                        object.GetPosition({ object.GivePosition().x , position.y - object.GiveSize().y , object.GivePosition().z });
                    }
                }
            }
            object.RectChange();
        }
        else
        {
            if (current_new == 1 || current_new == 3)
            {
                if (position.x + sprite.GetTextureSize().x < object.GivePosition().x + object.GiveSize().x / 2)
                {
                    position.x = object.GivePosition().x - sprite.GetTextureSize().x;
                }
                else
                {
                    position.x = object.GivePosition().x + object.GiveSize().x;
                }
            }
            else if (current_new == 0 || current_new == 2)
            {
                if (position.y + sprite.GetTextureSize().y < object.GivePosition().y + object.GiveSize().y / 2)
                {
                    position.y = object.GivePosition().y - sprite.GetTextureSize().y;
                }
                else
                {
                    position.y = object.GivePosition().y + object.GiveSize().y;
                }
            }
        }
        hen_move = false;
        
    }

    if (object.GivePosition().x + vx < 0 && position.x <= object.GivePosition().x + object.GiveSize().x&&position.y+sprite.GetTextureSize().y>object.GivePosition().y&&object.GivePosition().y+object.GiveSize().y>position.y)//check y axis as also
    {
        object.GetPosition({ 0, object.GivePosition().y, object.GivePosition().z });
        position.x = object.GivePosition().x + object.GiveSize().x;
        hen_move = false;
    }
    if (object.GivePosition().x + vx + object.GiveSize().x > Engine::GetWindow().GetSize().x && position.x + sprite.GetTextureSize().x >= object.GivePosition().x && position.y + sprite.GetTextureSize().y > object.GivePosition().y && object.GivePosition().y + object.GiveSize().y > position.y)
    {
        object.GetPosition({ double(Engine::GetWindow().GetSize().x - object.GiveSize().x), object.GivePosition().y, object.GivePosition().z });
        position.x = Engine::GetWindow().GetSize().x - object.GiveSize().x - sprite.GetTextureSize().x;
        hen_move = false;
    }

    if (object.GivePosition().y + vy < 0 && position.y <= object.GivePosition().y + object.GiveSize().y && position.x + sprite.GetTextureSize().x>object.GivePosition().x && object.GivePosition().x + object.GiveSize().x > position.x)
    {
        object.GetPosition({ object.GivePosition().x, 0, object.GivePosition().z });
        position.y = object.GivePosition().y + object.GiveSize().y;
        hen_move = false;
    }
    if (object.GivePosition().y + vy + object.GiveSize().y > Engine::GetWindow().GetSize().y && position.y + sprite.GetTextureSize().y >= object.GivePosition().y && position.x + sprite.GetTextureSize().x > object.GivePosition().x && object.GivePosition().x + object.GiveSize().x > position.x)
    {
        object.GetPosition({object.GivePosition().x, double(Engine::GetWindow().GetSize().y - object.GiveSize().y), object.GivePosition().z });
        position.y = Engine::GetWindow().GetSize().y - object.GiveSize().y - sprite.GetTextureSize().y;
        hen_move = false;
    }

    if (hen_move)
    {
        position += velocity * dt;
    }
    
    hen.GetPosition(position);
    hen.GetVelocity(velocity);
    hen.RectChange(sprite.GetTextureSize());
    object.RectChange();
    /*if (collision.GetDistanceY(hen.GiveCollisionRect(), object.GiveCollisionRect()))
    {
        Engine::GetLogger().LogDebug("\nCollision\n");
        Engine::GetLogger().LogDebug("x: "+ std::to_string((collision.GetDistanceX(hen.GiveCollisionRect(), object.GiveCollisionRect()))));
        Engine::GetLogger().LogDebug("y: " + std::to_string((collision.GetDistanceY(hen.GiveCollisionRect(), object.GiveCollisionRect()))) + "\n");
    }*/

}

void Hen_top::Draw() {
    object.DrawBaseXY();
    sprite.DrawBaseXY(position);
    sprite.DrawCollisionScope(position.x, 600 - (position.y), sprite.GetTextureSize().x, -sprite.GetTextureSize().y);
}


void Hen_top::CheckRoom(int get_room)
{
    if (get_room == 1 && room != 2)
    {
        room++;
    }
    else if (get_room == 2 && room != 1)
    {
        room--;
    }
}