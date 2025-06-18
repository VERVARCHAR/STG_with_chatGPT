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

void SceneManager::update()
{
    if (currentScene)
        currentScene->update();
}

void SceneManager::draw()
{
    if (currentScene)
        currentScene->draw();
}

std::shared_ptr<Scene> SceneManager::getCurrentScene() const
{
    return currentScene;
}
