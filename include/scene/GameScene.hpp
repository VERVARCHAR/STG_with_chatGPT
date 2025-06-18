#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "scene/Scene.hpp"
#include <iostream>
#include <SDL2/SDL.h>

class GameScene : public Scene
{
public:
    void onEnter() override;
    void onExit() override;
    void update() override;
    void draw() override;
};

#endif
