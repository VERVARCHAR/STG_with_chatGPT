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

    sceneManager.changeScene(SceneID::TITLE);

    float deltaTime = 0.016f; // 仮に1フレーム約60FPS前提で固定

    while (isRunning)
    {
        sceneManager.update(deltaTime, isRunning);

        auto ts = std::dynamic_pointer_cast<TitleScene>(sceneManager.getCurrentScene());
        Logger::log("Entered TitleScene");
        if (ts && ts->requestStart)
        {
            sceneManager.changeScene(SceneID::GAME);
        }

        sceneManager.draw(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    shutdown(); // これで SDL_Quit() が必ず呼ばれるように
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
