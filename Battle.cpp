#include "Battle.h"

Battle::Battle(sf::Sprite pokemonSprite) {
  pokemonSprite_ = pokemonSprite;
  window.create(sf::VideoMode(windowWidth, windowHeight), "Battle");
  pokemonSprite_.setPosition((windowWidth / 2) + 200, (windowHeight / 2) - 200);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear(sf::Color::White);
    window.draw(pokemonSprite_);
    window.display();
  }
}
