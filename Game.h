#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "Battle.h"
#include "Map.h"
#include "Player.h"
#include "Pokemons.h"

class Game {
 public:
  Game();
  void run();

 private:
  sf::RenderWindow window;
  sf::RenderWindow battleWindow;
  Map map;
  Player player;
  Pokemons pokemons;
  // Battle battle;

  // game events
  void handleEvents();
  bool canMove(float x, float y);
  // adding key presses to move player
  void keyPress(sf::Keyboard::Key key);
  // render
  void render();
  void checkInteraction();

  // void handleBattleEvents() {
  //   sf::Event event;
  //   while (window.pollEvent(event)) {
  //     if (event.type == sf::Event::Closed) {
  //       window.close();
  //     }
  //   }
  // }
  // void renderBattle() {
  //   battleWindow.clear();
  //   battle.draw(battleWindow);
  //   window.display();
  // }
  // void battleRun() {
  //   while (battleWindow.isOpen()) {
  //     handleBattleEvents();
  //     renderBattle();
  //   }
  // }
};

#endif