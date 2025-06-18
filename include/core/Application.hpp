#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SDL2/SDL.h>

class Application
{
public:
    Application();
    ~Application();

    bool init();     // SDL初期化・ウィンドウ生成
    void run();      // メインループ
    void shutdown(); // 終了処理

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool isRunning;
};

#endif // APPLICATION_HPP
