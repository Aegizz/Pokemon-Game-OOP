#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"

using namespace std;

vector<vector<string>> pokemonDatabase() {
    // Implementation of the function
    vector<vector<string>> database;
    string pokeSlot1;
    pokeSlot1 = "bulbasaur";
    Pokemon Pokemon1 = Pokemon(pokeSlot1, database);
    std::string hpString1 = Pokemon1.findVariableData("hp");
    std::string attackString1 = Pokemon1.findVariableData("attack");
    std::string defenseString1 = Pokemon1.findVariableData("defense");

    int pokemonHP = std::stoi(hpString1);
    int pokemonAttack = std::stoi(attackString1);
    int pokemonDefense = std::stoi(defenseString1);

    string pokeSlot2;
    pokeSlot2 = "charmander";
    Pokemon Pokemon2 = Pokemon(pokeSlot2, database);
    std::string hpString2 = Pokemon1.findVariableData("hp");
    std::string attackString2 = Pokemon1.findVariableData("attack");
    std::string defenseString2 = Pokemon1.findVariableData("defense");

    int pokemonHP = std::stoi(hpString2);
    int pokemonAttack = std::stoi(attackString2);
    int pokemonDefense = std::stoi(defenseString2);







    
}

int main() {
    vector<vector<string>> database = pokemonDatabase();
    

    // Rest of the main function
    // ...
}
