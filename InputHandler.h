#pragma once

#include "Graphics.h"
#include <curses.h>

class InputHandler
{
public:
    InputHandler()
    {
        currentState = State::Nothing;

        x = 0;
        y = 0;

        p = 0;
        q = 0;
    }

    bool IsFinished()
    {
        return currentState == State::Finished;
    }

    void Reset()
    {
        currentState = State::Nothing;

        x = 0;
        y = 0;

        p = 0;
        q = 0;
    }

    int GetX()
    {
        return x;
    }

    int GetY()
    {
        return y;
    }

    int GetP()
    {
        return p;
    }

    int GetQ()
    {
        return q;
    }

    void Update(bool& shouldQuit)
    {
        int character = getch();

        if (character == 'm')
        {
            if (currentState == State::Nothing)
            {
                currentState = State::MovingArmy;
            }
        }

        else if (character == 'x')
        {
            if (currentState != State::Nothing)
            {
                currentState = State::ChangingX;
            }
        }

        else if (character == 'y')
        {
            if (currentState != State::Nothing)
            {
                currentState = State::ChangingY;
            }
        }

        else if (character == 'p')
        {
            if (currentState != State::Nothing)
            {
                currentState = State::ChangingP;
            }
        }

        else if (character == 'q')
        {
            if (currentState != State::Nothing)
            {
                currentState = State::ChangingQ;
            }
        }

        else if (character == 'f')
        {
            currentState = State::Finished;
        }

        else if (character >= '0' && character <= '9')
        {
            if (currentState == State::ChangingX)
            {
                x = x * 10 + character - 48;
            }

            else if (currentState == State::ChangingY)
            {
                y = y * 10 + character - 48;
            }

            else if (currentState == State::ChangingP)
            {
                p = p * 10 + character - 48;
            }

            else if (currentState == State::ChangingQ)
            {
                q = q * 10 + character - 48;
            }
        }

        else if (character == 'e')
        {
            shouldQuit = true;
        }
    }

    void Draw(Graphics& graphics)
    {
        graphics.DrawString(Vector2f(0, 0), StateToString());
    }

private:
    std::string StateToString()
    {
        if (currentState == State::Nothing)
        {
            return "";
        }

        else if (currentState == State::MovingArmy)
        {
            return "m";
        }

        else if (currentState == State::ChangingX)
        {
            return std::string("x: ") + std::to_string(x);
        }

        else if (currentState == State::ChangingY)
        {
            return std::string("y: ") + std::to_string(y);
        }

        else if (currentState == State::ChangingP)
        {
            return std::string("p: ") + std::to_string(p);
        }

        else if (currentState == State::ChangingQ)
        {
            return std::string("q: ") + std::to_string(q);
        }

        else if (currentState == State::Finished)
        {
            return "";
        }

        return "";
    }

private:
    enum class State
    {
        Nothing,
        MovingArmy,
        ChangingX,
        ChangingY,
        ChangingP,
        ChangingQ,
        Finished
    };

private:
    State currentState;

    int x;
    int y;

    int p;
    int q;

};
