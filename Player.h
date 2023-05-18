#include "pokemon.h"
#include <vector>
#include <string>
#include <iostream>

class Player {
private:
    std::vector<Pokemon> pokemonTeam;

public:
    Player() {}

    void addPokemonToTeam(Pokemon& pokemon) {
        if (pokemonTeam.size() < 6) {
            pokemonTeam.push_back(pokemon);
            std::cout << "Added " << pokemon.getpokemonName() << " to your team." << std::endl;
        } else {
            std::cout << "Your team is full. Unable to add more Pokemon." << std::endl;
        }
    }

    void displayTeam() {
        if (pokemonTeam.empty()) {
            std::cout << "Your team is empty." << std::endl;
        } else {
            std::cout << "Your team: " << std::endl;
            for (Pokemon& pokemon : pokemonTeam) {
                std::cout << "Pokemon Name: " << pokemon.getpokemonName() << std::endl;
                std::cout << "Health: " << pokemon.findVariableData("health") << std::endl;
                std::cout << "Attack: " << pokemon.findVariableData("attack") << std::endl;
                std::cout << "Defense: " << pokemon.findVariableData("defense") << std::endl;
                std::cout << "Type: " << pokemon.findVariableData("type1") << std::endl;
                std::cout << "------------------------" << std::endl;
            }
        }
    }
};