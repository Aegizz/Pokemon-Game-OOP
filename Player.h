#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "pokemon.h"

class Player {
private:
    std::vector<Pokemon> pokemonTeam; // Vector to store the player's Pokemon team

public:
    Player();
    bool addPokemon(Pokemon& pokemon);
    bool removePokemon(std::string pokemonName);
    bool switchPokemonToFirst(std::string pokemonName);
    std::vector<Pokemon> getPokemonTeam();
};
#endif // PLAYER_H