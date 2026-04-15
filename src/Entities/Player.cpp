#include "Entities/Player.hpp"

#include <cmath>

Player::Player(const std::string& texturePath, sf::Vector2f pos)
    : Entity(texturePath, pos) {
  m_sprite.setScale(0.1f, 0.1f);
}

namespace {  // local-file
void normalize(sf::Vector2f& v, float targetLength) {
  float lengthSq = v.x * v.x + v.y * v.y;
  if (lengthSq == 0.f) return;
  float length = std::sqrt(lengthSq);
  v *= (targetLength / length);
}
}  // namespace

void Player::update(sf::Time dt) {
  const float speed = 200.f;
  m_velocity = {0.f, 0.f};

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) m_velocity.y -= speed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) m_velocity.y += speed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) m_velocity.x -= speed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) m_velocity.x += speed;

  if (m_velocity.x != 0.f || m_velocity.y != 0.f) {
    float angleRad = std::atan2(m_velocity.y, m_velocity.x);
    float angleDeg = angleRad * 180.f / 3.14159265f;
    m_sprite.setRotation(angleDeg + 90.f);
  }

  normalize(m_velocity, speed);
  Entity::update(dt);
}

void Player::onBounds(sf::FloatRect bounds) {
  sf::FloatRect local = m_sprite.getLocalBounds();
  sf::Vector2f scale = m_sprite.getScale();
  float halfW = (local.width * scale.x) / 2.f;
  float halfH = (local.height * scale.y) / 2.f;

  sf::Vector2f pos = m_sprite.getPosition();
  if (pos.x < bounds.left + halfW) pos.x = bounds.left + halfW;
  if (pos.y < bounds.top + halfH) pos.y = bounds.top + halfH;
  if (pos.x > bounds.left + bounds.width - halfW) {
    pos.x = bounds.left + bounds.width - halfW;
  }
  if (pos.y > bounds.top + bounds.height - halfH) {
    pos.y = bounds.top + bounds.height - halfH;
  }
  m_sprite.setPosition(pos);
}