#ifndef Header_Player
#define Header_Player

#include <SFML/Graphics.hpp>
#include <string>

#include "Entities/Entity.hpp"

class Player : public Entity {
 public:
  Player(const std::string& texturePath, sf::Vector2f pos);

  void onBounds(sf::FloatRect bounds) override;

  void update(sf::Time dt) override;

  void shoot();
};

#endif