#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SDL2/SDL.h>

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void update(float deltaTime, bool &isRunning) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
};

#endif
