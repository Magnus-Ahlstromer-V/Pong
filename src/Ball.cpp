#include "Ball.h"
#include "Game.h"

Ball::Ball(float x, float y, int width, int height, int r, int g, int b, int a) :
_x(x), _y(y), _width(width), _height(height), _r(r), _g(g), _b(b), _a(a)
{
    _dx = 2;
    _dy = -2;
}

void Ball::Draw()
{
    _rect.x = _x;
    _rect.y = _y;
    _rect.w = _width;
    _rect.h = _height;

    SDL_SetRenderDrawColor(Game::_renderer, _r, _g, _b, _a);
    SDL_RenderFillRect(Game::_renderer, &_rect);
}

void Ball::Update()
{
    _x += _dx;
    _y += _dy;
}

void Ball::CheckScreenCollision()
{
    // Collision with screen
    if (_y <= 0) _dy *= -1;
    if (_y >= 600 - 15) _dy *= -1;

    if (_x <= 0 || _x >= 800 - 15)
    {
        SetPos(800 / 2 - 15, 600 / 2 - 15);
        _dx *= -1;
    }
}