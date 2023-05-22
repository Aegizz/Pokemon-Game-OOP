#ifndef BATTLE_H
#define BATTLE_H

#include "Pokemons.h"

class Battle {
 public:
  void draw(sf::RenderWindow& window);
  Battle(sf::Sprite pokemoneSprite);

 private:
  sf::Sprite pokemonSprite_;
  sf::RenderWindow window;
};

#endif