#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "scene/Scene.hpp"
#include <SDL2/SDL.h>

class TitleScene : public Scene
{
public:
    void onEnter() override;
    void onExit() override;
    void update(float deltaTime, bool &isRunning) override;
    void draw(SDL_Renderer *renderer) override;

    bool requestStart = false; // Enterで開始判定
};

#endif
