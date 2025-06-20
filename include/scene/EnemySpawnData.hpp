#pragma once
#include <string>

struct EnemySpawnData
{
    int time;
    int x;
    int y;
    std::string type;
    int hp;

    EnemySpawnData(int t, int x_, int y_, const std::string &type_, int hp_)
        : time(t), x(x_), y(y_), type(type_), hp(hp_) {}
};
