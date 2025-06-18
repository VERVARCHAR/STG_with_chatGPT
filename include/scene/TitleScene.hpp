#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "scene/Scene.hpp"
#include <SDL2/SDL.h>

class TitleScene : public Scene
{
public:
    void onEnter() override;
    void onExit() override;
    void update() override;
    void draw() override;

    bool requestStart = false; // Enterで開始判定
};

#endif
