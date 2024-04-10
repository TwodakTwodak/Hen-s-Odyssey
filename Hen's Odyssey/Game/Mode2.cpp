 /*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Mode2.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#include "../Engine/Engine.h"
#include "States.h"
#include "Mode2.h"



Mode2::Mode2() : hen_top({ 0, 0, 0}), object() { }

void Mode2::Load() {
    hen_top.Load();
}

void Mode2::Update(double dt) {
    hen_top.Update(dt);
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Two))
    {
        Engine::GetGameStateManager().ClearNextGameState();
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::One))
    {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode1));
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::R)) {
        Engine::GetGameStateManager().ReloadGameState();
    }

    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Up)) {
        hen_top.CheckRoom(1);
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Down)) {
        hen_top.CheckRoom(2);
    }
}

void Mode2::Draw() {
    Engine::GetWindow().Clear(0x000000FF);
    hen_top.Draw();
    
}

void Mode2::Unload() { }