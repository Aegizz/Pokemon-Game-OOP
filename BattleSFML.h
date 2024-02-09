#ifndef BATTLESFML_H
#define BATTLESFML_H

#include <SFML/Graphics.hpp>

#include "Pokemons.h"

class BattleSFML {
 public:
  BattleSFML(sf::Sprite pokemonSprite);

  sf::Sprite getBulbasaur();
  sf::Sprite getCharmander();
  sf::Sprite getSquirtle();
  sf::Sprite getPikachu();
  sf::Sprite getJigglypuff();

 private:
  void initializePokemonSprites();
  void initializeTexts(sf::Font& font);
  void handleEvents();
  void render();

  sf::Sprite pokemonSprite_;
  sf::RenderWindow window;
  sf::Sprite bulbasaurSprite;
  sf::Sprite charmanderSprite;
  sf::Sprite squirtleSprite;
  sf::Sprite pikachuSprite;
  sf::Sprite jigglypuffSprite;
  sf::Text bulbasaur;
  sf::Text charmander;
  sf::Text squirtle;
  sf::Text pikachu;
  sf::Text jigglypuff;
};

#endif