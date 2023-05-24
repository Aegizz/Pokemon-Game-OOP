#include "pokemon.h"
#include <iostream>
extern vector<vector<string>> pokemonDatabase();

int main() {
    vector<vector<string>> database = pokemonDatabase();

    Pokemon pikachu("Pikachu", database);
    Pokemon mewtwo("Mewtwo", database);

    std::cout << "Pikachu Name: " << pikachu.getpokemonName() << std::endl;
    std::cout << "Pikachu Health: " << pikachu.getHealth() << std::endl;
    std::cout << "Pikachu Type: " << pikachu.getType() << std::endl;

    std::cout << "Mewtwo Name: " << mewtwo.getpokemonName() << std::endl;
    std::cout << "Mewtwo Health: " << mewtwo.getHealth() << std::endl;
    std::cout << "Mewtwo Type: " << mewtwo.getType() << std::endl;

    int damage = 3;
    pikachu.takeDamage(damage);
    std::cout << "Pikachu Health: " << pikachu.getCurrentHealth() << std::endl;

    return 0;
}