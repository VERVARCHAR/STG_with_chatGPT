#include "core/Application.hpp"

#include "scene/SceneManager.hpp"
#include "scene/TitleScene.hpp"
#include "scene/GameScene.hpp"
#include "system/Logger.hpp"

#include <iostream>

Application::Application()
    : window(nullptr), renderer(nullptr), isRunning(false) {}

Application::~Application()
{
    shutdown();
}

bool Application::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL Init Failed: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("My Engine",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              800, 600,
                              SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    isRunning = true;
    return true;
}

void Application::run()
{
    SceneManager sceneManager;

    auto titleScene = std::make_shared<TitleScene>();
    auto gameScene = std::make_shared<GameScene>();

    sceneManager.registerScene(SceneID::TITLE, titleScene);
    sceneManager.registerScene(SceneID::GAME, gameScene);

    titleScene->setSceneChangeCallback(
        [&](SceneID id)
        { sceneManager.changeScene(id); });
    gameScene->setSceneChangeCallback(
        [&](SceneID id)
        { sceneManager.changeScene(id); });

    sceneManager.changeScene(SceneID::TITLE);

    Uint32 lastTime = SDL_GetTicks();
    isRunning = true;

    while (isRunning)
    {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f; // 秒単位
        lastTime = currentTime;

        sceneManager.update(deltaTime, isRunning);
        sceneManager.draw(renderer);

        SDL_Delay(1); // CPU負荷軽減（必要なら）
    }
}

void Application::shutdown()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}
