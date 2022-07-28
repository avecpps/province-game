#include "Graphics.h"
#include <curses.h>

Graphics::Graphics()
{
    initscr();

    cbreak();
    noecho();

    nodelay(stdscr, true);

    curs_set(0);
}

void Graphics::Clear()
{
    erase();
}

void Graphics::SetCharacter(const Vector2f &position, char character)
{
    mvaddch((int)position.y, (int)position.x, (chtype)character);
}

void Graphics::DrawString(const Vector2f &position, const std::string &string)
{
    mvaddstr((int)position.y, (int)position.x, string.c_str());
}

void Graphics::DrawLine(Vector2f begin, Vector2f end, char character)
{
    if (begin.x != end.x)
    {
        float slope = (end.y - begin.y) / (end.x - begin.x);

        float intercept = begin.y - slope * begin.x;

        if (slope <= 1.0f)
        {
            if (begin.x > end.x)
            {
                Vector2f temp = begin;

                begin = end;

                end = temp;
            }

            for (int x = begin.x; x <= end.x; x++) 
            {
                float y = slope * (float)x + intercept;

                SetCharacter(Vector2f((float)x, y), character);
            }
        }

        else
        {
            float inverseSlope = 1.0f / slope;

            float newIntercept = begin.x - inverseSlope * begin.y; 

            if (begin.y > end.y)
            {
                Vector2f temp = begin;

                begin = end;

                end = temp;
            }

            for (int y = begin.y; y <= end.y; y++) 
            {
                float x = inverseSlope * (float)y + newIntercept;

                SetCharacter(Vector2f(x, (float)y), character);
           }
        }
    }

    else
    {
        if (begin.y > end.y)
        {
            Vector2f temp = begin;
            begin = end;

            end = temp;
        }

        for (int y = begin.y; y <= end.y; y++) 
        {
            SetCharacter(Vector2f(begin.x, (float)y), character);
        }
    }
}

void Graphics::Draw()
{
    refresh();
}

Graphics::~Graphics()
{
    endwin();
}
