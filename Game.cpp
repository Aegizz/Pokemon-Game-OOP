#include "Game.h"

Game::Game() {
  // Game window
  window.create(sf::VideoMode(windowWidth, windowHeight), "Pokemon Game");
}

// running the game
void Game::run() {
  while (window.isOpen()) {
    handleEvents();
    render();
  }
}
