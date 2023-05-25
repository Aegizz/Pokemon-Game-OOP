#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "BattleSFML.h"
#include "Map.h"
#include "PlayerGraphics.h"
#include "Pokemons.h"
#include "player.h"



#include <string>
#include "pokemon.h"  // Include pokemon.h before attack.h
#include "attack.h"
#include "assignedAttack.h"
#include "player.h"



extern std::vector<std::vector<std::string>> pokemonDatabase();

class Game {
 public:
  Game();
  ~Game();  // Destructor to free dynamically allocated memory
  void run();

 private:
  sf::RenderWindow* window;        // Use pointer for dynamic allocation
  sf::RenderWindow* battleWindow;  // Use pointer for dynamic allocation
  Map* map;                        // Use pointer for dynamic allocation
  PlayerGraphics* player;          // Use pointer for dynamic allocation
  Pokemons* pokemons;              // Use pointer for dynamic allocation
  // Player& player_;

  // Battle* battle;  // Commented out as it's not used

  // Game events
  void handleEvents();
  bool canMove(float x, float y);
  void keyPress(sf::Keyboard::Key key);
  void render();
  void checkInteraction();
};

#endif