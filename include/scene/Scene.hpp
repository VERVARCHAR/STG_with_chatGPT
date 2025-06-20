#ifndef SCENE_HPP
#define SCENE_HPP

#include <SDL2/SDL.h>

#include <functional>

enum class SceneID; // ← 追加！

using SceneChangeCallback = std::function<void(SceneID)>;

class Scene
{
protected:
    SceneChangeCallback changeSceneCallback;

public:
    virtual ~Scene() = default;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void update(float deltaTime, bool &isRunning) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
    virtual void setSceneChangeCallback(SceneChangeCallback callback)
    {
        changeSceneCallback = callback;
    }
};

#endif
