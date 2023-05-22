#include "pokemon.h"
#include "attack.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

extern vector<vector<string>> pokemonDatabase();
extern vector<vector<string>> pokemonDatabaseMoves();

Pokemon::Pokemon(){

};

Pokemon::Pokemon(string _pokemonName, vector<vector<string>> _database){
    pokemonName = _pokemonName;
    data = _database;
    level = 50;
    for (int i = 0; i < _database.size(); i++){
        for (int j = 0; j < _database[1].size(); j++){
            if (_database[i][j] == pokemonName){
                row  = i;
            }
        }
    }
    sprite = "pokemon/"+data[row][0]+".png";

};

string Pokemon::getpokemonName(){
    return pokemonName;
};
vector<vector<string>> Pokemon::getData(){
    return data;
};

int Pokemon::getRowPos(vector<vector<string>> database){
    for (int i = 0; i < database.size(); i++){
        for (int j = 0; j < database[1].size(); j++){
            if (database[i][j] == pokemonName){
                row  = i;
            }
        }
    }
    return row;
}
int Pokemon::getRow(){
    return row;
}

string Pokemon::findVariableData(string input){
    for (int j = 0; j < data[1].size(); j++){
        if (data[0][j] == input){
                return data[row][j];

            }
        }
    return "Error";
}   
int Pokemon::getLevel(){
    return level;
}
void Pokemon::setLevel(int _level){
    level = _level;
}
string Pokemon::getSprite(){
    return sprite;
}

int Pokemon::getHealth() {
    return health;
}

void Pokemon::setHealth(){
    health = stoi(findVariableData("HP"));
}

string Pokemon::getType(){
    return type;
}

void Pokemon::setType(){
    type = stoi(findVariableData("Type1"));
}


std::vector<Attack> Pokemon::getAttacks() {
    std::vector<Attack> resultAttacks;
    
    // Get the type of the Pokemon
    std::string pokemonType = getType();
    
    // Allocate moves based on the Pokemon's type
    if (pokemonType == "fire") {
        resultAttacks = {
            Attack("Ember", 40, 100, 20),
            Attack("Fire Blast", 110, 85, 20),
            Attack("Flamethrower", 90, 100, 20),
            Attack("Fire Spin", 35, 85, 20)
        };
    } else if (pokemonType == "water") {
        resultAttacks = {
            Attack("Water Gun", 40, 100, 20),
            Attack("Hydro Pump", 110, 85, 20),
            Attack("Surf", 90, 100, 20),
            Attack("Bubble Beam", 35, 85, 20)
        };
    } else if (pokemonType == "grass") {
        resultAttacks = {
            Attack("Vine Whip", 45, 100, 20),
            Attack("Solar Beam", 120, 85, 20),
            Attack("Razor Leaf", 55, 95, 20),
            Attack("Seed Bomb", 80, 100, 20)
        };
    } else if (pokemonType == "electric") {
        resultAttacks = {
            Attack("Thunder Shock", 40, 100, 20),
            Attack("Thunderbolt", 90, 100, 20),
            Attack("Thunder", 110, 70, 20),
            Attack("Zap Cannon", 120, 50, 20)
        };
    } else {
        // Default moves for other types
        resultAttacks = {
            Attack("Tackle", 40, 100, 20),
            Attack("Scratch", 40, 100, 20),
            Attack("Bite", 60, 100, 20),
            Attack("Growl", 0, 100, 20)
        };
    }
    
    return resultAttacks;
}

void Pokemon::setAttacks(const vector<string>& attackList) {
    if (attackList.size() == 4) {
        attacks = attackList;
    } else {
        // Handle error or provide default attacks
        attacks = { "Tackle", "Scratch", "Bite", "Growl" };
    }
}