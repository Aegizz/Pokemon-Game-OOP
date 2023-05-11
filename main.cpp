#include <SFML/Graphics.hpp>
#include <vector>

const int mapWidth = 16;
const int mapHeight = 9;
const int tileSize = 50;
float windowHeight = mapHeight * tileSize;
float windowWidth = mapWidth * tileSize;

int map[mapHeight][mapWidth] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

bool canMove(float x, float y) {
  int i = static_cast<int>(x) / tileSize;
  int j = static_cast<int>(y) / tileSize;

  // Check if the coordinates are within the map bounds
  if (i < 0 || i >= mapWidth || j < 0 || j >= mapHeight) return false;

  // Check if the tile is a wall
  if (map[i][j] == 1) return false;

  return true;
}

int main() {
  // creating window
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Map");

  sf::Texture texture;
  if (!texture.loadFromFile("Grass1.png")) {
    return 1;
  }
  sf::Sprite sprite(texture);

  sf::Texture player;

  if (!player.loadFromFile("player.png")) {
    return 1;
  }
  sf::Sprite playerSprite(player);

  // game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();

    for (int i = 0; i < mapWidth; i++) {
      for (int j = 0; j < mapHeight; j++) {
        sprite.setPosition(i * tileSize, j * tileSize);
        window.draw(sprite);
      }
    }
    playerSprite.setPosition(((mapWidth * tileSize) - 50) / 2,
                             ((mapHeight * tileSize) - 50) / 2);
    window.draw(playerSprite);
    window.display();
  }
}