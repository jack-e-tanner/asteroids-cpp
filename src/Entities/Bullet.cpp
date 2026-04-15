#include "Entities/Bullet.hpp"

Bullet::Bullet(const std::string& texturePath, sf::Vector2f pos,
               sf::Vector2f velocity)
    : Entity(texturePath, pos) {
  m_sprite.setScale(0.1f, 0.1f);
  m_velocity = velocity;
}

void Bullet::onBounds(sf::FloatRect bounds) {
  if (!m_sprite.getGlobalBounds().intersects(bounds)) {
    m_alive = false;
  }
}
