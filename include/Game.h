#pragma once
#include "Paddle.h"
#include "Ball.h"
#include <SDL2/SDL.h>

class Game
{
public:
    Game();

    void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    inline bool IsRunning() const { return _running; }

    static SDL_Renderer* _renderer;

private:
    bool _running = true;

    Paddle* player1;
    Paddle* player2;
    Ball* ball;

    SDL_Window* _window = nullptr;
};