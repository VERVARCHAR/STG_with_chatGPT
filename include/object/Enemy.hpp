#pragma once
#include <SDL2/SDL.h>

class Enemy
{
public:
    int x, y, hp;

    Enemy(int x, int y, int hp) : x(x), y(y), hp(hp) {}
    virtual ~Enemy() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;

    virtual bool isOffScreen() const;
    virtual SDL_Rect getRect() const;
};
