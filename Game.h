#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "Map.h"
#include "Player.h"
#include "Pokemons.h"

class Game {
 public:
  Game();
  void run();

 private:
  sf::RenderWindow window;
  Map map;
  Player player;
  Pokemons pokemons;

  // game events
  void handleEvents();
  bool canMove(float x, float y);
  // adding key presses to move player
  void keyPress(sf::Keyboard::Key key);
  // render
  void render();
  void checkInteraction();
};

#endif