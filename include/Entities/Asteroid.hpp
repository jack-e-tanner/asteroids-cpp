#ifndef Header_Asteroid
#define Header_Asteroid

#include <SFML/Graphics.hpp>
#include <string>

#include "Entities/Entity.hpp"

class Asteroid : public Entity {
 public:
  Asteroid(const std::string& texturePath, sf::Vector2f pos);

  void onBounds(sf::FloatRect bounds) override;
};

#endif