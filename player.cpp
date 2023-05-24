//Implementation for player class
#include "pokemon.h"
#include "player.h"
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>


Player::Player() {
    // Constructor implementation
}

// Adds a Pokemon to the player's team.
// Returns true if the Pokemon was successfully added, false if the team is already full.
bool Player::addPokemon(Pokemon& pokemon) {
    if (pokemonTeam.size() < 6) {
        pokemonTeam.push_back(pokemon);
        return true;
    }
    return false; // Unable to add Pokemon if the team is already full
}

// Removes a Pokemon from the player's team based on its name.
// Returns true if the Pokemon was successfully removed, false if the Pokemon was not found.
bool Player::removePokemon(std::string pokemonName) {
    for (auto it = pokemonTeam.begin(); it != pokemonTeam.end(); ++it) {
        if (it->getpokemonName() == pokemonName) {
            pokemonTeam.erase(it);
            return true;
        }
    }
    return false;
}

// Switches the position of a Pokemon in the team and moves it to the first position.
// Returns true if the Pokemon was successfully switched, false if the Pokemon was not found.
bool Player::switchPokemonToFirst(std::string pokemonName) {
    auto it = std::find_if(pokemonTeam.begin(), pokemonTeam.end(),
                           [pokemonName](Pokemon& pokemon) {
                               return pokemon.getpokemonName() == pokemonName;
                           });

    if (it != pokemonTeam.end()) {
        std::rotate(pokemonTeam.begin(), it, it + 1);
        return true;
    }

    return false;
}

// Retrieves the player's Pokemon team.
std::vector<Pokemon> Player::getPokemonTeam() {
    return pokemonTeam;
}
