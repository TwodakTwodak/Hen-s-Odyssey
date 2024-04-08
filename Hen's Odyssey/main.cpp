/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  main.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#include "Engine/Engine.h"
#include "Game/Mode1.h"
#include "Game/Mode2.h"
#include "Game/Splash.h"

int main() {
    Engine& engine = Engine::Instance();
    engine.Start("Hen's Odyssaey");


    Splash splash;
    engine.GetGameStateManager().AddGameState(splash);
    Mode1 mode1; 
    engine.GetGameStateManager().AddGameState(mode1);
    Mode2 mode2;
    engine.GetGameStateManager().AddGameState(mode2);


    while (engine.HasGameEnded() == false) {
        engine.Update();
    }

    engine.Stop();

    return 0;
}
