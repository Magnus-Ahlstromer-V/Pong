#include "Game.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>

SDL_Renderer* Game::_renderer = nullptr;

Game::Game()
{
    player1 = new Paddle(15, 600 / 2 - 50, 15, 100, 0xFF, 0xFF, 0xFF, 0xFF);
    player2 = new Paddle(770, 600 / 2 - 50, 15, 100, 0xFF, 0xFF, 0xFF, 0xFF);

    ball = new Ball(800 / 2 - 15, 600 / 2 - 15, 15, 15, 0xFF, 0xFF, 0xFF, 0xFF);
}

void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
    int flags;
    fullscreen ? flags = SDL_WINDOW_FULLSCREEN : flags = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        printf("SDL2 successfully initialized!\n");

        _window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (_window == nullptr) printf("Failed to create window...\n");
        else printf("Window created successfully!\n");

        if (_renderer == nullptr) printf("Failed to create renderer...\n");
        else printf("Renderer created successfully!\n");
    }
    else { SDL_Log("Failed to initialize SDL2: %s", SDL_GetError()); }

    if (TTF_Init() != 0) std::cerr << "Failed to init TTF...\n";    

    TTF_Font* scoreFont = TTF_OpenFont("res/font.ttf", 40);
    player1ScoreText = new ScoreManager(800 / 4, 20, scoreFont);
    player2ScoreText = new ScoreManager(3 * 800 / 4, 20, scoreFont);
}

void Game::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) _running = false;
    }
}

void Game::Update()
{
    const uint8_t* keys = SDL_GetKeyboardState(NULL);

    // Make player1 move
    if (keys[SDL_SCANCODE_W]) player1->SetY(player1->GetY() - 5);
    if (keys[SDL_SCANCODE_S]) player1->SetY(player1->GetY() + 5);

    // Make player2 move
    if (keys[SDL_SCANCODE_UP]) player2->SetY(player2->GetY() - 5);
    if (keys[SDL_SCANCODE_DOWN]) player2->SetY(player2->GetY() + 5);

    ball->Update();

    player1->CheckScreenCollision();
    player2->CheckScreenCollision();

    ball->CheckScreenCollision();
    if (ball->CheckPaddleCollision(*player1) || ball->CheckPaddleCollision(*player2))
        ball->SetDx(ball->GetDx() * -1);
}

void Game::Render()
{
    SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(_renderer);

    player1->Draw();
    player2->Draw();
    player1ScoreText->Draw();
    player2ScoreText->Draw();

    ball->Draw();

    SDL_RenderPresent(_renderer);
}

void Game::Clean()
{
    printf("Game cleaned!\n");
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    TTF_Quit();
    SDL_Quit();
}