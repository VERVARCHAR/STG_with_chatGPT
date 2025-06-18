#include "object/Enemy.hpp"

Enemy::Enemy(int x, int y, int speed)
    : speed(speed)
{
    rect.x = x;
    rect.y = y;
    rect.w = 32;
    rect.h = 32;
}

void Enemy::update(float deltaTime, bool &isRunning)
{
    rect.y += speed;
}

void Enemy::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

bool Enemy::isOffScreen() const
{
    return rect.y > 600;
}

SDL_Rect Enemy::getRect() const
{
    return rect;
}
