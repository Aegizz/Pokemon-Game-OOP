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

bool Player::addPokemon(Pokemon& pokemon) {
    if (pokemonTeam.size() < 6) {
        pokemonTeam.push_back(pokemon);
        return true;
    }
    return false; // Unable to add Pokemon if the team is already full
}

bool Player::removePokemon(std::string pokemonName) {
    for (auto it = pokemonTeam.begin(); it != pokemonTeam.end(); ++it) {
        if (it->getpokemonName() == pokemonName) {
            pokemonTeam.erase(it);
            return true;
        }
    }
    return false;
}

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



std::vector<Pokemon> Player::getPokemonTeam() {
    return pokemonTeam;
}

    