#ifndef Header_Player
#define Header_Player

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entities/Entity.hpp"

class Player : public Entity {
 public:
  Player(const std::string& texturePath, sf::Vector2f pos);

  void onBounds(sf::FloatRect bounds) override;

  void update(sf::Time dt) override;

  float radius() const override {
    return m_sprite.getGlobalBounds().width * 0.4f;
  }

  void onCollision(Entity& other) override { std::cout << "Player COLLISSION"; }

 private:
  std::vector<std::unique_ptr<Entity>> m_entities;
};

#endif