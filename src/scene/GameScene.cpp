#include "scene/GameScene.hpp"
#include "object/EnemyFactory.hpp"

#include "object/StraightEnemy.hpp" // 追加

GameScene::GameScene()
    : enemySpawnTimer(0)
{
    player = std::make_shared<Player>(400, 500, 5);

    spawner.addWave(1.0f, []()
                    { return std::make_shared<StraightEnemy>(100, -30, 2); });

    spawner.addWave(3.5f, []()
                    { return std::make_shared<StraightEnemy>(300, -50, 1); });

    spawner.addWave(5.0f, []()
                    { return std::make_shared<StraightEnemy>(200, -20, 4); });
}

void GameScene::onEnter()
{
    Logger::log("Entered GameScene");
}

void GameScene::onExit()
{
    Logger::log("Exited GameScene");
}

void GameScene::update(float deltaTime, bool &isRunning)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
        }
    }

    currentFrame++;

    for (auto it = spawnTable.begin(); it != spawnTable.end();)
    {
        if (it->time <= currentFrame)
        {
            const auto &spawnData = *it;
            auto enemy = EnemyFactory::create(spawnData.type, spawnData.x, spawnData.y, spawnData.hp);
            enemies.push_back(enemy);
            it = spawnTable.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (auto &enemy : enemies)
    {
        enemy->update(deltaTime);
    }

    player->update(deltaTime, isRunning); // プレイヤーの処理も忘れずに
}

void GameScene::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    player->draw(renderer);

    for (auto &enemy : enemies)
    {
        enemy->draw(renderer);
    }

    SDL_RenderPresent(renderer); // これが無いと描画結果が画面に出ません！
}
