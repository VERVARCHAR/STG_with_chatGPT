#include "scene/EnemySpawner.hpp"

void EnemySpawner::addWave(float time, std::function<std::shared_ptr<Enemy>()> creator)
{
    waves.push_back({time, creator, false});
}

void EnemySpawner::update(float time, std::vector<std::shared_ptr<Enemy>> &enemies)
{
    for (auto &wave : waves)
    {
        if (!wave.spawned && time >= wave.spawnTime)
        {
            enemies.push_back(wave.createFunc());
            wave.spawned = true;
        }
    }
}
