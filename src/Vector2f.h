#pragma once

class Vector2f
{
public:
    Vector2f(float newX, float newY)
    {
        x = newX;
        y = newY;
    }

    Vector2f& operator=(const Vector2f& argument)
    {
        x = argument.x;
        y = argument.y;

        return *this;
    }

    Vector2f operator*(const Vector2f& argument)
    {
        return Vector2f(x * argument.x, y * argument.y);
    }
    
    Vector2f operator/(const Vector2f& argument)
    {
        return Vector2f(x / argument.x, y / argument.y);
    }

    Vector2f operator+(const Vector2f& argument)
    {
        return Vector2f(x + argument.x, y + argument.y);
    }

    Vector2f operator-(const Vector2f& argument)
    {
        return Vector2f(x - argument.x, y - argument.y);
    }

    Vector2f operator*(const float argument)
    {
        return Vector2f(x * argument, y * argument);
    }

    Vector2f& operator*=(const Vector2f& argument)
    {
        x *= argument.x;
        y *= argument.y;

        return *this;
    }

    Vector2f& operator/=(const Vector2f& argument)
    {
        x /= argument.x;
        y /= argument.y;

        return *this;
    }
    Vector2f& operator+=(const Vector2f& argument)
    {
        x += argument.x;
        y += argument.y;

        return *this;
    }
    Vector2f& operator-=(const Vector2f& argument)
    {
        x -= argument.x;
        y -= argument.y;

        return *this;
    }
    
public: 
    float x;
    float y;
};
