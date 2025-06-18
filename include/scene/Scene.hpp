#ifndef SCENE_HPP
#define SCENE_HPP

class Scene
{
public:
    virtual ~Scene() = default;
    virtual void onEnter() = 0; // シーンに入ったとき
    virtual void onExit() = 0;  // シーンを離れるとき
    virtual void update() = 0;  // 毎フレーム更新処理
    virtual void draw() = 0;    // 毎フレーム描画処理
};

#endif
