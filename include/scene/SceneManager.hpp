#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <memory>
#include <unordered_map>
#include "scene/Scene.hpp"

enum class SceneID
{
    TITLE,
    GAME,
    GAME_OVER,
    // 他のシーンも順次追加
};

class SceneManager
{
public:
    void changeScene(SceneID id); // シーン切り替え
    void update();                // 現在シーンの更新
    void draw();                  // 現在シーンの描画

    void registerScene(SceneID id, std::shared_ptr<Scene> scene);
    std::shared_ptr<Scene> getCurrentScene() const;

private:
    std::shared_ptr<Scene> currentScene = nullptr;
    std::unordered_map<SceneID, std::shared_ptr<Scene>> scenes;
    SceneID currentID;
};

#endif
