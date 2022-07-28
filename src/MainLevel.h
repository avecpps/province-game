#pragma once

#include <map>
#include <vector>
#include "InputHandler.h"
#include "Level.h"
#include "Province.h"
#include "Polyline.h"

class MainLevel : public Level
{
public:
    MainLevel()
        :
        polyline({
                {Vector2f(30.0f, 0.0f)},
                {Vector2f(40.0f, 4.0f)},
                {Vector2f(40.0f, 13.0f)},
                {Vector2f(30.0f, 13.0f)}})
    {
        provinces.insert({{0, 0}, Province(0, 0, size)});
        provinces.insert({{1, 0}, Province(1, 0, size)});
        provinces.insert({{0, 1}, Province(0, 1, size)});
        provinces.insert({{1, 1}, Province(1, 1, size)});
    }

    virtual void Update(float deltaTime, bool& shouldQuit) override
    {
        inputHandler.Update(shouldQuit);

        if (inputHandler.IsFinished())
        {
            float newArmy = provinces[std::pair<int, int>(inputHandler.GetX(), inputHandler.GetY())].GetArmyCount();

            provinces[std::pair<int, int>(inputHandler.GetP(), inputHandler.GetQ())].AddArmyCount(newArmy);

            provinces[std::pair<int, int>(inputHandler.GetX(), inputHandler.GetY())].SetArmyCount(0.0f);

            inputHandler.Reset();
        }

        for (auto& province : provinces) 
        {
            province.second.Update(deltaTime);
        }
    }

    virtual void Draw(Graphics& graphics) override
    {
        for (auto& province : provinces) 
        {
            province.second.Draw(graphics);
        }
        
        inputHandler.Draw(graphics);

        polyline.Draw(graphics);
    }

private:
    InputHandler inputHandler;

    std::map<std::pair<int, int>, Province> provinces;

    const int size = 10;

    Polyline polyline;
};
