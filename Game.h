#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "BattleSFML.h"
#include "Map.h"
#include "PlayerGraphics.h"
#include "Pokemons.h"
#include "Menu.h"
#include "Pokedex.h"
#include "PokedexPokemon.h"

#include <string>
#include "Pokemon.h"  // Include pokemon.h before attack.h
#include "attack.h"
#include "assignedAttack.h"



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
  Menu * menu;
  Pokedex * pokedex;
  PokedexPokemon * pokedexPokemon;
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