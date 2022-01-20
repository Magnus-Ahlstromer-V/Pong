#include "Paddle.h"
#include "Game.h"

Paddle::Paddle(float x, float y, int width, int height, int r, int g, int b, int a) :
_x(x), _y(y), _width(width), _height(height), _r(r), _g(g), _b(b), _a(a)
{}

void Paddle::Draw()
{
    SDL_Rect rect;
    rect.x = _x;
    rect.y = _y;
    rect.w = _width;
    rect.h = _height;

    SDL_SetRenderDrawColor(Game::_renderer, _r, _g, _b, _a);
    SDL_RenderFillRect(Game::_renderer, &rect);
}

void Paddle::CheckScreenCollision()
{
    if (_y <= 0) _y = 0;
    if (_y >= 600 - 100) _y = 600 - 100;
}