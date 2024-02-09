#include "Game.h"
void battle(Player& player);

Game::Game() {
  // Game window
  window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight),
                                "Pokemon Game");
  battleWindow = nullptr;  // Initialize to nullptr as it will be allocated
                           // dynamically when needed
  map = new Map();
  vector<vector<string>> db = pokemonDatabase();
  player = new PlayerGraphics();
  pokemons = new Pokemons();
  menu = new Menu(0,windowHeight);
  // battle = nullptr;  // Commented out as it's not used
  pokedex = new Pokedex(db, 0, windowHeight);
  pokedexPokemon = new PokedexPokemon(db, 0, windowHeight);
}

Game::~Game() {
  delete window;        // Free dynamically allocated window
  delete battleWindow;  // Free dynamically allocated battleWindow if it's
                        // allocated
  delete map;           // Free dynamically allocated map
  delete player;        // Free dynamically allocated player
  delete pokemons;      // Free dynamically allocated pokemons
  // delete battle;  // Commented out as it's not used
}

void Game::run() {
  while (window->isOpen()) {
    handleEvents();
    render();
  }
}

void Game::handleEvents() {
  sf::Event event;
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window->close();
    } else if (event.type == sf::Event::KeyPressed) {
      keyPress(event.key.code);
    }
  }
}

bool Game::canMove(float x, float y) {
  int i = static_cast<int>(x) / tileSize;
  int j = static_cast<int>(y) / tileSize;

  if (i < 0 || i >= mapWidth || j < 0 || j >= mapHeight) return false;

  return true;
}

// key presses
void Game::keyPress(sf::Keyboard::Key key) {
  // player moving up
  if ((!menu->getDisplay() && !pokedex->getDisplay()) && !pokedexPokemon->getDisplay()){
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        canMove(player->getX(), player->getY() - tileSize))) {
      player->animationVertical(354);
      player->move(0, -0.1);
    }
    // player moving down
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        canMove(player->getX(), player->getY() + tileSize))) {
      player->animationVertical(0);
      player->move(0, 0.1);
    }
    // player moving left
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        canMove(player->getX() - tileSize, player->getY()))) {
      player->animationHorizontal(118);
      player->move(-0.1, 0);
    }
    // player moving right
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        canMove(player->getX() + tileSize, player->getY()))) {
      player->animationHorizontal(236);
      player->move(0.1, 0);
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
    menu->toggleDisplay();
    pokedex->setDisplay(false);
    pokedexPokemon->setDisplay(false);

  }
  if (pokedex->getDisplay() && !menu->getDisplay()){
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        pokedex->moveUp();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        pokedex->moveDown();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
          pokedex->setDisplay(false);
          pokedexPokemon->entry(pokedex->getPage());
          pokedexPokemon->setDisplay(true);
      }
    }
  if ((menu->getDisplay() && !pokedex->getDisplay()) && !pokedexPokemon->getDisplay()){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      menu->moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      menu->moveDown();
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) && (menu->getItemIndex() == 0)){
      menu->toggleDisplay();
      pokedex->setDisplay(true);
    }
  }
  
  if (pokedexPokemon->getDisplay()){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      pokedexPokemon->moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      pokedexPokemon->moveDown();
    }
  }


}

void Game::render() {
  checkInteraction();
  window->clear();
  map->draw(*window);
  pokemons->draw(*window);
  player->draw(*window);
  menu->draw(*window);
  pokedex->draw(*window);
  pokedexPokemon->draw(*window);
  window->display();
}

void Game::checkInteraction() {
  sf::Sprite playerSprite = player->getPlayerSprite();
  //check if player get close to apokemon
  sf::Sprite pokemonSprite1 = pokemons->getSprite1();
  if (playerSprite.getGlobalBounds().intersects(
          pokemonSprite1.getGlobalBounds())) {
    pokemonSprite1.setPosition(16, 9);
    Player player_;
    std::vector<std::vector<std::string>> database = pokemonDatabase();
    assignedAttack pikachu("Pikachu", database);

    // Display the battle message
    std::cout << "A wild Pikachu appeared!\n\n";

    // Get the player's Pokemon team
    std::vector<Pokemon> team = player_.getPokemonTeam();

    // Get the first Pokemon in the team
    Pokemon& selectedPokemon = team[0];

    // Create assignedAttack for selectedPokemon
    assignedAttack assigned(selectedPokemon.getpokemonName(), database);

    // Boolean flag to control the battle loop
    bool battleOver = false;
    // Battle loop
    // Battle loop
    while (!battleOver) {
      // Player's turn
      std::cout << "Player's turn:\n";
      std::cout << "Select an attack:\n";

      // Display the assignedAttack moves
      std::vector<Attack> moves = assigned.getMoves();
      for (int i = 0; i < moves.size(); i++) {
        std::cout << i + 1 << ". " << moves[i].getAttackName() << "\n";
      }
      // Prompt the player to select an attack
      int attackChoice;
      std::cout << "Enter the option number of the attack you want to use: ";
      std::cin >> attackChoice;

      // Validate the input
      if (attackChoice < 1 || attackChoice > moves.size()) {
        std::cout << "Invalid input. Please try again.\n\n";
        continue;
      }

      // Get the selected attack
      Attack& selectedAttack = moves[attackChoice - 1];

      // Perform the attack on Pikachu
      pikachu.takeDamage(selectedAttack.getPower());

      // Display the attack result
      std::cout << selectedPokemon.getpokemonName() << " used "
                << selectedAttack.getAttackName() << "!\n";
      std::cout << "Pikachu's HP: " << pikachu.getCurrentHealth() << "/"
                << pikachu.getHealth() << "\n\n";

      // Check if Pikachu is defeated
      if (pikachu.getCurrentHealth() <= 0) {
        std::cout << "Congratulations! You defeated Pikachu!\n\n";
        battleOver = true;
      }
      if (battleOver == false) {
        // Pikachu's turn
        std::cout << "Pikachu's turn:\n";

        // Select a random attack from Pikachu's moves
        Attack& pikachuAttack = pikachu.getRandomAttack();

        // Perform the attack on the player's Pokemon
        selectedPokemon.takeDamage(pikachuAttack.getPower());

        // Display the attack result
        std::cout << "Pikachu used " << pikachuAttack.getAttackName() << "!\n";
        std::cout << selectedPokemon.getpokemonName()
                  << "'s HP: " << selectedPokemon.getCurrentHealth() << "/"
                  << selectedPokemon.getHealth() << "\n\n";

        // Check if the player's Pokemon is defeated
        if (selectedPokemon.getCurrentHealth() <= 0) {
          std::cout << selectedPokemon.getpokemonName() << " fainted!\n";
          player_.removePokemon(selectedPokemon.getpokemonName());
          battleOver = true;
        }
        // Check if the player has any remaining Pokemon
        if (player_.getPokemonTeam().empty()) {
          std::cout << "All of your Pokemon fainted. You lost the battle!\n\n";
          battleOver = true;
        }
      }
    }
  }

  // sf::Sprite pokemonSprite2 = pokemons->getSprite2();
  // if (playerSprite.getGlobalBounds().intersects(
  //         pokemonSprite2.getGlobalBounds())) {
  //   BattleSFML battle2(pokemonSprite2);
  // }

  // sf::Sprite pokemonSprite3 = pokemons->getSprite3();
  // if (playerSprite.getGlobalBounds().intersects(
  //         pokemonSprite3.getGlobalBounds())) {
  //   BattleSFML battle3(pokemonSprite3);
  // }
}