#include "Entities/Entity.hpp"

Entity::Entity(const std::string& texturePath, sf::Vector2f pos) {
  m_texture.loadFromFile(texturePath);
  m_sprite.setTexture(m_texture);
  m_sprite.setPosition(pos);
}

void Entity::draw(sf::RenderWindow& window) const { window.draw(m_sprite); }
