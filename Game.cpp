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

void Game::handleEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    } else if (event.type == sf::Event::KeyPressed) {  // moving player
      keyPress(event.key.code);
    }
  }
}

bool Game::canMove(float x, float y) {
  int i = static_cast<int>(x) / tileSize;
  int j = static_cast<int>(y) / tileSize;

  // Check if the coordinates are within the map bounds
  if (i < 0 || i >= mapWidth || j < 0 || j >= mapHeight) return false;

  return true;
}

// adding key presses to move player
void Game::keyPress(sf::Keyboard::Key key) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
      canMove(player.getX(), player.getY() - tileSize)) {
    player.animationVertical(354);
    player.move(0, -0.1);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
      canMove(player.getX(), player.getY() + tileSize)) {
    player.animationVertical(0);
    player.move(0, 0.1);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
      canMove(player.getX() - tileSize, player.getY())) {
    player.animationHorizontal(118);
    player.move(-0.1, 0);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
      canMove(player.getX() + tileSize, player.getY())) {
    player.animationHorizontal(236);
    player.move(0.1, 0);
  }
}

// render
void Game::render() {
  window.clear();
  map.draw(window);
  pokemons.draw(window);
  player.draw(window);
  window.display();
}