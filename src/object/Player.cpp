#include "object/Player.hpp"

Player::Player(int x, int y, int speed)
    : speed(speed)
{
    rect.x = x;
    rect.y = y;
    rect.w = 32;
    rect.h = 32;
}

void Player::update(float deltaTime, bool &isRunning)
{
    for (auto &bullet : bullets)
    {
        bullet->update(deltaTime, isRunning);
    }

    // クールダウン
    if (shootCooldown > 0)
        shootCooldown--;
}

void Player::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // 白
    SDL_RenderFillRect(renderer, &rect);

    for (auto &bullet : bullets)
    {
        bullet->draw(renderer);
    }
}

void Player::handleInput(const Uint8 *keystate)
{
    int actualSpeed = slowMode ? speed / 2 : speed;
    if (keystate[SDL_SCANCODE_LSHIFT])
        slowMode = true;
    else
        slowMode = false;

    if (keystate[SDL_SCANCODE_UP])
        rect.y -= actualSpeed;
    if (keystate[SDL_SCANCODE_DOWN])
        rect.y += actualSpeed;
    if (keystate[SDL_SCANCODE_LEFT])
        rect.x -= actualSpeed;
    if (keystate[SDL_SCANCODE_RIGHT])
        rect.x += actualSpeed;

    // Zキー発射（クールダウンで制限）
    if (keystate[SDL_SCANCODE_Z] && shootCooldown == 0)
    {
        bullets.push_back(std::make_shared<Bullet>(rect.x + rect.w / 2 - 3, rect.y, 10));
        shootCooldown = 10; // クールダウン
    }
}

const std::vector<std::shared_ptr<Bullet>> &Player::getBullets() const
{
    return bullets;
}

void Player::removeOffScreenBullets()
{
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                                 [](const std::shared_ptr<Bullet> &b)
                                 {
                                     return b->isOffScreen();
                                 }),
                  bullets.end());
}