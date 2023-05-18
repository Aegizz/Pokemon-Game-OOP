#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

const int windowWidth = 800;
const int windowHeight = 450;
const int mapWidth = 16;
const int mapHeight = 9;
const int tileSize = 50;

class Map {
 public:
  Map();
  void draw(sf::RenderWindow& window);
  int getWidth() const;
  int getHeight() const;
  int getTile(int x, int y) const;
  std::vector<std::vector<int>> getMapLayout();

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