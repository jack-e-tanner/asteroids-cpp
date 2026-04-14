#include "Entities/Player.hpp"

Player::Player(const std::string& texturePath, sf::Vector2f pos)
    : Entity(texturePath, pos) {
  m_sprite.setScale(0.1f, 0.1f);
}

void Player::shoot() {}