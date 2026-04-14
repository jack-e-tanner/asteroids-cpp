#include "Core/Game.hpp"

#include "Entities/Asteroid.hpp"
#include "Entities/Entity.hpp"
#include "Entities/Player.hpp"

Game::Game(unsigned int width, unsigned int height, const std::string& title)
    : m_window(sf::VideoMode(width, height), title) {
  addEntity<Player>("assets/ship.png", sf::Vector2f(200.f, 150.f));
  addEntity<Asteroid>("assets/asteroid.png", sf::Vector2f(400.f, 150.f));
}

void Game::run() {
  while (m_window.isOpen()) {
    sf::Time dt = m_clock.restart();

    sf::Event event;
    while (m_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        m_window.close();
      }
    }

    update(dt);
    render();
  }
}

void Game::render() {
  m_window.clear();
  for (const auto& entity : m_entities) {
    entity->draw(m_window);
  }
  m_window.display();
}

void Game::update(sf::Time dt) {
  sf::Vector2u size = m_window.getSize();
  sf::FloatRect bounds(0.f, 0.f, static_cast<float>(size.x),
                       static_cast<float>(size.y));

  for (auto& entity : m_entities) {
    entity->update(dt);
    entity->onBounds(bounds);
  }
}
