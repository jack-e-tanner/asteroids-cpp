#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "Entities/Player.hpp"

class Game {
 public:
  Game(unsigned int width = 500, unsigned int height = 500,
       const std::string& title = "Asteroids!");

  void run();

 private:
  void render();

  sf::RenderWindow m_window;
  Player m_player;
};