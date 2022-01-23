#include "Ball.h"
#include "Game.h"

Ball::Ball(float x, float y, int width, int height, int r, int g, int b, int a) :
_x(x), _y(y), _width(width), _height(height), _r(r), _g(g), _b(b), _a(a)
{
    _dx = 4;
    _dy = -4;
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

bool Ball::CheckPaddleCollision(Paddle& paddle)
{
    float ballLeft = _x;
    float ballRight = _x + 15; // x + ball_width
    float ballTop = _y;
    float ballBottom = _y + 15; // y + ball_height 

    float paddleLeft = paddle.GetX();
    float paddleRight = paddle.GetX() + 15; // paddle_x + paddle_width
    float paddleTop = paddle.GetY();
    float paddleBottom = paddle.GetY() + 100; // paddle_y + paddle_height

    // If any of these cases return false
    if (ballLeft >= paddleRight) return false;
    if (ballRight <= paddleLeft) return false;
    if (ballTop >= paddleBottom) return false;
    if (ballBottom <= paddleTop) return false;

    return true;
}