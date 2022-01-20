#pragma once
#include <SDL2/SDL.h>

class Ball
{

public:
    Ball(float x, float y, int width, int height, int r, int g, int b, int a);

    void Draw();

    inline float GetY() const { return _y; }
    inline void SetY(float y) { _y = y; }

private:
    float _x, _y;
    int _width, _height;
    int _r, _g, _b, _a;
};