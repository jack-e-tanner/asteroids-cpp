#include "Entities/Entity.hpp"

Entity::Entity(const std::string& texturePath, sf::Vector2f pos) {
  m_texture.loadFromFile(texturePath);
  m_sprite.setTexture(m_texture);

  sf::FloatRect bounds = m_sprite.getLocalBounds();
  m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

  m_sprite.setPosition(pos);
}

void Entity::draw(sf::RenderWindow& window) const { window.draw(m_sprite); }

void Entity::update(sf::Time dt) { m_sprite.move(m_velocity * dt.asSeconds()); }