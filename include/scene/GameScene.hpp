#include "object/Enemy.hpp"
#include "object/Player.hpp"
#include "scene/Scene.hpp"
#include "system/Logger.hpp"
#include "scene/EnemySpawnData.hpp"
#include "scene/EnemySpawner.hpp"
#include "object/EnemyFactory.hpp"
#include <memory>
#include <time.h>

class GameScene : public Scene
{
public:
    GameScene();
    void onEnter() override;
    void onExit() override;
    void update(float deltaTime, bool &isRunning) override;
    void draw(SDL_Renderer *renderer) override;

private:
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Enemy>> enemies; // クラスメンバとして定義
    int enemySpawnTimer;
    float elapsedTime = 0.0f;
    EnemySpawner spawner;
    int currentFrame = 0;
    std::vector<EnemySpawnData> spawnTable;
};
