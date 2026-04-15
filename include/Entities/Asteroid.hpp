#ifndef Header_Asteroid
#define Header_Asteroid

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entities/Entity.hpp"

class Asteroid : public Entity {
 public:
  Asteroid(const std::string& texturePath, sf::Vector2f pos);

  void onBounds(sf::FloatRect bounds) override;

  float radius() const override {
    return m_sprite.getGlobalBounds().width * 0.4f;
  }

  void onCollision(Entity& other) override {
    std::cout << "ASTEROID COLLISION";
  }
};

#endif