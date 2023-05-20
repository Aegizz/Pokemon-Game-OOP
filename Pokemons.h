#ifndef POKEMONES_H
#define POKEMONES_H

#include <random>

#include "Map.h"

class Pokemons {
 public:
  Pokemons();
  sf::Sprite spawnPokemon1();
  sf::Sprite spawnPokemon2();
  sf::Sprite spawnPokemon3();
  void draw(sf::RenderWindow& window);

 private:
  std::vector<sf::Texture> sprites;
  int random1 = 1 + (rand() % 151);
  int random2 = 1 + (rand() % (windowWidth / tileSize - 2));
  int random3 = 1 + (rand() % (windowHeight / tileSize - 2));
  int random4 = 1 + (rand() % 151);
  int random5 = 1 + (rand() % (windowWidth / tileSize - 2));
  int random6 = 1 + (rand() % (windowHeight / tileSize - 2));
  int random7 = 1 + (rand() % 151);
  int random8 = 2 + (rand() % (windowWidth / tileSize - 2));
  int random9 = 2 + (rand() % (windowHeight / tileSize - 2));
  sf::Sprite sprite1;
  sf::Sprite sprite2;
  sf::Sprite sprite3;
  sf::Sprite pokemon1;
  sf::Sprite pokemon2;
  sf::Sprite pokemon3;
};

#endif