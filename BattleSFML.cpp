#include "BattleSFML.h"

BattleSFML::BattleSFML(sf::Sprite pokemonSprite) {
  pokemonSprite_ = pokemonSprite;
  window.create(sf::VideoMode(windowWidth, windowHeight), "Battle");
  pokemonSprite_.setPosition((windowWidth / 2) + 200, (windowHeight / 2) - 200);
  pokemonSprite_.setScale(2, 2);

  sf::Font font;
  font.loadFromFile("bebas/Bebas-Regular.otf");

  initializePokemonSprites();
  initializeTexts(font);

  while (window.isOpen()) {
    handleEvents();
    render();
  }
}

void BattleSFML::initializePokemonSprites() {
  sf::Texture bulbasaurTexture;
  bulbasaurTexture.loadFromFile("pokemonSprites/1.png");
  bulbasaurSprite.setTexture(bulbasaurTexture);
  bulbasaurSprite.setScale(2, 2);
  bulbasaurSprite.setPosition(20, 20);

  sf::Texture charmanderTexture;
  charmanderTexture.loadFromFile("pokemonSprites/4.png");
  charmanderSprite.setTexture(charmanderTexture);
  charmanderSprite.setScale(2, 2);
  charmanderSprite.setPosition(300, 20);

  sf::Texture squirtleTexture;
  squirtleTexture.loadFromFile("pokemonSprites/7.png");
  squirtleSprite.setTexture(squirtleTexture);
  squirtleSprite.setScale(2, 2);
  squirtleSprite.setPosition(600, 20);

  sf::Texture pikachuTexture;
  pikachuTexture.loadFromFile("pokemonSprites/25.png");
  pikachuSprite.setTexture(pikachuTexture);
  pikachuSprite.setScale(2, 2);
  pikachuSprite.setPosition(200, 200);

  sf::Texture jigglypuffTexture;
  jigglypuffTexture.loadFromFile("pokemonSprites/39.png");
  jigglypuffSprite.setTexture(jigglypuffTexture);
  jigglypuffSprite.setScale(2, 2);
  jigglypuffSprite.setPosition(400, 200);
}

void BattleSFML::initializeTexts(sf::Font& font) {
  sf::Text bulbasaur;
  bulbasaur.setFont(font);
  bulbasaur.setCharacterSize(20);
  bulbasaur.setFillColor(sf::Color::Black);
  bulbasaur.setString("1");
  bulbasaur.setPosition(120, 50);

  sf::Text charmander;
  charmander.setFont(font);
  charmander.setCharacterSize(20);
  charmander.setFillColor(sf::Color::Black);
  charmander.setString("2");
  charmander.setPosition(400, 50);

  sf::Text squirtle;
  squirtle.setFont(font);
  squirtle.setCharacterSize(20);
  squirtle.setFillColor(sf::Color::Black);
  squirtle.setString("3");
  squirtle.setPosition(680, 50);

  sf::Text pikachu;
  pikachu.setFont(font);
  pikachu.setCharacterSize(20);
  pikachu.setFillColor(sf::Color::Black);
  pikachu.setString("4");
  pikachu.setPosition(280, 220);

  sf::Text jigglypuff;
  jigglypuff.setFont(font);
  jigglypuff.setCharacterSize(20);
  jigglypuff.setFillColor(sf::Color::Black);
  jigglypuff.setString("5");
  jigglypuff.setPosition(500, 220);
}

void BattleSFML::handleEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();

    } else if (event.type == sf::Event::KeyReleased) {
      switch (event.key.code) {
        case sf::Keyboard::Num1:
          bulbasaurSprite.setPosition(200, 200);
          window.clear(sf::Color::White);
          window.draw(pokemonSprite_);
          window.draw(bulbasaurSprite);
          window.display();
          break;
          // Handle other key events if necessary
      }
    }
  }
}

void BattleSFML::render() {
  window.clear(sf::Color::White);
  window.draw(pokemonSprite_);
  window.draw(bulbasaurSprite);
  window.draw(charmanderSprite);
  window.draw(squirtleSprite);
  window.draw(pikachuSprite);
  window.draw(jigglypuffSprite);
  window.draw(bulbasaur);
  window.draw(charmander);
  window.draw(squirtle);
  window.draw(pikachu);
  window.draw(jigglypuff);
  window.display();
}