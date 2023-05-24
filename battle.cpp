#include "assignedAttack.h"
#include "player.h"
#include <iostream>
#include <vector>

extern std::vector<std::vector<std::string>> pokemonDatabase();

// Function to simulate a battle between the player and Pikachu
void battle(Player& player) {
    // Create assignedAttack for Pikachu
    std::vector<std::vector<std::string>> database = pokemonDatabase();
    assignedAttack pikachu("Pikachu", database);

    // Display the battle message
    std::cout << "A wild Pikachu appeared!\n\n";

    // Get the player's Pokemon team
    std::vector<Pokemon> team = player.getPokemonTeam();

    // Get the first Pokemon in the team
    Pokemon& selectedPokemon = team[0];

    // Create assignedAttack for selectedPokemon
    assignedAttack assigned(selectedPokemon.getpokemonName(), database);

    // Battle loop
    while (true) {
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
        std::cout << selectedPokemon.getpokemonName() << " used " << selectedAttack.getAttackName() << "!\n";
        std::cout << "Pikachu's HP: " << pikachu.getCurrentHealth() << "/" << pikachu.getHealth() << "\n\n";

        // Check if Pikachu is defeated
        if (pikachu.getHealth() <= 0) {
            std::cout << "Congratulations! You defeated Pikachu!\n\n";
            break;
        }

        // Pikachu's turn
        std::cout << "Pikachu's turn:\n";

        // Select a random attack from Pikachu's moves
        Attack& pikachuAttack = pikachu.getRandomAttack();

        // Perform the attack on the player's Pokemon
        selectedPokemon.takeDamage(pikachuAttack.getPower());

        // Display the attack result
        std::cout << "Pikachu used " << pikachuAttack.getAttackName() << "!\n";
        std::cout << selectedPokemon.getpokemonName() << "'s HP: " << selectedPokemon.getCurrentHealth() << "/"
                  << selectedPokemon.getHealth() << "\n\n";

        // Check if the player's Pokemon is defeated
        if (selectedPokemon.getHealth() <= 0) {
            std::cout << selectedPokemon.getpokemonName() << " fainted!\n";
            player.removePokemon(selectedPokemon.getpokemonName());
            break;
        }

        // Check if the player has any remaining Pokemon
        if (player.getPokemonTeam().empty()) {
            std::cout << "All of your Pokemon fainted. You lost the battle!\n\n";
            break;
        }
    }
}

int main() {
    // Create a player
    Player player;

    // Add some Pokemon to the player's team
    std::vector<std::vector<std::string>> database = pokemonDatabase();
    assignedAttack charmander("Charmander", database);
    assignedAttack squirtle("Squirtle", database);
    player.addPokemon(charmander);
    player.addPokemon(squirtle);

    // Start the battle
    battle(player);

    return 0;
}
