#pragma once
#include "object/Enemy.hpp"
#include <cmath>

class SpiralEnemy : public Enemy
{
public:
    SpiralEnemy(int x, int y, int hp);
    void update(float deltaTime) override;
    void draw(SDL_Renderer *renderer) override;

private:
    float angle;
};
