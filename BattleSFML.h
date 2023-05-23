#ifndef BATTLESFML_H
#define BATTLESFML_H

#include "Pokemons.h"

class BattleSFML {
 public:
  BattleSFML(sf::Sprite pokemoneSprite);
  sf::Sprite getBulbasaur();
  sf::Sprite getCharmander();
  sf::Sprite getSquirtle();
  sf::Sprite getPikachu();
  sf::Sprite getJigglypuff();

 private:
  sf::Sprite pokemonSprite_;
  sf::RenderWindow window;
};

#endif