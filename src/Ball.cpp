#include "Ball.h"
#include "Game.h"

Ball::Ball(float x, float y, int width, int height, int r, int g, int b, int a) :
_x(x), _y(y), _width(width), _height(height), _r(r), _g(g), _b(b), _a(a)
{
    _dx = 2;
    _dy = 2;
}

void Ball::Draw()
{
    SDL_Rect rect;
    rect.x = _x;
    rect.y = _y;
    rect.w = _width;
    rect.h = _height;

    SDL_SetRenderDrawColor(Game::_renderer, _r, _g, _b, _a);
    SDL_RenderFillRect(Game::_renderer, &rect);
}

void Ball::Update()
{
    _x += _dx;
    _y -= _dy;
}