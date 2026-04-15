#include "Core/Game.hpp"

#include "Entities/Asteroid.hpp"
#include "Entities/Entity.hpp"
#include "Entities/Player.hpp"

Game::Game(unsigned int width, unsigned int height, const std::string& title)
    : m_window(sf::VideoMode(width, height), title) {
  auto player = std::unique_ptr<Player>(
      new Player("assets/ship.png", sf::Vector2f(200.f, 150.f)));
  m_player = player.get();
  m_entities.push_back(std::move(player));

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

void Game::checkCollisions() {
  for (size_t i = 0; i < m_entities.size(); i++) {
    for (size_t j = i + 1; j < m_entities.size(); j++) {
      Entity& a = *m_entities[i];
      Entity& b = *m_entities[j];

      sf::Vector2f d = a.position() - b.position();
      float r = a.radius() + b.radius();

      if (d.x * d.x + d.y * d.y < r * r) {
        a.onCollision(b);
        b.onCollision(a);
      }
    }
  }
}

void Game::update(sf::Time dt) {
  sf::Vector2u size = m_window.getSize();
  sf::FloatRect bounds(0.f, 0.f, static_cast<float>(size.x),
                       static_cast<float>(size.y));

  for (auto& entity : m_entities) {
    entity->update(dt);
    entity->onBounds(bounds);
  }

  addEntities(m_player->takePending());

  checkCollisions();
  removeDead();
}

void Game::removeDead() {
  m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(),
                                  [](const std::unique_ptr<Entity>& entity) {
                                    return !entity->isAlive();
                                  }),
                   m_entities.end());
}