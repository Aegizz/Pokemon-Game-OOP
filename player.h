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
    bool addPokemon(Pokemon& pokemon);  // Function to add a Pokemon to the player's team
    bool removePokemon(std::string pokemonName);    //Function to remove a Pokemon from the player's team
    bool switchPokemonToFirst(std::string pokemonName); //Function to switch a Pokemon to the first position in the player's team
    std::vector<Pokemon> getPokemonTeam();  //storage vector for the player's Pokemon team
};
#endif // PLAYER_H