#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"

using namespace std;

vector<vector<string>> pokemonDatabase() {
    // Implementation of the function
    vector<vector<string>> database;

    // Populate the database with Pokemon data
    vector<string> pokemon1 = {"Pikachu", "Electric", "55", "40"};
    vector<string> pokemon2 = {"Charmander", "Fire", "39", "52"};
    // Add more Pokemon data as needed

    database.push_back(pokemon1);
    database.push_back(pokemon2);
    // Add more Pokemon data to the database vector as needed

    return database;
}

int main() {
    vector<vector<string>> database = pokemonDatabase();

    // Rest of the main function
    // ...
}
