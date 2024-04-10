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
    background.Load("Assets/TopGroundGrass.png");
    hen_top.Load();
    stair.Load();
}

void Mode2::Update(double dt) {
    hen_top.Update(dt);
    stair.Update(dt);
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Two))
    {
        Engine::GetGameStateManager().ClearNextGameState();
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::One))
    {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode1));
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
    
}

void Mode2::Draw() {
    Engine::GetWindow().Clear(0x00F0F0FF);
    if (stair.GiveRoom() != 3)
    {
        background.DrawBaseXY({ 0, 0, 0 });
        stair.DrawBaseXY();
    }    
    hen_top.Draw();
}

void Mode2::Unload() { }