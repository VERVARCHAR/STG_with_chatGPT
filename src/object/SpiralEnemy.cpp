#include "object/SpiralEnemy.hpp"
#include <SDL2/SDL.h>
#include <cmath>

SpiralEnemy::SpiralEnemy(int x_, int y_, int hp_)
    : Enemy(x_, y_, hp_), angle(0.0f) {}

void SpiralEnemy::update(float deltaTime)
{
    angle += 3.0f * deltaTime; // 回転速度
    x += static_cast<int>(5.0f * std::cos(angle));
    y += static_cast<int>(5.0f * std::sin(angle));
}

void SpiralEnemy::draw(SDL_Renderer *renderer)
{
    SDL_Rect rect = {x - 10, y - 10, 20, 20};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 赤い敵
    SDL_RenderFillRect(renderer, &rect);
}
