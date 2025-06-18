#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "object/GameObject.hpp"
#include <SDL2/SDL.h>

class Enemy : public GameObject
{
public:
    Enemy(int x, int y, int speed);

    void update(float deltaTime, bool &isRunning);
    void draw(SDL_Renderer *renderer) override;

    bool isOffScreen() const;
    SDL_Rect getRect() const;

private:
    SDL_Rect rect;
    int speed;
};

#endif
