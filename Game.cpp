#include "Game.h"

Game::Game() {
  // Game window
  window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight),
                                "Pokemon Game");
  battleWindow = nullptr;  // Initialize to nullptr as it will be allocated
                           // dynamically when needed
  map = new Map();
  player = new PlayerGraphics();
  pokemons = new Pokemons();
  // battle = nullptr;  // Commented out as it's not used
}

Game::~Game() {
  delete window;        // Free dynamically allocated window
  delete battleWindow;  // Free dynamically allocated battleWindow if it's
                        // allocated
  delete map;           // Free dynamically allocated map
  delete player;        // Free dynamically allocated player
  delete pokemons;      // Free dynamically allocated pokemons
  // delete battle;  // Commented out as it's not used
}

void Game::run() {
  while (window->isOpen()) {
    handleEvents();
    render();
  }
}

void Game::handleEvents() {
  sf::Event event;
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window->close();
    } else if (event.type == sf::Event::KeyPressed) {
      keyPress(event.key.code);
    }
  }
}

bool Game::canMove(float x, float y) {
  int i = static_cast<int>(x) / tileSize;
  int j = static_cast<int>(y) / tileSize;

  if (i < 0 || i >= mapWidth || j < 0 || j >= mapHeight) return false;

  return true;
}

void Game::keyPress(sf::Keyboard::Key key) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
      canMove(player->getX(), player->getY() - tileSize)) {
    player->animationVertical(354);
    player->move(0, -0.1);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
      canMove(player->getX(), player->getY() + tileSize)) {
    player->animationVertical(0);
    player->move(0, 0.1);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
      canMove(player->getX() - tileSize, player->getY())) {
    player->animationHorizontal(118);
    player->move(-0.1, 0);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
      canMove(player->getX() + tileSize, player->getY())) {
    player->animationHorizontal(236);
    player->move(0.1, 0);
  }
}

void Game::render() {
  checkInteraction();
  window->clear();
  map->draw(*window);
  pokemons->draw(*window);
  player->draw(*window);
  window->display();
}

void Game::checkInteraction() {
  sf::Sprite playerSprite = player->getPlayerSprite();

  sf::Sprite pokemonSprite1 = pokemons->getSprite1();
  if (playerSprite.getGlobalBounds().intersects(
          pokemonSprite1.getGlobalBounds())) {
    BattleSFML battle1(pokemonSprite1);
  }

  sf::Sprite pokemonSprite2 = pokemons->getSprite2();
  if (playerSprite.getGlobalBounds().intersects(
          pokemonSprite2.getGlobalBounds())) {
    BattleSFML battle2(pokemonSprite2);
  }

  sf::Sprite pokemonSprite3 = pokemons->getSprite3();
  if (playerSprite.getGlobalBounds().intersects(
          pokemonSprite3.getGlobalBounds())) {
    BattleSFML battle3(pokemonSprite3);
  }
}