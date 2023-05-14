#include "Map.h"

#ifndef GAME_H
#define GAME_H

class Game {
 public:
  Game();
  void run();

 private:
  sf::RenderWindow window;
  Map map;

  // game events
  void handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
  // render
  void render() {
    window.clear();
    map.draw(window);
    window.display();
  }
};

#endif