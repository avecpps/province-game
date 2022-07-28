#include <iostream>
#include <vector>
#include <memory>
#include <curses.h>
#include <chrono>
#include "MainLevel.h"

int main()
{ 
    Graphics graphics;

    bool shouldQuit = false;

    std::chrono::time_point<std::chrono::system_clock> timePoint1 = std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> timePoint2 = timePoint1;

    float deltaTime = 0.0f;

    std::vector<std::unique_ptr<Level>> levels;

    levels.push_back(std::make_unique<MainLevel>(MainLevel()));
    
    int currentLevel = 0;

    while (!shouldQuit)
    {
        timePoint1 = timePoint2;
        timePoint2 = std::chrono::system_clock::now();

        deltaTime = (timePoint2 - timePoint1).count() / 100000.0f;

        levels[currentLevel]->Update(deltaTime, shouldQuit);

        graphics.Clear();

        levels[currentLevel]->Draw(graphics);

        graphics.Draw();
    }
}
