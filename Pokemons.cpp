#include "Pokemons.h"

Pokemons::Pokemons() {
  for (int i = 1; i <= 151; i++) {
    sf::Texture texture;
    if (texture.loadFromFile("pokemonSprites/" + std::to_string(i) + ".png")) {
      sprites.push_back(texture);
    }
  }
}

sf::Sprite Pokemons::spawnPokemon1() {
  pokemon1.setTexture(sprites[24]);

  pokemon1.setPosition(static_cast<float>(8 * tileSize),
                       static_cast<float>(5 * tileSize));

  return pokemon1;
}

sf::Sprite Pokemons::spawnPokemon2() {
  pokemon2.setTexture(sprites[random4]);

  pokemon2.setPosition(static_cast<float>(random5 * tileSize),
                       static_cast<float>(random6 * tileSize));

  return pokemon2;
}

sf::Sprite Pokemons::spawnPokemon3() {
  pokemon3.setTexture(sprites[random7]);

  pokemon3.setPosition(static_cast<float>(random8 * tileSize),
                       static_cast<float>(random9 * tileSize));

  return pokemon3;
}

void Pokemons::draw(sf::RenderWindow& window) {
  sprite1 = spawnPokemon1();
  sprite2 = spawnPokemon2();
  sprite3 = spawnPokemon3();

  window.draw(sprite1);
  // window.draw(sprite2);
  // window.draw(sprite3);
}

sf::Sprite Pokemons::getSprite1() { return sprite1; }
sf::Sprite Pokemons::getSprite2() { return sprite2; }
sf::Sprite Pokemons::getSprite3() { return sprite3; }