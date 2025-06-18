#include "scene/TitleScene.hpp"
#include <iostream>

void TitleScene::onEnter()
{
    std::cout << "Entered TitleScene" << std::endl;
}

void TitleScene::onExit()
{
    std::cout << "Exited TitleScene" << std::endl;
}

void TitleScene::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
        {
            requestStart = true;
        }
    }
}

void TitleScene::draw()
{
    // TitleScene：背景を暗めの青
    SDL_SetRenderDrawColor(SDL_GetRenderer(SDL_GetWindowFromID(1)), 30, 30, 100, 255);
    SDL_RenderClear(SDL_GetRenderer(SDL_GetWindowFromID(1)));
}
