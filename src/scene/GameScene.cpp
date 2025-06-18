#include "scene/GameScene.hpp"

void GameScene::onEnter()
{
    std::cout << "Entered GameScene" << std::endl;
}

void GameScene::onExit()
{
    std::cout << "Exited GameScene" << std::endl;
}

void GameScene::update()
{
    // ゲーム中の更新処理（今回は空）
}

void GameScene::draw()
{
    // GameScene：背景を明るめの赤
    SDL_SetRenderDrawColor(SDL_GetRenderer(SDL_GetWindowFromID(1)), 100, 30, 30, 255);
    SDL_RenderClear(SDL_GetRenderer(SDL_GetWindowFromID(1)));
}
