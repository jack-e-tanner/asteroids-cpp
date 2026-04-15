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
  virtual float radius() const = 0;
  virtual void onCollision(Entity& other) {}

  sf::Vector2f position() const { return m_sprite.getPosition(); }
  bool isAlive() const { return m_alive; }

 protected:
  Entity(const std::string& texturePath, sf::Vector2f pos);

  sf::Texture m_texture;
  bool m_alive{true};
  sf::Sprite m_sprite;
  sf::Vector2f m_velocity{0.f, 0.f};
};

#endif