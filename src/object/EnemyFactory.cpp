#include "object/EnemyFactory.hpp"
#include "object/StraightEnemy.hpp"
#include "object/SpiralEnemy.hpp"

std::shared_ptr<Enemy> EnemyFactory::create(const std::string &type, int x, int y, int hp)
{
    if (type == "straight")
    {
        return std::make_shared<StraightEnemy>(x, y, hp);
    }
    else if (type == "spiral")
    {
        return std::make_shared<SpiralEnemy>(x, y, hp);
    }
    // デフォルト
    return std::make_shared<StraightEnemy>(x, y, hp);
}
