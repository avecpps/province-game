#pragma once

#include <vector>
#include "Graphics.h"
#include "Vector2f.h"

class Polyline
{
public:
    Polyline()
    {

    }

    Polyline(const std::vector<Vector2f>& newVertices)
    {
        vertices = newVertices;
    }

    void SetVertices(const std::vector<Vector2f>& newVertices)
    {
        vertices = newVertices;
    }

    void Draw(Graphics& graphics)
    {
        for (int i = 0; i < vertices.size() - 1; i++) 
        {
            graphics.DrawLine(vertices[i], vertices[i + 1], '#');
        }

        graphics.DrawLine(vertices[vertices.size() - 1], vertices[0], '#');
    }
private:
    std::vector<Vector2f> vertices;
};
