#ifndef Header_Player
#define Header_Player

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Entities/Bullet.hpp"
#include "Entities/Entity.hpp"

class Player : public Entity {
 public:
  Player(const std::string& texturePath, sf::Vector2f pos);

  void onBounds(sf::FloatRect bounds) override;

  void update(sf::Time dt) override;

  std::vector<std::unique_ptr<Entity>> takePending() {
    return std::move(m_newBullets);
  }

  float radius() const override {
    return m_sprite.getGlobalBounds().width * 0.4f;
  }

  void onCollision(Entity& other) override { std::cout << "Player COLLISSION"; }

 private:
  void spawnBullet(sf::Vector2f pos, sf::Vector2f velocity) {
    m_newBullets.push_back(std::unique_ptr<Bullet>(
        new Bullet("assets/bullet.png", pos, velocity)));
  }
  std::vector<std::unique_ptr<Entity>> m_newBullets;
  float m_fireCooldown{0.f};
};

#endif