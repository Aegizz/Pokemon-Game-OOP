#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Pokemon.h"

class Player {
private:
    std::vector<Pokemon> pokemonTeam; // Vector to store the player's Pokemon team

public:
    Player();
    bool addPokemon(const Pokemon& pokemon);
    bool removePokemon(const std::string& pokemonName);
    std::vector<Pokemon> getPokemonTeam();
};
#endif;