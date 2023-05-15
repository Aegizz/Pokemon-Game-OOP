#include "Map.h"
#include "Player.h"

#ifndef GAME_H
#define GAME_H

class Game {
 public:
  Game();
  void run();

 private:
  sf::RenderWindow window;
  Map map;
  Player player;

  // game events
  void handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) {
        keyPress(event.key.code);
      }
    }
  }

  void keyPress(sf::Keyboard::Key key) {
    switch (key) {
      case sf::Keyboard::Up:
        player.animationVertical(354);
        player.move(0, -0.1);
        break;

      case sf::Keyboard::Down:
        player.animationVertical(0);
        player.move(0, 0.1);
        break;

      case sf::Keyboard::Left:
        player.animationHorizontal(118);
        player.move(-0.1, 0);
        break;

      case sf::Keyboard::Right:
        player.animationHorizontal(236);
        player.move(0.1, 0);
        break;

      default:
        break;
    }
  }

  // render
  void render() {
    window.clear();
    map.draw(window);
    player.draw(window);
    window.display();
  }
};

#endif