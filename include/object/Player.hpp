#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "object/Bullet.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Player : public GameObject
{
public:
    Player(int x, int y, int speed);

    void update(float deltaTime, bool &isRunning) override;
    void draw(SDL_Renderer *renderer) override;

    void handleInput(const Uint8 *keystate);
    const std::vector<std::shared_ptr<Bullet>> &getBullets() const;
    void removeOffScreenBullets();

private:
    SDL_Rect rect;
    int speed;
    bool slowMode = false;

    std::vector<std::shared_ptr<Bullet>> bullets;
    int shootCooldown = 0;
};

#endif
