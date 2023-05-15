#include "Player.h"

Player::Player() {
  player.loadFromFile("playerSprite.png");
  playerSprite.setTexture(player);
  playerSprite.setTextureRect(sf::IntRect(0, 0, 85.5, 118));
  playerSprite.setScale(0.5f, 0.5f);
}

// moving player around the map
void Player::move(double x, double y) {
  playerSprite.move(static_cast<double>(x * tileSize),
                    static_cast<double>(y * tileSize));
}

// animating player when walking horizonatally
//                                y-axis
void Player::animationHorizontal(double y) {
  int animation = 0;
  animation = (int)playerSprite.getPosition().x / 20 % 4;
  animation = animation * 85.5;
  playerSprite.setTextureRect(sf::IntRect(animation, y, 85.5, 118));
}

// animating player when moving vertically
void Player::animationVertical(double y) {
  int animation = 0;
  animation = (int)playerSprite.getPosition().y / 20 % 4;
  animation = animation * 85.5;
  playerSprite.setTextureRect(sf::IntRect(animation, y, 85.5, 118));
}

// drawing player on the map
void Player::draw(sf::RenderWindow& window) { window.draw(playerSprite); }
