#include <SFML/Graphics.hpp>

#include "Map.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player {
 public:
  Player();
  void move(double x, double y);
  //                        y-axis
  void animationHorizontal(double y);
  void animationVertical(double y);
  void draw(sf::RenderWindow& window);

 private:
  sf::Texture player;
  sf::Sprite playerSprite;
};

#endif