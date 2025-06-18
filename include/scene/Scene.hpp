#ifndef SCENE_HPP
#define SCENE_HPP

#include <SDL2/SDL.h>

class Scene
{
public:
    virtual ~Scene() = default;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void update(float deltaTime, bool &isRunning) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
};

#endif
