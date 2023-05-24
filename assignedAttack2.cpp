#include <iostream>
#include "assignedAttack.h"
#include "player.h"
#include <iostream>
#include <ctime> 

extern vector<vector<string>> pokemonDatabase();
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

    std::vector<Pokemon> team = player.getPokemonTeam();

    Pokemon& selectedPokemon = team[0];

    assignedAttack assign(selectedPokemon.getpokemonName(), database);
    std::vector<Attack> moves = selectedPokemon.getMoves();
    std::cout << "Pikachu's moves:" << std::endl;
    for (const Attack& move : moves) {
        std::cout << "Move Name: " << move.getAttackName() << std::endl;
        std::cout << "Power: " << move.getPower() << std::endl;
        std::cout << "Accuracy: " << move.getAccuracy() << std::endl;
        std::cout << "Remaining PP: " << move.getRemainingPP() << std::endl;
        std::cout << std::endl;
    
}
}