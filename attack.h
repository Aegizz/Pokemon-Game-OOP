#ifndef ATTACK_H
#define ATTACK_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"
using namespace std;

class Attack : public Pokemon {
   protected:
    int attack;
    int accuracy;
    string attackName;
    int PP;
   
   public:
    Attack();
    Attack(int attack, int accuracy, string attackName, int PP);
    int getAttack();
    int getAccuracy();
    int getPP();
    string getAttackName();
};




/*
vector<vector<string>> pokemonMovesDatabase(){
    vector<vector<string>> database;

};

vector<vector<string>> pokemonDatabase() {
    // Implementation of the function
    vector<vector<string>> database;

    string pokeSlot1;
    pokeSlot1 = "bulbasaur";
    Pokemon Pokemon1 = Pokemon(pokeSlot1, database);
    std::string healthString1 = Pokemon1.findVariableData("health");
    std::string attackString1 = Pokemon1.findVariableData("attack");
    std::string defenseString1 = Pokemon1.findVariableData("defense");
    std::string pokeTypeString1 = Pokemon1.findVariableData("type1");

    int pokemonhealth = std::stoi(healthString1);
    int pokemonAttack = std::stoi(attackString1);
    int pokemonDefense = std::stoi(defenseString1);
    int pokeType = std::stoi(pokeTypeString1);

    string pokeSlot2;
    pokeSlot2 = "charmander";
    Pokemon Pokemon2 = Pokemon(pokeSlot2, database);
    std::string healthString2 = Pokemon1.findVariableData("health");
    std::string attackString2 = Pokemon1.findVariableData("attack");
    std::string defenseString2 = Pokemon1.findVariableData("defense");
    std::string pokeTypeString2 = Pokemon1.findVariableData("type1");    

    int pokemonhealth = std::stoi(healthString2);
    int pokemonAttack = std::stoi(attackString2);
    int pokemonDefense = std::stoi(defenseString2);
    int pokeType = std::stoi(pokeTypeString2);    
}

int main() {
    vector<vector<string>> database = pokemonDatabase();
    

    // Rest of the main function
    // ...
}
*/
#endif
