#pragma once
#include <SDL2/SDL.h>

class Ball
{

public:
    Ball(float x, float y, int width, int height, int r, int g, int b, int a);

    void Draw();
    void Update();
    void CheckScreenCollision();

    inline float GetX() const { return _x; }
    inline float GetY() const { return _y; }
    inline int GetDx() const { return _dx; }
    inline int GetDy() const { return _dy; }

    inline void SetPos(float x, float y) 
    {
        _x = x;
        _y = y; 
    }
    inline void SetDx(float dx) { _dx = dx; }
    inline void SetDy(float dy) { _dy = dy; }

private:
    float _x, _y;
    int _width, _height;
    int _dx, _dy;
    int _r, _g, _b, _a;
};