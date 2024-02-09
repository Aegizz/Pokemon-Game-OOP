#include <SFML/Graphics.hpp>

#include "Game.cpp"
#include "Map.cpp"
#include "PlayerGraphics.cpp"
#include "Pokemons.cpp"
#include "pokemonDatabase.cpp"
#include "Menu.cpp"
#include "Pokedex.cpp"
#include "PokedexPokemon.cpp"
#include "player.h"
#include "Pokemon.h"
#include "attack.h"
int main() {
  Game game;
  game.run(); //running game
  return 0;
}
