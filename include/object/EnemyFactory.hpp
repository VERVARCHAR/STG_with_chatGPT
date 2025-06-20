#pragma once
#include <memory>
#include <string>
#include "object/Enemy.hpp"

class EnemyFactory
{
public:
    static std::shared_ptr<Enemy> create(const std::string &type, int x, int y, int hp);
};
