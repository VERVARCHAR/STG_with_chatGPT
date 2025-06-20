#include "object/StraightEnemy.hpp"

// 親クラス Enemy のコンストラクタを呼び出す
StraightEnemy::StraightEnemy(int x_, int y_, int hp_)
    : Enemy(x_, y_, hp_) {}

void StraightEnemy::update(float deltaTime)
{
    y += static_cast<int>(100 * deltaTime); // 下に移動
}

void StraightEnemy::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = {x, y, 32, 32};
    SDL_RenderFillRect(renderer, &rect);
}
