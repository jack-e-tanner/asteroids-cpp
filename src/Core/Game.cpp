#include "Core/Game.hpp"

Game::Game(unsigned int width, unsigned int height, const std::string& title)
    : m_window(sf::VideoMode(width, height), title),
      m_player("assets/ship.png", sf::Vector2f(200.f, 150.f)) {}

void Game::run() {
  while (m_window.isOpen()) {
    sf::Event event;
    while (m_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        m_window.close();
      }
    }

    render();
  }
}

void Game::render() {
  m_window.clear();
  m_player.draw(m_window);
  m_window.display();
}