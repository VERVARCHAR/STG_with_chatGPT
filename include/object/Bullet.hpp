#ifndef BULLET_HPP
#define BULLET_HPP

#include "object/GameObject.hpp"
#include <SDL2/SDL.h>

class Bullet : public GameObject
{
public:
    Bullet(int x, int y, int speed);

    void update(float deltaTime, bool &isRunning);
    void draw(SDL_Renderer *renderer) override;

    bool isOffScreen() const;
    SDL_Rect getRect() const; // ★ これを忘れていた

private:
    SDL_Rect rect;
    int speed;
};

#endif
