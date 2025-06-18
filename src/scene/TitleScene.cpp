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

void TitleScene::update(float deltaTime, bool &isRunning)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            if (event.key.keysym.sym == SDLK_RETURN)
            {
                requestStart = true;
            }
        }
    }
}

void TitleScene::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 30, 30, 100, 255);
    SDL_RenderClear(renderer);
}