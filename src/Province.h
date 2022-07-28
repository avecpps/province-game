#pragma once

#include "Graphics.h"
#include <string>

class Province
{
public:
    Province()
    {
        xPosition = 0;
        yPosition = 0;

        size = 0;

        armyCount = 0;
    }

    Province(int newX, int newY, int newSize)
    {
        xPosition = newX * newSize;
        yPosition = newY * newSize;

        size = newSize;

        armyCount = 0.0f;
    }

    void Update(float deltaTime)
    {
        armyCount += 0.001f * deltaTime;
    }

    void SetArmyCount(float newArmyCount)
    {
        armyCount = newArmyCount;
    }

    void AddArmyCount(float newArmyCount)
    {
        armyCount += newArmyCount;
    }

    float GetArmyCount()
    {
        return armyCount;
    }

    void Draw(Graphics& graphics)
    {
        for (int y = 0; y < size; y++) 
        {
            for (int x = 0; x < size; x++) 
            {
                if (x == 2 && y == size / 2)
                {
                    graphics.DrawString(Vector2f(xPosition + x, yPosition + y), std::to_string((int)armyCount));
                }

                if (IsOnBorder(x, y))
                {
                    graphics.SetCharacter(Vector2f(xPosition + x, yPosition + y), '#');
                }
            }
        }
    }

private:
    bool IsOnBorder(int x, int y)
    {
        return x == 0 || x == size - 1 || y == 0 || y == size - 1;
    }

private:
    int xPosition;
    int yPosition;

    int size;

    float armyCount;
};
