#include "scene/GameScene.hpp"

GameScene::GameScene()
    : enemySpawnTimer(0) // ← ここで初期化
{
    player = std::make_shared<Player>(400, 500, 5);

    spawner.addWave(1.0f, []()
                    { return std::make_shared<Enemy>(100, -30, 2); });
    spawner.addWave(3.5f, []()
                    { return std::make_shared<Enemy>(300, -50, 1); });
    spawner.addWave(5.0f, []()
                    { return std::make_shared<Enemy>(200, -20, 4); });
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
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        {
            isRunning = false;
        }
    }

    const Uint8 *keystate = SDL_GetKeyboardState(nullptr);
    player->handleInput(SDL_GetKeyboardState(nullptr));
    player->update(1.0f / 60, isRunning);
    player->removeOffScreenBullets();

    // 敵の出現タイマー更新
    enemySpawnTimer--;
    if (enemySpawnTimer <= 0)
    {
        int x = rand() % (800 - 32); // ウィンドウ幅を800と仮定
        enemies.push_back(std::make_shared<Enemy>(x, -32, 2));
        enemySpawnTimer = 60; // 1秒ごとに出現（60fps想定）
    }

    elapsedTime += deltaTime;
    spawner.update(elapsedTime, enemies);

    // 各敵の更新
    for (auto &enemy : enemies)
    {
        enemy->update(1.0f / 60, isRunning);
    }

    // 画面外に出た敵を削除
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
                       [](const std::shared_ptr<Enemy> &e)
                       { return e->isOffScreen(); }),
        enemies.end());
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
}
