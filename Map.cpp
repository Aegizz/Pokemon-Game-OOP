#include "Map.h"

Map::Map() {
  // making the map layout
  mapLayout = {{0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2},
               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1},
               {0, 0, 0, 0, 2, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
               {0, 0, -1, 0, 2, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, -1, 0},
               {0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, -1, 0},
               {-1, -1, 0, 0, -1, 0, 0, 2, 0, 0, -1, 0, 2, 0, 2, 0},
               {-1, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0},
               {0, 2, 2, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0}};

  // reading sprites
  grassTexture.loadFromFile("pokemonSprites/Grass1.png");
  waterTexture.loadFromFile("pokemonSprites/water.png");
  treeTexture.loadFromFile("pokemonSprites/tree.png");
  bushTexture.loadFromFile("pokemonSprites/bush.png");
  bridgeTexture.loadFromFile("pokemonSprites/bridge.png");
  bridgeRotatedTexture.loadFromFile("pokemonSprites/bridgeRotated.png");

  sprite.setSize(sf::Vector2f(tileSize, tileSize));
  sprite.setTexture(&grassTexture);
}

// drawing the map
void Map::draw(sf::RenderWindow& window) {
  for (int i = 0; i < mapLayout.size(); i++) {
    for (int j = 0; j < mapLayout[i].size(); j++) {
      int tile = mapLayout[i][j];

      if (tile == 0) {
        sprite.setTexture(&grassTexture);
      } else if (tile == 1) {
        sprite.setTexture(&waterTexture);
      } else if (tile == 2) {
        sprite.setTexture(&treeTexture);
      } else if (tile == -1) {
        sprite.setTexture(&bushTexture);
      } else if (tile == -2) {
        sprite.setTexture(&bridgeTexture);
      } else if (tile == -3) {
        sprite.setTexture(&bridgeRotatedTexture);
      }

      sprite.setPosition(static_cast<float>(j * tileSize),
                         static_cast<float>(i * tileSize));
      window.draw(sprite);
    }
  }
}

int Map::getWidth() const { return mapLayout[0].size(); }
int Map::getHeight() const { return mapLayout.size(); }
int Map::getTile(int x, int y) const { return mapLayout[y][x]; }

std::vector<std::vector<int>> Map::getMapLayout() { return mapLayout; }