#ifndef Bullet_Header
#define Bullet_Header

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entities/Entity.hpp"

class Bullet : public Entity {
 public:
  Bullet(const std::string& texturePath, sf::Vector2f pos,
         sf::Vector2f velocity);

  void onBounds(sf::FloatRect bounds) override;

  float radius() const override {
    return m_sprite.getGlobalBounds().width * 0.2f;
  }

  void onCollision(Entity& other) override { std::cout << "BULLET COLLISSION"; }
};

#endif