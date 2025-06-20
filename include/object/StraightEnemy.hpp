#pragma once
#include "object/Enemy.hpp"

class StraightEnemy : public Enemy
{
public:
    StraightEnemy(int x, int y, int hp);
    void update(float deltaTime) override;
    void draw(SDL_Renderer *renderer) override;
};
