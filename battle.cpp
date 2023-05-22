#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "pokemon.h"
#include "Player.h"
#include "attack.h"

extern vector<vector<string>> pokemonDatabase();

// Function to simulate a battle between two Pokémon
void battle(Pokemon& playerPokemon, Pokemon& opponentPokemon) {
    std::cout << "A wild " << opponentPokemon.getpokemonName() << " appeared!\n";
    std::cout << "Go, " << playerPokemon.getpokemonName() << "!\n\n";

    // Game loop
    while (true) {
        // Player's turn
        std::cout << "Your turn:\n";
        std::vector<Attack> playerAttacks = playerPokemon.getAttacks();
        std::cout << "Choose an attack:\n";
        for (int i = 0; i < playerAttacks.size(); ++i) {
            std::cout << i + 1 << ". " << playerAttacks[i].getAttackName() << "\n";
        }
        int attackChoice;
        std::cin >> attackChoice;

        // Validate the attack choice
        if (attackChoice < 1 || attackChoice > playerAttacks.size()) {
            std::cout << "Invalid attack choice. Try again.\n";
            continue;
        }

        Attack& selectedAttack = playerAttacks[attackChoice - 1];
        selectedAttack.useAttack(opponentPokemon);
        std::cout << playerPokemon.getpokemonName() << " used " << selectedAttack.getAttackName() << "!\n";

        // Check if the opponent's Pokémon fainted
        if (opponentPokemon.getHealth() <= 0) {
            std::cout << "You defeated the wild " << opponentPokemon.getpokemonName() << "!\n";
            break;
        }

        // Opponent's turn
        std::cout << "\nOpponent's turn:\n";
        std::vector<Attack> opponentAttacks = opponentPokemon.getAttacks();
        srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
        int opponentAttackChoice = rand() % opponentAttacks.size();
        Attack& opponentAttack = opponentAttacks[opponentAttackChoice];
        opponentAttack.useAttack(playerPokemon);
        std::cout << "The wild " << opponentPokemon.getpokemonName() << " used " << opponentAttack.getAttackName() << "!\n";

        // Check if the player's Pokémon fainted
        if (playerPokemon.getHealth() <= 0) {
            std::cout << "Your " << playerPokemon.getpokemonName() << " fainted!\n";
            break;
        }

        std::cout << std::endl;
    }

    std::cout << "Battle ended.\n";
}

int main() {
    vector<vector<string>> database = pokemonDatabase();

    Player player;

    Pokemon bulbasaur("bulbasaur", database);
    player.addPokemon(bulbasaur);

    Pokemon charmander("charmander", database);
    player.addPokemon(charmander);

    Pokemon squirtle("squirtle", database);
    player.addPokemon(squirtle);

    Pokemon pikachu("pikachu", database);
    player.addPokemon(pikachu);

    Pokemon jigglypuff("jigglypuff", database);
    player.addPokemon(jigglypuff);

    std::vector<Pokemon> playerTeam = player.getPokemonTeam();

    if (playerTeam.size() < 1) {
        std::cout << "You don't have any Pokémon in your team.\n";
        return 0;
    }

    // Start the battle with the first Pokémon in the player's team
    Pokemon& playerPokemon = playerTeam[0];

    // Create the opponent's Pokémon
    Pokemon opponentPokemon("charmander", database);

    // Start the battle
    battle(playerPokemon, opponentPokemon);

    return 0;
}