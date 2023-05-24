//Passed Test - Tested for retrieving the Pokemon database, creating a Pikachu and Mewtwo object, and printing their name, health, and type
#include "pokemon.h"
#include <iostream>

extern vector<vector<string>> pokemonDatabase(); // Declaration of external function to retrieve the Pokemon database

int main() {
    vector<vector<string>> database = pokemonDatabase(); // Retrieve the Pokemon database

    Pokemon pikachu("Pikachu", database); // Create a Pikachu object using the Pokemon constructor
    Pokemon mewtwo("Mewtwo", database);   // Create a Mewtwo object using the Pokemon constructor

    // Print Pikachu's name, health, and type
    std::cout << "Pikachu Name: " << pikachu.getpokemonName() << std::endl;
    std::cout << "Pikachu Health: " << pikachu.getHealth() << std::endl;
    std::cout << "Pikachu Type: " << pikachu.getType() << std::endl;

    // Print Mewtwo's name, health, and type
    std::cout << "Mewtwo Name: " << mewtwo.getpokemonName() << std::endl;
    std::cout << "Mewtwo Health: " << mewtwo.getHealth() << std::endl;
    std::cout << "Mewtwo Type: " << mewtwo.getType() << std::endl;

    // Print Pikachu's current health
    std::cout << "Pikachu Health: " << pikachu.getCurrentHealth() << std::endl;

    int damage = 3;
    pikachu.takeDamage(damage); // Pikachu takes damage
    std::cout << "Pikachu Health: " << pikachu.getCurrentHealth() << std::endl;

    pikachu.takeDamage(damage); // Pikachu takes damage again
    std::cout << "Pikachu Health: " << pikachu.getCurrentHealth() << std::endl;

    return 0;
}
