#pragma once
#include <vector>
#include <string>
#include "scene/EnemySpawnData.hpp"

class StageLoader
{
public:
    static std::vector<EnemySpawnData> loadFromJson(const std::string &filepath);
};
