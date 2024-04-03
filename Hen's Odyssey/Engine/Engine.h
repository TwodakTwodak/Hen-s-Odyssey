 /* Copyright stuff ... */

#pragma once

#include "Logger.h"
#include "Window.h"
#include "Input.h"
#include "GameStateManager.h"
#include <chrono>
#include <time.h>
#include "Vec2.h"

class Engine {
public:
    static Engine& Instance() {
        static Engine instance;
        return instance;
    }

    static CS230::Logger& GetLogger() {
        return Instance().logger;
    }

    static CS230::Window& GetWindow() {
        return Instance().window;
    }

    static CS230::GameStateManager& GetGameStateManager() {
        return Instance().gamestatemanager;
    }

    static CS230::Input& GetInput() {
        return Instance().input;
    }



    void Start(std::string window_title);
    void Stop();
    void Update();
    bool HasGameEnded();

private:
    Engine();
    CS230::GameStateManager gamestatemanager;
    CS230::Logger logger;
    CS230::Window window;
    CS230::Input input;

    double now;


    std::chrono::system_clock::time_point last_tick;
    std::chrono::system_clock::time_point last_test;

    int frame_count = 0;

    static constexpr double TargetFPS = 30.0;
    static constexpr int FPSDuration = 5;
    static constexpr int FPSTargetFrames = static_cast<int>(FPSDuration * TargetFPS);

};
