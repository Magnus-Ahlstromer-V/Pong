#include "ScoreManager.h"
#include "Game.h"

ScoreManager::ScoreManager(float x, float y, TTF_Font* font) :  _font(font)
{
    _surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
    _texture = SDL_CreateTextureFromSurface(Game::_renderer, _surface);

    int width, height;
    SDL_QueryTexture(_texture, NULL, NULL, &width, &height);

    _rect.x = (int)(x);
    _rect.y = (int)(y);
    _rect.w = width;
    _rect.h = height;
}

ScoreManager::~ScoreManager()
{
    SDL_FreeSurface(_surface);
    SDL_DestroyTexture(_texture);
}

void ScoreManager::Draw() { SDL_RenderCopy(Game::_renderer, _texture, nullptr, &_rect); }