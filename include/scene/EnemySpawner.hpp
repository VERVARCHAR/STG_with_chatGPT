#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "object/Enemy.hpp"

struct EnemyWave
{
    float spawnTime; // 出現時間
    std::function<std::shared_ptr<Enemy>()> createFunc;
    bool spawned = false;
};

class EnemySpawner
{
public:
    void addWave(float time, std::function<std::shared_ptr<Enemy>()> creator);
    void update(float time, std::vector<std::shared_ptr<Enemy>> &enemies);

private:
    std::vector<EnemyWave> waves;
};
