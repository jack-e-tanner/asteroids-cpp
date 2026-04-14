#ifndef Header_Game
#define Header_Game

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>

#include "Entities/Entity.hpp"

class Game {
 public:
  Game(unsigned int width = 500, unsigned int height = 500,
       const std::string& title = "Asteroids!");

  void run();

  template <typename T, typename... Args>
  void addEntity(Args&&... args) {
    m_entities.push_back(
        std::unique_ptr<T>(new T(std::forward<Args>(args)...)));
  }

 private:
  void render();
  void update(sf::Time dt);

  sf::RenderWindow m_window;
  std::vector<std::unique_ptr<Entity>> m_entities;
  sf::Clock m_clock;
};

#endif