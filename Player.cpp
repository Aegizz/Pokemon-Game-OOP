#include "pokemon.h"
#include "player.h"
#include <vector>
#include <string>
#include <iostream>
extern std::vector<std::vector<std::string>> pokemonDatabase();


Player::Player() {
    // Constructor implementation
}

bool Player::addPokemon(const Pokemon& pokemon) {
    if (pokemonTeam.size() < 6) {
        pokemonTeam.push_back(pokemon);
        return true;
    }
    return false; // Unable to add Pokemon if the team is already full
}

bool Player::removePokemon(const std::string& pokemonName) {
    for (auto it = pokemonTeam.begin(); it != pokemonTeam.end(); ++it) {
        if (it->getpokemonName() == pokemonName) {
            pokemonTeam.erase(it);
            return true;
        }
    }
    return false; // Unable to find and remove the specified Pokemon
}

std::vector<Pokemon> Player::getPokemonTeam() {
    return pokemonTeam;
}

    