#include "scene/SceneManager.hpp"

void SceneManager::registerScene(SceneID id, std::shared_ptr<Scene> scene)
{
    scenes[id] = scene;
}

void SceneManager::changeScene(SceneID id)
{
    if (currentScene)
        currentScene->onExit();
    currentScene = scenes[id];
    currentID = id;
    if (currentScene)
        currentScene->onEnter();
}

void SceneManager::update(float deltaTime, bool &isRunning)
{
    if (currentScene)
        currentScene->update(deltaTime, isRunning);
}

void SceneManager::draw(SDL_Renderer *renderer)
{
    if (currentScene)
        currentScene->draw(renderer);
}

std::shared_ptr<Scene> SceneManager::getCurrentScene() const
{
    return currentScene;
}

SceneID SceneManager::getCurrentID() const
{
    return currentID;
}
