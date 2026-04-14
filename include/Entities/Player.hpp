#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Entities/Entity.hpp"

class Player : public Entity {
 public:
  Player(const std::string& texturePath, sf::Vector2f pos);

  void shoot();
};