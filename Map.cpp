#include "Map.h"

Map::Map() {
  // making the map layout
  mapLayout = {{0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2},
               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1},
               {1, 1, 1, -2, 1, 1, 1, 1, 1, 1, -2, 1, 1, 0, 0, 0},
               {0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
               {0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0},
               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0},
               {-1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0},
               {-1, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 1, 0, 0, 0},
               {0, 2, 2, 0, 0, 0, 0, 0, 0, -1, -1, 0, 1, 0, 0, 0}};

  // reading sprites
  grassTexture.loadFromFile("Grass1.png");
  waterTexture.loadFromFile("water.png");
  treeTexture.loadFromFile("tree.png");
  bushTexture.loadFromFile("bush.png");
  bridgeTexture.loadFromFile("bridge.png");
  bridgeRotatedTexture.loadFromFile("bridgeRotated.png");

  sprite.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
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

      sprite.setPosition(static_cast<float>(j * TILE_SIZE),
                         static_cast<float>(i * TILE_SIZE));
      window.draw(sprite);
    }
  }
}
