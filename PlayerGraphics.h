#ifndef PLAYERGRAPHICS_H
#define PLAYERGRAPHICS_H
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Map.h"

class PlayerGraphics {
 public:
  PlayerGraphics();
  void move(double x, double y);
  //                        y-axis
  void animationHorizontal(double y);
  void animationVertical(double y);
  void draw(sf::RenderWindow& window);
  double getX();
  double getY();
  sf::Sprite getPlayerSprite();

 private:
  int x_;
  int y_;
  sf::Texture player;
  sf::Sprite playerSprite;
};

#endif