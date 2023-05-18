#include "pokemon.h"
#include "player.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
extern vector<vector<string>> pokemonDatabase();
    
int main() {
    vector<vector<string>> database = pokemonDatabase();
    Player player;

    // Create and add Pokemon objects to the player's team
    Pokemon bulbasaur("bulbasaur", database);
    player.addPokemonToTeam(bulbasaur);

    Pokemon charmander("charmander", database);
    player.addPokemonToTeam(charmander);

    Pokemon squirtle("squirtle", database);
    player.addPokemonToTeam(squirtle);

    Pokemon pikachu("pikachu", database);
    player.addPokemonToTeam(pikachu);

    Pokemon jigglypuff("jigglypuff", database);
    player.addPokemonToTeam(jigglypuff);

    // Display the player's team
    player.displayTeam();

    return 0;
}
