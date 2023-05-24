//Passed Test - Tested for creating a player, adding Pokemon to the player's team, removing Pokemon from the player's team, and switching a Pokemon to be the first member of the team
#include "pokemon.h"
#include "player.h"
#include <vector>
#include <string>
#include <iostream>
extern std::vector<std::vector<std::string>> pokemonDatabase();

int main() {
    std::vector<std::vector<std::string>> database = pokemonDatabase();
    Player player;

    // Create some Pokemon
    Pokemon pikachu("Pikachu", database);
    Pokemon charmander("Charmander", database);
    Pokemon mewtwo("Mewtwo", database);

    // Add Pokemon to the player's team
    player.addPokemon(pikachu);
    player.addPokemon(charmander);
    player.addPokemon(mewtwo);

    // Get the player's Pokemon team
    std::vector<Pokemon> team = player.getPokemonTeam();

    // Display the player's Pokemon team
    for (Pokemon& pokemon : team) {
        std::cout << "Name: " << pokemon.getpokemonName() << std::endl;
        std::cout << "Type: " << pokemon.getType() << std::endl;
        std::cout << std::endl;
    }

    // Remove Mewtwo
    player.removePokemon("Mewtwo");

    // Get the updated player's Pokemon team
    team = player.getPokemonTeam();

    // Display the updated player's Pokemon team
    for (Pokemon& pokemon : team) {
        std::cout << "Name: " << pokemon.getpokemonName() << std::endl;
        std::cout << "Type: " << pokemon.getType() << std::endl;
        std::cout << std::endl;
    }

    // Switch a Pokemon to be the first member
    player.switchPokemonToFirst("Charmander");

    // Get the updated player's Pokemon team
    team = player.getPokemonTeam();

    // Display the updated player's Pokemon team
    for (Pokemon& pokemon : team) {
        std::cout << "Name: " << pokemon.getpokemonName() << std::endl;
        std::cout << "Type: " << pokemon.getType() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
