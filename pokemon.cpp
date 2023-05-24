//Implementation for pokemon class
#include "pokemon.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

Pokemon::Pokemon() {
    // Default constructor
}

Pokemon::Pokemon(string _pokemonName, vector<vector<string>> _database) {
    pokemonName = _pokemonName;
    data = _database;
    level = 50;
    
    // Find the row position of the pokemon in the database
    for (int i = 0; i < _database.size(); i++) {
        for (int j = 0; j < _database[1].size(); j++) {
            if (_database[i][j] == pokemonName) {
                row = i;
            }
        }
    }

    currentHealth = getHealth(); // Set current health to the initial health value
}

string Pokemon::getpokemonName() {
    // Get the name of the pokemon
    return pokemonName;
}

vector<vector<string>> Pokemon::getData() {
    // Get the data of the pokemon
    return data;
}

int Pokemon::getRowPos(vector<vector<string>> database) {
    // Get the row position of the pokemon in the database
    for (int i = 0; i < database.size(); i++) {
        for (int j = 0; j < database[1].size(); j++) {
            if (database[i][j] == pokemonName) {
                row = i;
            }
        }
    }
    return row;
}

int Pokemon::getRow() {
    // Get the current row position of the pokemon
    return row;
}

string Pokemon::findVariableData(string input) {
    // Find the variable data of the pokemon based on the input variable name
    for (int j = 0; j < data[1].size(); j++) {
        if (data[0][j] == input) {
            return data[row][j];
        }
    }
    return "Error";
}

int Pokemon::getLevel() {
    // Get the level of the pokemon
    return level;
}

void Pokemon::setLevel(int _level) {
    // Set the level of the pokemon
    level = _level;
}

void Pokemon::setHealth(int _health) {
    // Set the health of the pokemon
    health = _health;
}

int Pokemon::getHealth() {
    // Get the maximum health of the pokemon
    return stoi(findVariableData("HP"));
}

void Pokemon::setType(string _type) {
    // Set the type of the pokemon
    type = _type;
}

string Pokemon::getType() {
    // Get the type of the pokemon
    return findVariableData("Type1");
}

void Pokemon::takeDamage(int damage) {
    // Reduce the current health of the pokemon by the damage amount
    int currentHealth = getCurrentHealth();
    int newHP = currentHealth - damage;
    if (newHP < 0) {
        newHP = 0;
    }
    setCurrentHealth(newHP);
}

int Pokemon::getCurrentHealth() {
    // Get the current health of the pokemon
    return currentHealth;
}

void Pokemon::setCurrentHealth(int _currentHealth) {
    // Set the current health of the pokemon
    currentHealth = _currentHealth;
}
