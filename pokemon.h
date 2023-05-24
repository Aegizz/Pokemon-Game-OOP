//Pokemon Class

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "attack.h"
using namespace std;

class Pokemon {
    protected:
        string pokemonName;             // Name of the Pokemon
        int row;                        // Row position of the Pokemon in the database
        int health;                     // Maximum health of the Pokemon
        int currentHealth;              // Current health of the Pokemon
        vector<vector<string>> data;    // Data of the Pokemon
        int level;                      // Level of the Pokemon
        string type;                    // Type of the Pokemon

    public:
        // Default constructor
        Pokemon();

        // Constructor with parameters
        Pokemon(string pokemonName, vector<vector<string>> database);

        // Get the name of the Pokemon
        string getpokemonName();

        // Get the data of the Pokemon
        vector<vector<string>> getData();

        // Get the row position of the Pokemon in the database
        int getRowPos(vector<vector<string>> database);

        // Get the row position of the Pokemon
        int getRow();

        // Find the value of a variable for the Pokemon
        string findVariableData(string input);

        // Set the maximum health of the Pokemon
        void setHealth(int _health);

        // Get the maximum health of the Pokemon
        int getHealth();

        // Set the level of the Pokemon
        void setLevel(int level);

        // Get the level of the Pokemon
        int getLevel();

        // Get the type of the Pokemon
        string getType();

        // Set the type of the Pokemon
        void setType(string _type);

        // Take damage and update the current health of the Pokemon
        void takeDamage(int damage);

        // Set the current health of the Pokemon
        void setCurrentHealth(int _currentHealth);

        // Get the current health of the Pokemon
        int getCurrentHealth();

};

#endif
