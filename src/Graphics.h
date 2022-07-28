#pragma once

#include <string>
#include <curses.h>
#include "Vector2f.h"

class Graphics
{
public:
    Graphics();

    void Clear();

    void SetCharacter(const Vector2f& position, char character);

    void DrawString(const Vector2f& position, const std::string& string);

    void DrawLine(Vector2f begin, Vector2f end, char character); 

    void Draw();

    ~Graphics();
};

