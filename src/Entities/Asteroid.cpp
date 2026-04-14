#include "Entities/Asteroid.hpp"

#include <string>

Asteroid::Asteroid(const std::string& texturePath, sf::Vector2f pos)
    : Entity(texturePath, pos) {
  m_sprite.setScale(0.15f, 0.15f);
}

// Player overrides to clamp
void Asteroid::onBounds(sf::FloatRect bounds) {
  sf::Vector2f pos = m_sprite.getPosition();
  if (pos.x < bounds.left) pos.x = bounds.left;
  if (pos.y < bounds.top) pos.y = bounds.top;
  if (pos.x > bounds.left + bounds.width) pos.x = bounds.left + bounds.width;
  if (pos.y > bounds.top + bounds.height) pos.y = bounds.top + bounds.height;
  m_sprite.setPosition(pos);
}