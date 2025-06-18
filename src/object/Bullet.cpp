#include "object/Bullet.hpp"

Bullet::Bullet(int x, int y, int speed)
    : speed(speed)
{
    rect.x = x;
    rect.y = y;
    rect.w = 8;
    rect.h = 16;
}

void Bullet::update(float deltaTime, bool &isRunning)
{
    rect.y -= speed;
}

void Bullet::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // 黄色
    SDL_RenderFillRect(renderer, &rect);
}

bool Bullet::isOffScreen() const
{
    return rect.y + rect.h < 0;
}

SDL_Rect Bullet::getRect() const
{
    return rect;
}
