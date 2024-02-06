#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Map.h"

class Player {
 public:
  Player();
  void move(double x, double y);
  //                        y-axis
  void animationHorizontal(double y);
  void animationVertical(double y);
  void draw(sf::RenderWindow& window);
  double getX();
  double getY();

 private:
  int x_;
  int y_;
  sf::Texture player;
  sf::Sprite playerSprite;
};

#endif