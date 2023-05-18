#ifndef POKEMONES_H
#define POKEMONES_H

#include <random>

#include "Map.h"

class Pokemons {
 public:
  Pokemons() {
    for (int i = 1; i <= 151; i++) {
      sf::Texture texture;
      if (texture.loadFromFile("pokemonSprites/" + std::to_string(i) +
                               ".png")) {
        sprites.push_back(texture);
      }
    }
  }

  int random1 = 1 + (rand() % 151);
  int random2 = 1 + (rand() % 16);
  int random3 = 1 + (rand() % 9);
  sf::Sprite spawnPokemon1() {
    sf::Sprite pokemon1;

    pokemon1.setTexture(sprites[random1]);

    pokemon1.setPosition(static_cast<float>(random2 * tileSize),
                         static_cast<float>(random3 * tileSize));

    return pokemon1;
  }

  // int random4 = 1 + (rand() % 151);
  // int random5 = 1 + (rand() % 16);
  // int random6 = 1 + (rand() % 9);
  // sf::Sprite spawnPokemon2() {
  //   sf::Sprite pokemon1;

  //   pokemon1.setTexture(sprites[random4]);

  //   pokemon1.setPosition(static_cast<float>(random5 * tileSize),
  //                        static_cast<float>(random6 * tileSize));

  //   return pokemon1;
  // }

  // int random7 = 1 + (rand() % 151);
  // int random8 = 1 + (rand() % 16);
  // int random9 = 1 + (rand() % 9);
  // sf::Sprite spawnPokemon3() {
  //   sf::Sprite pokemon1;

  //   pokemon1.setTexture(sprites[random7]);

  //   pokemon1.setPosition(static_cast<float>(random8 * tileSize),
  //                        static_cast<float>(random9 * tileSize));

  //   return pokemon1;
  // }

  void draw(sf::RenderWindow& window) {
    sf::Sprite sprite1;
    // sf::Sprite sprite2;
    // sf::Sprite sprite3;

    sprite1 = spawnPokemon1();
    // sprite2 = spawnPokemon2();
    // sprite3 = spawnPokemon3();

    window.draw(sprite1);
    //   window.draw(sprite2);
    //   window.draw(sprite3);
  }

 private:
  std::vector<sf::Texture> sprites;
  std::vector<std::pair<int, int>> pokemonPositions;
};

#endif