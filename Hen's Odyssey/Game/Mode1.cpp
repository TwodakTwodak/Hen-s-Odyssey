 /*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Mode1.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#include "../Engine/Engine.h"
#include "States.h"
#include "Mode1.h"
#include "iostream"

Mode1::Mode1() : 
    hen_side({ hen.GivePosition().x, hen.GivePosition().y, floor }),
    object(), hen()
{
}

void Mode1::Load() {
    background.Load("Assets/SideBackground.png");
    hen_side.Load();
}

void Mode1::Update([[maybe_unused]] double dt) {
    hen_side.Update(dt);
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::One)) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode2));
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Two))
    {
        Engine::GetGameStateManager().ClearNextGameState();
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::R)) {
        stair.Reset();
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Up)) {
        stair.RoomChange(1);
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Down)) {
        stair.RoomChange(2);
    }

    stair.Update(dt);
}

void Mode1::Draw() {
    Engine::GetWindow().Clear(0x00F0F0FF);

    background.DrawBaseXZ({ 0, 0, 0 });
    hen_side.Draw();
}

void Mode1::Unload() { }