#include "Battle.h"

Battle::Battle(sf::Sprite pokemoneSprite) {
  pokemonSprite_ = pokemoneSprite;
  window.create(sf::VideoMode(windowWidth, windowHeight), "Battle");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear(sf::Color::White);
    // pokemonSprite_.draw(window);
    window.display();
  }
}

// void Battle::draw(sf::RenderWindow& window) { window.draw(pokemonSprite_); }
