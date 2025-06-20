#include "object/Enemy.hpp"

bool Enemy::isOffScreen() const
{
    return y > 600; // 画面外（画面高さは仮に600px）
}

SDL_Rect Enemy::getRect() const
{
    // デフォルト敵の当たり判定の矩形（仮に16x16）
    SDL_Rect rect = {x - 8, y - 8, 16, 16};
    return rect;
}
