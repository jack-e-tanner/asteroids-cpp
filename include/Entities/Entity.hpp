#ifndef Header_Entity
#define Header_Entity

#include <SFML/Graphics.hpp>
#include <string>

class Entity {
 public:
  virtual ~Entity() = default;

  virtual void draw(sf::RenderWindow& window) const;
  virtual void update(sf::Time dt);
  virtual void onBounds(sf::FloatRect bounds) = 0;

  sf::Vector2f position() const { return m_sprite.getPosition(); }

 protected:
  Entity(const std::string& texturePath, sf::Vector2f pos);

  sf::Texture m_texture;
  sf::Sprite m_sprite;
  sf::Vector2f m_velocity{0.f, 0.f};
};

#endif