#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class ScoreManager
{
public:
    ScoreManager(float x, float y, TTF_Font* font);
    ~ScoreManager();

    void Draw();
private:
    TTF_Font* _font;
    SDL_Surface* _surface;
    SDL_Texture* _texture;
    SDL_Rect _rect;

};