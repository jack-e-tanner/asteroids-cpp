#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity {
 public:
  virtual ~Entity() = default;

  virtual void draw(sf::RenderWindow& window) const;

  sf::Vector2f position() const { return m_sprite.getPosition(); }

 protected:
  Entity(const std::string& texturePath, sf::Vector2f pos);

  sf::Texture m_texture;
  sf::Sprite m_sprite;
};