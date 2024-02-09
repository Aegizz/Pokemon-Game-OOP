#include <cassert>
#include <iostream>

#include "Game.cpp"
#include "Map.cpp"
#include "PlayerGraphics.cpp"
#include "Pokemons.cpp"

void testMap() {
  Map map;

  // Test getWidth() and getHeight()
  assert(map.getWidth() == 16);
  assert(map.getHeight() == 9);

  // Test getTile()
  assert(map.getTile(0, 0) == 0);
  assert(map.getTile(4, 2) == 2);
  assert(map.getTile(15, 8) == 0);

  // Test getMapLayout()
  std::vector<std::vector<int>> map_layout = map.getMapLayout();
  assert(map_layout.size() == 9);
  assert(map_layout[0].size() == 16);
  assert(map_layout[4][11] == 2);
  assert(map_layout[8][8] == 0);
}

void testPlayer() {
  PlayerGraphics player;

  // Test getX() and getY()
  assert(player.getX() == 0.0);
  assert(player.getY() == 0.0);

  // Test move()
  player.move(1.0, 2.0);
  assert(player.getX() == 50.0);
  assert(player.getY() == 100.0);

  // Test animationHorizontal() and animationVertical()
  player.animationHorizontal(118);
  player.animationVertical(0);

  // Test getPlayerSprite()
  sf::Sprite sprite = player.getPlayerSprite();
}

void testPokemons() {
  Pokemons pokemons;

  // Test getSprite1(), getSprite2(), and getSprite3()
  sf::Sprite sprite1 = pokemons.getSprite1();
  sf::Sprite sprite2 = pokemons.getSprite2();
  sf::Sprite sprite3 = pokemons.getSprite3();

  // Test spawnPokemon1(), spawnPokemon2(), and spawnPokemon3()
  sf::Sprite spawnedSprite1 = pokemons.spawnPokemon1();
  sf::Sprite spawnedSprite2 = pokemons.spawnPokemon2();
  sf::Sprite spawnedSprite3 = pokemons.spawnPokemon3();
}

void testGame() {
  // Test the Game class by running it and checking for any assertion failure or
  // errors.
  Game game;
  game.run();
}

int main() {
  testMap();
  testPlayer();
  testPokemons();
  testGame();

  std::cout << "All tests passed!" << std::endl;

  return 0;
}