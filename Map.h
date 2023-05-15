#include <SFML/Graphics.hpp>
#include <vector>

#ifndef MAP_H
#define MAP_H

const int windowWidth = 800;
const int windowHeight = 450;
const int tileSize = 50;

class Map {
 public:
  Map();
  void draw(sf::RenderWindow& window);

 private:
  std::vector<std::vector<int>> mapLayout;
  sf::Texture grassTexture;
  sf::Texture waterTexture;
  sf::Texture treeTexture;
  sf::Texture bushTexture;
  sf::Texture bridgeTexture;
  sf::Texture bridgeRotatedTexture;
  sf::RectangleShape sprite;
};

#endif