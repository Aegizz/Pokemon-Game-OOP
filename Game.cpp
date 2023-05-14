#include "Game.h"

Game::Game() {
  // Game window
  window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon Game");
}

// running the game
void Game::run() {
  while (window.isOpen()) {
    handleEvents();
    render();
  }
}
